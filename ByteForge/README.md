# ByteForge

ByteForge is a custom programming language and compiler built in modern C++.

The project implements the full compilation pipeline:

- Lexical Analysis
- Syntax Parsing
- Abstract Syntax Tree construction
- Semantic Analysis
- Code Generation (x86-64 Assembly)

ByteForge demonstrates compiler architecture, parsing theory, semantic validation, and low-level code generation.

---

## Architecture

The compiler pipeline follows a traditional design:

Source Code (.bf)
        ↓
Lexer → Token Stream
        ↓
Parser → Abstract Syntax Tree
        ↓
Semantic Analyzer → Validated AST
        ↓
Code Generator → Assembly Output
        ↓
Assembler (nasm) → Executable

---

## Language Overview

ByteForge currently supports:

- Integer variables
- Arithmetic operations
- Variable assignment
- Print statements
- While loops
- If statements

Example:

```bash

let x = 10;
while (x > 0) {
print(x);
x = x - 1;
}

```


---

## Build

Linux:

```bash

chmod +x scripts/build.sh
./scripts/build.sh

```


---

## Project Structure

```bash

ByteForge/
├── src/
├── build/
├── tests/
├── examples/
├── docs/
└── scripts/

```


---

## Requirements

- C++17 compatible compiler
- NASM
- GCC or Clang

---

## License

MIT License

