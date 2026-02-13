#!/bin/bash

set -e

ROOT_DIR=$(cd "$(dirname "$0")/.." && pwd)
BUILD_DIR="$ROOT_DIR/kernel/build"
BOOT_DIR="$ROOT_DIR/bootloader"

rm -rf "$BUILD_DIR"/*
rm -f "$BOOT_DIR/boot.bin"
rm -f "$ROOT_DIR/mini-os.img"

echo "Clean completed successfully"
