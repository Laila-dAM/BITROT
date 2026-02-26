# GridDB Query Engine

## Overview

The GridDB Query Engine is responsible for parsing, planning, and executing database operations on top of the storage engine. It provides a lightweight SQL-like interface that translates user queries into low-level operations over binary data files.

The engine is designed to be modular, deterministic, and tightly integrated with the internal storage format of GridDB.

Core responsibilities:
- Query parsing
- Logical planning
- Execution
- Data retrieval and filtering
- Interaction with storage and indexing layers

## Supported Query Types

The initial version of the query engine supports a minimal but practical subset of database operations:

- CREATE TABLE
- INSERT INTO
- SELECT
- SELECT with WHERE (basic conditions)

Example queries:

```sql
CREATE TABLE users (id INT, name STRING, age INT);
INSERT INTO users VALUES (1, "Alice", 22);
SELECT * FROM users;
SELECT * FROM users WHERE id = 1;
```

## High-Level Architecture

The query engine follows a pipeline-based architecture:

```bash
[ Query String ]
        ↓
[ Lexer ]
        ↓
[ Parser ]
        ↓
[ Abstract Syntax Tree (AST) ]
        ↓
[ Logical Plan ]
        ↓
[ Execution Engine ]
        ↓
[ Storage Engine / Index Manager ]
        ↓
[ Result Set ]
```

This layered flow ensures separation of concerns and future extensibility.

## Lexer

The lexer converts the raw query string into a stream of tokens.

Example:

Input:
```sql
SELECT * FROM users WHERE id = 1;
```

Token stream:
```bash
[SELECT] [ASTERISK] [FROM] [IDENTIFIER(users)] [WHERE] [IDENTIFIER(id)] [EQUALS] [NUMBER(1)] [SEMICOLON]
```

Token types include:
- Keywords (SELECT, INSERT, CREATE, WHERE)
- Identifiers (table names, column names)
- Literals (numbers, strings)
- Operators (=)
- Symbols (*, commas, parentheses, semicolon)

## Parser

The parser transforms the token stream into an Abstract Syntax Tree (AST) that represents the logical structure of the query.

Example AST for a SELECT query:

```bash
SelectStatement
 ├── Table: users
 ├── Columns: *
 └── WhereClause
      ├── Column: id
      ├── Operator: =
      └── Value: 1
```

The parser uses a deterministic recursive-descent approach to keep the implementation simple and maintainable.

## Abstract Syntax Tree (AST)

The AST is a tree representation of the query semantics. Each node represents a specific operation or expression.

Main node types:
- CreateTableNode
- InsertNode
- SelectNode
- WhereNode
- ExpressionNode
- LiteralNode
- IdentifierNode

The AST is independent from execution details, enabling future optimization passes.

## Logical Planning

After parsing, the AST is converted into a logical execution plan. This plan defines what operations must be performed without specifying low-level implementation details.

Example logical plan:

```bash
ScanTable(users)
   ↓
Filter(id = 1)
   ↓
Project(*)
```

Logical operators include:
- Table Scan
- Filter
- Projection
- Insert Operation
- Table Creation Operation

## Execution Engine

The execution engine interprets the logical plan and performs the actual data operations by interacting with the storage engine and index manager.

Execution flow:

```bash
[ Logical Plan ]
        ↓
[ Operator Executor ]
        ↓
[ Row Iteration ]
        ↓
[ Result Materialization ]
```

Each operator is executed in sequence, forming a simple iterator-based execution model.

## Table Scan

The table scan operator reads all rows from a table’s data block stored in the .db file.

Responsibilities:
- Locate table offset
- Read schema metadata
- Iterate over serialized rows
- Deserialize row values

This is the baseline access method when no index is used.

## Filtering (WHERE Clause)

The filter operator evaluates row predicates during iteration.

Example predicate:

```sql
WHERE age = 25
```

Evaluation process:
```bash
For each row:
  Read column value
  Compare with predicate value
  Include or discard row
```

Supported operators (initial version):
- =
- !=
- <
- >
- <=
- >=

## Projection

Projection determines which columns are returned in the result set.

Examples:
```sql
SELECT * FROM users;
SELECT name, age FROM users;
```

Execution behavior:
- Map requested columns to schema indices
- Extract only necessary fields
- Avoid unnecessary deserialization when possible

## Insert Execution

INSERT queries append new rows to the table’s data block.

Execution steps:
```bash
Parse VALUES
Validate against schema
Serialize row
Append to file
Update row count metadata
Update index (if exists)
```

This design favors sequential disk writes for better performance.

## Create Table Execution

CREATE TABLE statements define schema metadata and allocate a new table block in the database file.

Process:
```bash
Validate table name
Parse column definitions
Update table directory
Write schema metadata
Initialize empty row section
```

## Index Integration

When an index exists for a queried column, the engine can bypass full table scans.

Optimized flow:

```bash
[ Query with WHERE on indexed column ]
        ↓
[Index Lookup]
        ↓
[Direct Row Offset Access]
        ↓
[Row Fetch]
```

This significantly reduces I/O for point queries.

## Result Set Representation

Query results are materialized into an in-memory result structure.

Structure:

```bash
ResultSet
 ├── Column Names
 ├── Column Types
 └── Rows[]
```

Each row is stored as a vector of typed values to simplify output formatting and future API integration.

## Error Handling

The query engine performs validation at multiple stages:

- Syntax errors during parsing
- Schema validation errors
- Type mismatch detection
- Missing table or column errors
- Invalid query structure

Errors are reported with clear messages and do not corrupt the database state.

## Extensibility

The query engine is designed to support future features such as:
- JOIN operations
- ORDER BY
- GROUP BY
- Aggregation functions
- Prepared statements
- Query optimization rules
- Cost-based planning

Its modular AST and planning layers allow new operators to be added without redesigning the entire system.