# GridDB Storage Format

## Overview

GridDB uses a custom binary storage format designed for simplicity, efficiency, and full control over low-level data persistence. The storage engine writes and reads structured data directly from binary files without relying on external database systems or serialization frameworks.

The format is deterministic, extensible, and optimized for sequential writes and predictable reads.

GridDB primarily uses two file types:

- Database file: `.db`
- Index file: `.idx`

## Design Goals

- Binary persistence
- Fast disk I/O
- Deterministic layout
- Minimal overhead
- Extensible structure
- Direct offset access
- Compatibility with indexing

## File Types

### Database File (.db)

The main database file stores:
- Metadata
- Table schemas
- Table records (rows)

Example:

```bash
data/griddb.db
```

### Index File (.idx)

The index file stores mappings between keys and file offsets for fast lookups.

Example:

```bash
data/griddb.idx
```

## Global Database Layout

The database file follows a structured binary layout:

```bash
[ Header ]
[ Table Directory ]
[ Table Data Blocks ]
```

## Header Structure

The header is located at the beginning of the file and contains global metadata.

Binary layout:

```bash
[ Magic Number (8 bytes) ]
[ Version (4 bytes) ]
[ Table Count (4 bytes) ]
[ Reserved (16 bytes) ]
```

### Field Description

- Magic Number: Identifies the file as a GridDB database
- Version: Storage format version
- Table Count: Number of tables stored in the database
- Reserved: Space for future extensions

Example magic value:

```bash
"GRIDDB01"
```

## Table Directory

The table directory contains metadata for each table stored in the database.

Layout:

```bash
For each table:
[ Table Name Length (4 bytes) ]
[ Table Name (N bytes) ]
[ Table Offset (8 bytes) ]
```

This allows direct navigation to table data blocks without scanning the entire file.

## Table Data Block

Each table is stored as a contiguous data block.

Structure:

```bash
[ Table Metadata ]
[ Column Definitions ]
[ Row Count ]
[ Row Data Section ]
```

## Table Metadata

Binary layout:

```bash
[ Column Count (4 bytes) ]
[ Row Count (8 bytes) ]
```

## Column Definitions

Each column definition describes the schema of the table.

Per column layout:

```bash
[ Column Name Length (4 bytes) ]
[ Column Name (N bytes) ]
[ Column Type (4 bytes) ]
```

Supported column types:
- INT
- STRING
- FLOAT
- BOOL

Column types are stored as integer enum values for compact representation.

## Row Data Section

Rows are stored sequentially in binary format following the schema definition.

Layout:

```bash
Row 1
Row 2
Row 3
...
Row N
```

Each row is serialized according to column order.

### Row Serialization Format

For each column in a row:

INT:

```bash
[ 4 bytes integer ]
```

FLOAT:

```bash
[ 4 bytes float ]
```

BOOL:

```bash
[ 1 byte boolean ]
```

STRING:

```bash
[ String Length (4 bytes) ]
[ Character Data (N bytes) ]
```

This variable-length encoding allows efficient storage of text data.

## Record Alignment

Records are stored sequentially without padding by default. Alignment can be introduced in future versions if page-based storage is implemented.

## File Offsets and Addressing

GridDB uses 64-bit file offsets to locate:
- Tables
- Rows
- Index entries

This allows large database files and direct random access operations.

Offset example:

```bash
uint64_t tableOffset;
uint64_t rowOffset;
```

## Index File Format (.idx)

The index file provides fast key-to-offset mapping.

Global layout:

```bash
[ Magic Number (8 bytes) ]
[ Version (4 bytes) ]
[ Entry Count (8 bytes) ]
[ Index Entries... ]
```

### Index Entry Structure

Each index entry maps a key to a file offset.

```bash
[ Key Length (4 bytes) ]
[ Key Data (N bytes) ]
[ Row Offset (8 bytes) ]
```

This structure enables fast binary search and efficient lookups.

## Future Extensions

Planned improvements to the storage format include:
- Page-based storage
- Compression support
- Write-ahead logging (WAL)
- Checksums for data integrity
- Secondary indexing
- Schema evolution support