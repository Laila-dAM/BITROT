#!/bin/bash

set -e

ROOT_DIR=$(cd "$(dirname "$0")/.." && pwd)
BUILD_DIR="$ROOT_DIR/kernel/build"
BOOT_DIR="$ROOT_DIR/bootloader"
KERNEL_DIR="$ROOT_DIR/kernel"
TOOLS_DIR="$ROOT_DIR/tools"

mkdir -p "$BUILD_DIR"

nasm -f bin "$BOOT_DIR/boot.asm" -o "$BOOT_DIR/boot.bin"

gcc -m32 -ffreestanding -c \
"$KERNEL_DIR/src/kernel.c" \
"$KERNEL_DIR/src/memory.c" \
"$KERNEL_DIR/src/scheduler.c" \
"$KERNEL_DIR/src/fs.c" \
"$KERNEL_DIR/src/shell.c" \
-I"$KERNEL_DIR/include" \
-nostdlib \
-fno-pie \
-o "$BUILD_DIR/kernel.o"

ld -m elf_i386 -T "$TOOLS_DIR/linker.ld" \
-o "$BUILD_DIR/kernel.bin" \
"$BUILD_DIR/kernel.o" \
--oformat binary

cat "$BOOT_DIR/boot.bin" "$BUILD_DIR/kernel.bin" > "$ROOT_DIR/mini-os.img"

echo "Build completed successfully"
