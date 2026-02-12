ByteForge Language — Summary

ByteForge is an imperative programming language compiled to x86-64 assembly.

Main Characteristics

64-bit signed integers only

Variables declared using let

Arithmetic operators: + - * /

Comparison operators: > < ==

Control flow: while, if, else

Block structure using { }

Built-in print statement

Important Rules

Variables must be declared before use

Redeclaration is not allowed

Comparisons return 0 (false) or 1 (true)

Variables are stored on the stack

Execution starts at the _start label

Basic Example
let x = 10;

while (x > 0) {
    print(x);
    x = x - 1;
}

The language is minimal by design and focuses on demonstrating compiler architecture, parsing, semantic analysis, and assembly code generation.