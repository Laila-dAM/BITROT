#!/bin/bash

PROJECT_ROOT=$(cd "$(dirname "$0")/.." && pwd)
SRC_DIR="$PROJECT_ROOT/src"
BUILD_DIR="$PROJECT_ROOT/build"
OBJ_DIR="$BUILD_DIR/obj"
BIN_DIR="$BUILD_DIR/bin"

mkdir -p "$OBJ_DIR"
mkdir -p "$BIN_DIR"

CXX=${CXX:-g++}
CXXFLAGS="-std=c++17 -Wall -Wextra -O2"

find "$OBJ_DIR" -type f -name "*.o" -delete

for file in $(find "$SRC_DIR" -name "*.cpp"); do
    obj="$OBJ_DIR/$(basename "${file%.cpp}.o")"
    $CXX $CXXFLAGS -c "$file" -o "$obj" || exit 1
done

$CXX $CXXFLAGS "$OBJ_DIR"/*.o -o "$BIN_DIR/byteforge" || exit 1

echo "Build completed successfully"
