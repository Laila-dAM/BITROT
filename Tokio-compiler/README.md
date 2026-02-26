# TOKIO Compiler

Tokio is a custom programming language compiler written in Java.

It includes lexical analysis, parsing, AST generation, semantic analysis, C code generation, custom bytecode generation, and an optional interpreter.

---

## Features

- Custom language design
- Lexer and recursive descent parser
- Abstract Syntax Tree (AST)
- Semantic analysis
- C code generation
- Custom bytecode generation
- CLI interface
- AST Viewer (HTML/JS)
- JUnit tests

---

## Requirements

- Java 17+
- Gradle 8+

Check Java:

```bash
java -version
```


---

## Build (Windows)

Generate wrapper:

```bash
gradle wrapper
```


Build:

```bash
.\gradlew build
```


Generate executable JAR:

```bash
.\gradlew fatJar
```

Run:

```bash
java -jar build/libs/tokio-compiler-1.0.0-all.jar examples/hello.tok
```

---

## Structure

```bash
src/main/java/tokio/
├── lexer
├── parser
├── ast
├── semantic
├── codegen
├── interpreter
├── cli
└── exceptions
```


---

## Outputs

- C code → `dist/c/`
- Bytecode → `dist/bytecode/`
- AST JSON → `dist/ast/`

---

## AST Viewer

Open:

```bash
ast-viewer/index.html
```

---

<h2 align="center">
  <p align="center">૮ ˙Ⱉ˙ ა bunxie.zip</p>
</h2>