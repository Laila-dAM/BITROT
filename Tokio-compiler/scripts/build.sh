#!/bin/bash

# Navigate to the project root
cd "$(dirname "$0")/.."

# Clean previous builds
rm -rf build
mkdir -p build/classes

# Compile Java sources
javac -d build/classes src/main/java/tokio/**/*.java src/main/java/tokio/*/*.java

# Check if compilation succeeded
if [ $? -eq 0 ]; then
    echo "Compilation successful!"
else
    echo "Compilation failed!"
    exit 1
fi

# Package into a jar
mkdir -p dist
jar cfe dist/tokio-compiler.jar tokio.Main -C build/classes .

echo "Build complete. JAR created at dist/tokio-compiler.jar"
