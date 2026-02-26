# GridDB Architecture

## Overview

GridDB is a lightweight database engine built from scratch in C++ with a layered architecture designed to separate concerns between query processing, execution, storage, and indexing. The system is modular, extensible, and focused on clarity of internal database engine design.

The architecture is inspired by real database systems while remaining educational and minimal.

## High-Level Architecture

GridDB follows a layered pipeline:

```bash
CLI Interface
↓
Query Processing Layer
↓
Execution Engine
↓
Core Database Layer
↓
Storage Engine
↓
File System (Binary Files)
```


Each layer has a well-defined responsibility and communicates through clear interfaces.

## Core Components

### 1. CLI Layer

The CLI layer provides the interactive interface for users to execute queries and internal commands. It is responsible for:

- Reading user input
- Handling meta commands (.exit, .tables, .schema)
- Passing queries to the query engine
- Displaying formatted results

Main module:

```bash
src/cli/
```


## Query Processing Layer

The query processing layer transforms raw text input into executable structures.

### Lexer

The lexer converts raw input strings into a sequence of tokens. It identifies keywords, identifiers, literals, and symbols.

Responsibilities:
- Tokenization
- Keyword recognition
- Basic validation of lexical structure

Modules:

```bash
src/query/lexer.*
src/query/token.h
```


### Parser

The parser converts tokens into an Abstract Syntax Tree (AST) that represents the structure of the query.

Responsibilities:
- Syntax analysis
- AST construction
- Query type detection (CREATE, INSERT, SELECT, DELETE)

Modules:

```bash
src/query/parser.*
src/query/ast/
```


### AST (Abstract Syntax Tree)

The AST represents queries in a structured and executable format.

Statement types:
- CreateTableStatement
- InsertStatement
- SelectStatement
- DeleteStatement

Base hierarchy:

```bash
Statement
├── CreateTableStatement
├── InsertStatement
├── SelectStatement
└── DeleteStatement
```


## Execution Engine

The execution engine receives AST nodes and executes them against the database core.

Responsibilities:
- Dispatching statements
- Coordinating operations with the database and storage layers
- Returning query results

Supported operations:
- Table creation
- Row insertion
- Full table selection
- Conditional deletion

Modules:

```bash
src/query/executor.*
```


## Core Database Layer

The core layer manages logical database structures such as databases, tables, rows, and columns.

### Database

The Database class is the central coordinator of all tables and operations.

Responsibilities:
- Managing table registry
- Loading and saving database state
- Routing operations to the correct table

Modules:

```bash
src/query/executor.*
```


## Core Database Layer

The core layer manages logical database structures such as databases, tables, rows, and columns.

### Database

The Database class is the central coordinator of all tables and operations.

Responsibilities:
- Managing table registry
- Loading and saving database state
- Routing operations to the correct table

Modules:

```bash
src/core/database.*
```


### Table

The Table class represents a logical table with schema and rows.

Responsibilities:
- Storing column definitions
- Managing row storage
- Handling insert, select, and delete operations

Modules:

```bash
src/core/table.*
src/core/row.h
src/core/column.h
```


### Row and Column Model

GridDB uses a structured row model composed of typed columns.

Conceptual structure:

```bash
Table
├── Columns (Schema)
└── Rows (Data Records)
```


Each row stores values aligned with the table schema.

## Storage Engine

The storage engine is responsible for persistence using binary files.

Responsibilities:
- Serializing tables and rows
- Deserializing database state
- Managing file layout
- Ensuring efficient disk I/O

Modules:

```bash
src/storage/file_manager.*
src/storage/serializer.*
src/storage/page.*
```


### File Manager

The file manager handles low-level file operations.

Responsibilities:
- Opening database files
- Reading binary data
- Writing binary data
- Managing file offsets
- Appending records

### Serializer

The serializer converts in-memory structures into binary format and reconstructs them from disk.

Supported serialization targets:
- Database metadata
- Table schemas
- Rows
- Index data

## Indexing Layer

The indexing subsystem provides faster data access by mapping keys to file offsets.

Responsibilities:
- Key lookup acceleration
- Offset mapping
- Future support for advanced index structures

Modules:

```bash
src/index/hash_index.*
src/index/btree.*
```


### Hash Index

The hash index provides fast average-case lookups for equality queries using a key-to-offset mapping.

### B-Tree (Planned)

The B-Tree structure is intended for scalable indexing and ordered data access. It will support efficient search, insertion, and range queries.

## Data Storage Format

GridDB uses a custom binary format for persistence.

Conceptual layout:

```bash
[ Magic Number ]
[ Version ]
[ Table Count ]
├── Table Metadata
├── Column Definitions
└── Row Data
```


Index file format:

```bash
[ Key ] -> [ File Offset ]
```


This design allows efficient sequential reads and direct access through indexing.

## Memory and Data Flow

Execution flow:
1. User inputs a query in the CLI
2. Lexer tokenizes the input
3. Parser builds an AST
4. Executor interprets the AST
5. Core database performs logical operations
6. Storage engine persists or retrieves data
7. Results are returned to the CLI

## Modularity and Extensibility

GridDB is designed with extensibility in mind:

- New query types can be added via new AST nodes
- Storage format can evolve without breaking upper layers
- Indexing strategies can be swapped or extended
- Execution strategies can be optimized independently

## Testing Architecture

The testing layer validates each subsystem independently.

Test coverage areas:
- Insert operations
- Select queries
- Delete logic
- Index behavior
- Serialization correctness

Modules:

```bash
tests/
```


## Future Architectural Enhancements

Planned improvements:
- Page cache system
- Query planner
- Write-ahead logging
- Transaction support
- Concurrency control
- Buffer pool management

These enhancements move the system closer to production-grade database engine architecture while preserving its educational focus.