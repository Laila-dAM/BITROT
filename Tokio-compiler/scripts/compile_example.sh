#!/bin/bash

# Navigate to the project root
cd "$(dirname "$0")/.."

# Path to the compiler JAR
JAR_PATH="dist/tokio-compiler.jar"

# Check if the JAR exists
if [ ! -f "$JAR_PATH" ]; then
    echo "Compiler JAR not found. Please run build.sh first."
    exit 1
fi

# Check if a source file was provided
if [ -z "$1" ]; then
    echo "Usage: ./scripts/compile_example.sh <example_file.tok>"
    exit 1
fi

SOURCE_FILE="$1"

# Ensure the output directories exist
mkdir -p dist/c
mkdir -p dist/bytecode
mkdir -p dist/ast

# Run the compiler
java -jar "$JAR_PATH" "$SOURCE_FILE"

EXIT_CODE=$?

if [ $EXIT_CODE -eq 0 ]; then
    echo "Compilation of '$SOURCE_FILE' finished successfully."
    echo "Generated outputs:"
    echo "- C output: dist/c/output.c"
    echo "- Bytecode: dist/bytecode/output.tbc"
    echo "- AST JSON: dist/ast/ast.json"
else
    echo "Compilation failed with exit code $EXIT_CODE."
fi
