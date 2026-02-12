#!/bin/bash

PROJECT_ROOT=$(cd "$(dirname "$0")/.." && pwd)
BIN="$PROJECT_ROOT/build/bin/byteforge"
EXAMPLES_DIR="$PROJECT_ROOT/examples"

if [ ! -f "$BIN" ]; then
    echo "Executable not found. Run build.sh first."
    exit 1
fi

if [ -z "$1" ]; then
    echo "Usage: ./run.sh <example_file.bf>"
    exit 1
fi

SOURCE_FILE="$EXAMPLES_DIR/$1"

if [ ! -f "$SOURCE_FILE" ]; then
    echo "Example file not found: $1"
    exit 1
fi

"$BIN" "$SOURCE_FILE"
