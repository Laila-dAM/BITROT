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
    echo "Usage: ./scripts/run.sh <source_file.tok>"
    exit 1
fi

SOURCE_FILE="$1"

# Run the compiler
java -jar "$JAR_PATH" "$SOURCE_FILE"
EXIT_CODE=$?

if [ $EXIT_CODE -eq 0 ]; then
    echo "Compilation finished successfully."
else
    echo "Compilation failed with exit code $EXIT_CODE."
fi
