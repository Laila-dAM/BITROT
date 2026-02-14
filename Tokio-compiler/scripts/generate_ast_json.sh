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
    echo "Usage: ./scripts/generate_ast_json.sh <example_file.tok>"
    exit 1
fi

SOURCE_FILE="$1"

# Ensure the AST output directory exists
mkdir -p dist/ast

# Run the compiler to generate AST JSON only
java -jar "$JAR_PATH" --ast-only "$SOURCE_FILE" dist/ast/ast.json

EXIT_CODE=$?

if [ $EXIT_CODE -eq 0 ]; then
    echo "AST JSON generated successfully for '$SOURCE_FILE'."
    echo "Output file: dist/ast/ast.json"
else
    echo "AST generation failed with exit code $EXIT_CODE."
fi
