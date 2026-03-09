#!/usr/bin/env bash

set -e

PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BUILD_DIR="$PROJECT_ROOT/build"
EXECUTABLE="$BUILD_DIR/mini_database"

if [ ! -f "$EXECUTABLE" ]; then
    echo "Executable not found. Building project."
    "$PROJECT_ROOT/scripts/build.sh"
fi

cd "$BUILD_DIR"

./mini_database