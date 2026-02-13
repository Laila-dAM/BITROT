#!/bin/bash

set -e

ROOT_DIR=$(cd "$(dirname "$0")/.." && pwd)
IMAGE="$ROOT_DIR/mini-os.img"

if [ ! -f "$IMAGE" ]; then
    echo "Disk image not found. Run build.sh first."
    exit 1
fi

qemu-system-i386 \
    -drive format=raw,file="$IMAGE" \
    -m 128M \
    -boot order=c \
    -serial stdio
