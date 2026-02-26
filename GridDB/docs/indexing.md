# GridDB Indexing System

## Overview

The GridDB Indexing System provides fast key-based lookups by mapping indexed column values to physical row offsets inside the database file. It is designed to reduce full table scans and improve query performance, especially for SELECT queries with WHERE conditions.

The indexing layer is tightly integrated with the storage engine and query engine, allowing direct offset access to rows stored in binary format.

Core goals:
- Fast lookups
- Minimal disk overhead
- Deterministic structure
- Simple persistence model
- Efficient integration with the storage format

## Indexing Strategy

GridDB uses a primary key-style indexing approach in its initial implementation. Each index maps a key value to a row offset inside the `.db` file.

Conceptual model:

```bash
Key → File Offset → Row Data
```

This design enables O(log n) or O(1) lookups depending on the in-memory structure used by the index manager.

## Supported Index Types

Initial version:
- Single-column index
- Unique key index
- Hash-based in-memory index with persistent backing file

Planned future support:
- Multi-column indexes
- B+ Tree indexes
- Secondary indexes
- Range indexes

## Index File (.idx)

Indexes are stored in a dedicated binary file separate from the main database file.

Example:

```bash
data/griddb.idx
```

This separation allows independent loading, updating, and rebuilding of indexes without modifying the main data file structure.

## Global Index File Layout

The index file follows a deterministic binary layout:

```bash
[ Header ]
[ Index Metadata ]
[ Index Entries ]
```

## Header Structure

The header identifies the file and stores global index metadata.

Binary layout:

```bash
[ Magic Number (8 bytes) ]
[ Version (4 bytes) ]
[ Index Count (4 bytes) ]
[ Reserved (16 bytes) ]
```

Field description:
- Magic Number: Identifies the file as a GridDB index file
- Version: Index format version
- Index Count: Number of indexes stored
- Reserved: Space for future extensions

Example magic value:

```bash
"GRIDIDX1"
```

## Index Metadata Section

Each index stored in the file has its own metadata entry.

Layout per index:

```bash
[ Table Name Length (4 bytes) ]
[ Table Name (N bytes) ]
[ Column Name Length (4 bytes) ]
[ Column Name (N bytes) ]
[ Entry Count (8 bytes) ]
```

This allows the engine to quickly locate the correct index for a specific table and column.

## Index Entry Structure

Each entry maps a key to a row offset in the database file.

Binary layout:

```bash
[ Key Type (4 bytes) ]
[ Key Length (4 bytes) ]
[ Key Data (N bytes) ]
[ Row Offset (8 bytes) ]
```

Field description:
- Key Type: Enum representing INT, STRING, FLOAT, or BOOL
- Key Length: Size of the key data in bytes
- Key Data: Serialized key value
- Row Offset: 64-bit offset pointing to the row in the `.db` file

## In-Memory Index Representation

When the database starts, index files are loaded into memory for fast access.

Typical structure:

```bash
HashMap<Key, uint64_t offset>
```

Advantages:
- Constant-time lookups
- Reduced disk reads
- Simple synchronization with storage layer

The in-memory map acts as a cache of the on-disk index file.

## Index Creation

Indexes are created when a table is defined with an indexed column or when an explicit index creation command is executed.

Process:

```bash
Scan existing table rows
Extract indexed column values
Compute row offsets
Insert entries into index structure
Persist entries to .idx file
```

This ensures the index is consistent with already stored data.

## Insert and Index Updates

When a new row is inserted, the index must be updated immediately to maintain consistency.

Execution flow:

```bash
Serialize new row
Append row to database file
Compute new row offset
Extract indexed column value
Insert (key, offset) into in-memory index
Append entry to index file
```

This design guarantees that indexed queries remain accurate after inserts.

## Lookup Process

When a query includes a WHERE clause on an indexed column, the query engine delegates the search to the index manager.

Optimized lookup flow:

```bash
Receive query predicate
Check if index exists for column
Search key in in-memory index
Retrieve row offset
Fetch row directly from storage engine
Return result
```

This avoids scanning all rows in the table.

## Range Queries

The initial hash-based index is optimized for equality lookups:

```sql
SELECT * FROM users WHERE id = 10;
```

Range queries such as:

```sql
SELECT * FROM users WHERE id > 10;
```

currently fall back to a full table scan unless a tree-based index is implemented in future versions.

## Index Consistency

GridDB maintains index consistency through synchronous updates during write operations.

Consistency rules:
- Every insert updates the index
- Deleted rows mark index entries as invalid (future feature)
- Index rebuild is supported if corruption is detected

## Rebuilding Indexes

Indexes can be rebuilt from the database file if necessary.

Rebuild process:

```bash
Clear existing index entries
Scan table data blocks
Re-extract indexed values
Recompute row offsets
Rewrite index file
```

This is useful for recovery and integrity validation.

## Error Handling

The indexing system validates:
- Index file magic number
- Version compatibility
- Corrupted entries
- Invalid offsets
- Type mismatches between key and column

If an index file is invalid, the system can safely rebuild it from the database data.

## Future Extensions

Planned improvements to the indexing system include:
- B+ Tree on-disk indexes
- Range query optimization
- Composite indexes
- Lazy index updates
- Compression of index entries
- Background index rebuilding
- Transaction-aware index synchronization