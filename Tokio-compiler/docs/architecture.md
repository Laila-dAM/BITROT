# Tokio Compiler Architecture

## 1. Overview

The Tokio compiler is a modular, multi-stage compiler for a custom programming language.  
It consists of multiple layers: Lexer, Parser, AST, Semantic Analyzer, Code Generator, Interpreter, and CLI.  
Each module is designed to be **separate, testable, and maintainable**.

---

## 2. Compiler Flow

```bash
Source Code (.tok)
│
▼
Lexer
│
▼
Parser
│
▼
AST
│
▼
Semantic Analyzer
│
▼
Code Generator
├─ C Code
└─ Bytecode
│
▼
Interpreter (optional)
```


1. **Lexer**: Converts raw source code into tokens.  
2. **Parser**: Reads tokens and builds an Abstract Syntax Tree (AST).  
3. **AST**: Represents program structure in a hierarchical tree.  
4. **Semantic Analyzer**: Checks type rules, scope, and correctness.  
5. **Code Generator**: Produces target code:
   - **C Generator** → generates equivalent C source code.
   - **Bytecode Generator** → generates custom virtual machine instructions.
6. **Interpreter (optional)**: Executes AST or bytecode directly.  
7. **CLI**: Provides user interface for compiling, running, and testing programs.

---

## 3. Module Responsibilities

### 3.1 Lexer
- Tokenizes input source code
- Reports lexical errors with line and column

### 3.2 Parser
- Constructs AST nodes
- Reports syntax errors with context
- Uses grammar defined in `grammar.ebnf`

### 3.3 AST
- Nodes represent program constructs:
  - ProgramNode, FunctionNode, StatementNode, ExpressionNode, VariableNode, BinaryExpression
- Facilitates semantic analysis and code generation
- Exportable as JSON for AST Viewer

### 3.4 Semantic Analyzer
- Type checking
- Scope management
- Symbol table maintenance
- Ensures variables and functions are correctly used

### 3.5 Code Generator
- **C Generator**: Converts AST into valid C code  
- **Bytecode Generator**: Produces instructions for a custom stack-based VM  
- CodegenManager orchestrates multiple targets

### 3.6 Interpreter
- Executes code directly from AST or bytecode  
- Maintains runtime environment (variables, function stack, etc.)

### 3.7 CLI
- Command line interface for compile/run/test tasks  
- Handles arguments and options

### 3.8 Utilities
- File handling, logging, and configuration management  
- Centralized for maintainability

### 3.9 Exceptions
- Standardized exception classes for lexer, parser, and compiler errors

---

## 4. Data Flow

- Source code → Lexer → Token Stream → Parser → AST → Semantic Analyzer → Code Generator → Output  
- AST can also be exported to **JSON** for visualization in `ast-viewer/`  

---

## 5. Testing and Examples

- Unit tests cover lexer, parser, AST, semantic analysis, and code generation  
- Example `.tok` programs are located in `examples/` folder  
- Scripts automate build, run, and AST export  

---

## 6. Design Principles

- **Modularity**: Each module can be tested independently  
- **Clean Code**: Clear naming, consistent structure, minimal coupling  
- **Extensibility**: Easy to add new syntax, data types, or code targets  
- **Documentation Ready**: Exports AST, logs errors clearly, example programs included