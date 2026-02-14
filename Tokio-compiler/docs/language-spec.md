# Tokio Language Specification

## 1. Overview

Tokio is a small, custom programming language designed for educational and experimental purposes.  
It features a simple syntax, lexical and syntactic analysis, semantic checks, and can generate C code or custom bytecode.

- Target audience: students, compiler enthusiasts
- Paradigm: imperative, block-structured
- Execution: via compiler or optional interpreter

---

## 2. Lexical Elements

### Keywords

```bash
if, else, while, for, return, func, var, const
```


### Operators

```bash
/ % = == != < <= > >= && || !
```


### Delimiters

```bash
( ) { } [ ] ; , .
```


### Identifiers
- Must start with a letter or underscore
- Can contain letters, digits, and underscores
- Case-sensitive

### Literals
- Integer: `123`
- Float: `3.14`
- String: `"hello"`
- Boolean: `true`, `false`

---

## 3. Grammar (simplified)

- Program: sequence of functions or global statements
- Function: `func <name>(<parameters>) { <body> }`
- Statements:
  - Variable declaration: `var x = 10;`
  - Assignment: `x = x + 1;`
  - Conditional: `if (<expr>) { <statements> } else { <statements> }`
  - Loop: `while (<expr>) { <statements> }`
  - Return: `return <expr>;`
- Expressions: arithmetic, boolean, function calls

---

## 4. Semantic Rules

1. Variables must be declared before use.
2. Type checking is enforced:
   - Integers, floats, strings, booleans
   - No implicit type coercion
3. Function arguments must match declared types.
4. No duplicate variable names in the same scope.

---

## 5. Code Generation Targets

1. **C Code**
   - Generates equivalent C functions and statements
   - Supports compilation with standard C compiler
2. **Custom Bytecode**
   - Stack-based virtual machine
   - Instructions for arithmetic, logic, control flow, function call, and variable management

---

## 6. Example

```tokio
func factorial(n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

var result = factorial(5);
``` 
## 7. AST JSON Representation

- Each program is represented as a JSON tree for the AST Viewer.

- Nodes include: ProgramNode, FunctionNode, StatementNode, ExpressionNode, VariableNode, BinaryExpression.

```bash
{
  "type": "ProgramNode",
  "body": [
    {
      "type": "FunctionNode",
      "name": "factorial",
      "params": ["n"],
      "body": [ ... ]
    }
  ]
}
```

## 8. Testing

- Each example program has a corresponding .tok file in the examples/ folder.

- Unit tests verify lexer, parser, semantic analysis, and code generation.

---

<h2 align="center">
  <p align="center">૮ ˙Ⱉ˙ ა bunxie.zip</p>
</h2>

