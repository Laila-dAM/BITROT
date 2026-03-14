# GridDB

> A lightweight database engine built from scratch in C++
> Binary storage • Custom query engine • Indexing • Modular architecture

---

## Overview

**GridDB** is a mini database engine developed from scratch in C++, designed to demonstrate deep knowledge of systems programming, storage engines, and internal database architecture.

This project focuses on how real databases work internally rather than relying on external libraries or existing database engines.

GridDB is part of a low-level systems portfolio that includes:

* Operating System (Kernel)
* Compiler with AST and Bytecode
* Database Engine (GridDB)

---

## Core Goals

* Build a database engine from zero
* Implement binary file storage (.db)
* Design a custom query parser (SQL-like)
* Create an internal execution engine
* Implement indexing (Hash / B-Tree)
* Demonstrate layered architecture
* Showcase systems-level engineering

---

## Architecture

GridDB follows a layered internal architecture inspired by real-world database systems:

```
CLI Interface
     ↓
Query Parser (Lexer + AST)
     ↓
Query Executor
     ↓
Core Database Engine
     ↓
Storage Engine (Binary Files)
     ↓
File Manager (.db / .idx)
```

Each module is isolated to ensure scalability, maintainability, and clear separation of concerns.

---

## Features

### Storage Engine

* Binary file persistence
* Custom serialization and deserialization
* Page-based storage system (planned)
* Efficient file I/O using fstream (binary mode)

### Query System

* SQL-like syntax
* Lexer and parser from scratch
* AST-based execution
* Modular query execution pipeline

Supported queries:

```
CREATE TABLE users (id INT, name STRING);
INSERT INTO users VALUES (1, "Alice");
SELECT * FROM users;
DELETE FROM users WHERE id = 1;
```

### Indexing

* Hash index (planned)
* B-Tree index (advanced)
* Fast record lookup using file offsets

### Internal Components

* Database manager
* Table abstraction
* Row and column system
* Query executor
* File manager
* Index manager

---

## Project Structure

```
GridDB/
├── CMakeLists.txt
├── README.md
├── LICENSE
├── .gitignore
│
├── docs/
│   ├── architecture.md
│   ├── storage-format.md
│   ├── indexing.md
│   └── screenshots/
│
├── data/
│   └── example.db
│
├── src/
│   ├── main.cpp
│
│   ├── cli/
│   │   ├── cli.cpp
│   │   └── cli.h
│
│   ├── core/
│   │   ├── database.cpp
│   │   ├── database.h
│   │   ├── table.cpp
│   │   ├── table.h
│   │   ├── row.h
│   │   └── column.h
│
│   ├── storage/
│   │   ├── file_manager.cpp
│   │   ├── file_manager.h
│   │   ├── serializer.cpp
│   │   ├── serializer.h
│   │   ├── page.cpp
│   │   └── page.h
│
│   ├── query/
│   │   ├── lexer.cpp
│   │   ├── lexer.h
│   │   ├── token.h
│   │   ├── parser.cpp
│   │   ├── parser.h
│   │   ├── executor.cpp
│   │   ├── executor.h
│   │   └── ast/
│   │       ├── statement.h
│   │       ├── create_table.h
│   │       ├── insert.h
│   │       ├── select.h
│   │       └── delete.h
│
│   ├── index/
│   │   ├── hash_index.cpp
│   │   ├── hash_index.h
│   │   ├── btree.cpp
│   │   └── btree.h
│
│   └── utils/
│       ├── logger.cpp
│       ├── logger.h
│       ├── constants.h
│       └── errors.h
│
├── tests/
│   ├── test_insert.cpp
│   ├── test_select.cpp
│   ├── test_delete.cpp
│   └── test_index.cpp
│
└── scripts/
    ├── build.sh
    └── run.sh
```

---

## Build & Run

### Requirements

* C++17 or higher
* CMake 3.15+
* GCC / Clang / MSVC

### Build

```bash
mkdir build
cd build
cmake ..
make
```

### Run

```bash
./griddb
```

---

## CLI Example

```
GridDB v0.1
db > CREATE TABLE users (id INT, name STRING);
db > INSERT INTO users VALUES (1, "Alice");
db > SELECT * FROM users;
```

Planned internal commands:

```
.tables
.schema
.exit
.help
```

---

## Testing

GridDB includes unit tests for core components:

* Insert operations
* Select queries
* Delete logic
* Index performance

Run tests:

```bash
ctest
```

---

## Storage Format (Concept)

GridDB uses a custom binary file format:

```
[ MAGIC_NUMBER ]
[ VERSION ]
[ TABLE_COUNT ]

[TABLE_METADATA]
[ROWS...]
```

Index file (.idx):

```
[ KEY ] -> [ FILE OFFSET ]
```

This design enables fast lookups and efficient disk usage.

---

## Educational Value

GridDB demonstrates:

* Systems programming
* Storage engine design
* Parsing and AST execution
* Binary file management
* Data structure implementation
* Performance-oriented architecture

This project is intended for learning how real database engines operate internally.

---

## Aesthetic Direction

Design inspiration:

* Early 2000s software interfaces
* Neon blue & green palette
* Retro grid visuals
* Classic terminal-style CLI

Suggested theme colors:

* Neon Blue: #00AEEF
* Neon Green: #39FF14
* Dark Background: #0A192F

---

<h2 align="center">
  <p align="center">૮ ˙Ⱉ˙ ა bunxie.zip</p>
</h2>
