# File System

## Overview

MiniOS implements a simple in-memory file system.

The file system does not use disk storage. All files exist only during runtime.

It is designed to demonstrate core file system concepts in a minimal environment.

---

## Architecture

The file system is based on a static array of file structures.

Each file entry contains:

- File name
- Data buffer
- File size
- Usage flag

The number of files and maximum file size are fixed at compile time.

---

## Limits

Maximum files: 32

Maximum file name length: 32 characters

Maximum file size: 1024 bytes

These limits are defined as constants in fs.h.

---

## Data Structure

Each file entry contains:

- name
- data
- size
- used flag

Unused entries are marked as not used.

There is no directory hierarchy.

All files exist in a single flat namespace.

---

## Operations

fs_init()

Initializes the file system and clears all file entries.

fs_create(name, data, size)

Creates a new file in memory.

Fails if:
- No free slot is available
- File size exceeds limit

fs_get(name)

Returns a pointer to a file entry if it exists.

fs_read(name, buffer, buffer_size)

Copies file contents into a buffer.

Fails if:
- File does not exist
- Buffer is too small

---

## Behavior

Files are stored entirely in RAM.

There is no:

- Disk persistence
- Journaling
- Metadata timestamps
- File permissions
- Directory structure
- Fragmentation handling

All file access is linear search based.

---

## Design Goals

The file system demonstrates:

- File abstraction
- Static allocation
- Simple metadata management
- Name lookup
- Read operations

It serves as a conceptual introduction to file systems before implementing disk-based storage.

---

## Integration

The shell interacts with the file system through:

- ls command
- cat command

Files can be created programmatically within the kernel.

This subsystem is independent from the memory allocator.
