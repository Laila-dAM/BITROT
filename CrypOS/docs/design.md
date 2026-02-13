# MiniOS Design

## Overview

MiniOS is a minimal educational operating system written in Assembly and C.

It demonstrates:

- BIOS boot process
- Transition from real mode to protected mode
- 32-bit freestanding kernel
- Basic memory management
- Cooperative scheduler
- In-memory file system
- Minimal shell architecture

The system is designed for learning low-level system architecture and operating system fundamentals.

---

## Boot Process

1. The BIOS loads the first 512 bytes from disk into memory at 0x7C00.
2. The bootloader executes in 16-bit real mode.
3. The kernel is loaded from disk into physical address 0x1000.
4. A Global Descriptor Table is initialized.
5. The CPU switches to 32-bit protected mode.
6. Execution jumps to `kernel_main`.

---

## Kernel Architecture

The kernel is a freestanding 32-bit binary linked at 0x1000.

Core subsystems:

- VGA text terminal output
- Heap-based dynamic memory allocator
- Cooperative round-robin scheduler
- Simple in-memory file system
- Minimal shell interface

The kernel does not rely on the standard C library.

---

## Memory Model

The heap starts at:

0x0100000

Heap size:

1 MB

Memory allocation is handled using a linked list of heap blocks. Blocks are split and merged to manage fragmentation.

The allocator provides:

- kmalloc
- kfree

---

## Scheduler

The scheduler is cooperative and non-preemptive.

Characteristics:

- Fixed maximum number of tasks
- Round-robin execution
- Manual yield control
- No context switching at register level
- Tasks execute as function calls

This simplifies understanding of scheduling logic without hardware interrupts.

---

## File System

The file system is memory-resident.

Features:

- Fixed maximum number of files
- Fixed maximum file size
- Static array storage
- Basic create and read operations

No disk persistence is implemented.

---

## Shell

The shell is minimal and command-based.

Supported commands:

- help
- clear
- ls
- cat <file>

The shell interacts with the file system and terminal output.

---

## Build System

Build components:

- NASM for bootloader
- GCC (32-bit freestanding) for kernel
- LD with custom linker script
- QEMU for execution

The final image layout:

| Bootloader (512 bytes) | Kernel (raw binary) |

The image is executed as a raw disk in QEMU.

---

## Educational Goals

This project demonstrates:

- Real mode to protected mode transition
- GDT configuration
- Bare-metal C execution
- Manual memory management
- Basic scheduler logic
- Simple kernel modularization
- Low-level build and linking process

MiniOS is intentionally minimal to focus on architecture clarity and learning.
