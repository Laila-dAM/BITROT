# Memory Management

## Overview

MiniOS implements a simple heap-based dynamic memory allocator.

The allocator operates in kernel space without paging or virtual memory.

All memory management is physical and linear.

---

## Heap Layout

Heap start address:

0x0100000

Heap size:

1 MB

The heap is initialized during kernel startup.

A single large free block is created and managed using a linked list.

---

## Block Structure

Each allocated or free block contains a header:

- size
- status
- next pointer

The block header is stored directly in heap memory.

Allocated memory returned to the user is located immediately after the block header.

---

## Allocation Strategy

The allocator uses a first-fit strategy.

Steps:

1. Traverse the linked list.
2. Find the first free block large enough.
3. Split the block if it is larger than required.
4. Mark the block as used.
5. Return pointer to usable memory.

All allocations are aligned to 4 bytes.

---

## Freeing Memory

When kfree is called:

1. The block header is located by subtracting header size.
2. The block is marked as free.
3. Adjacent free blocks are merged.

This reduces fragmentation over time.

---

## Fragmentation Handling

Fragmentation is reduced by:

- Splitting large blocks
- Merging consecutive free blocks

There is no compaction or relocation.

---

## Limitations

- No paging
- No virtual memory
- No protection mechanisms
- No slab allocation
- No advanced allocation policies
- No thread safety

This design prioritizes clarity over performance.

---

## API

memory_init()

Initializes heap and creates first free block.

kmalloc(size)

Allocates memory of given size.

Returns pointer or null if allocation fails.

kfree(ptr)

Frees previously allocated memory.

---

## Educational Value

This allocator demonstrates:

- Manual heap management
- Linked list memory tracking
- Block splitting
- Block merging
- Basic fragmentation control

It provides a foundation for understanding more advanced memory systems used in modern operating systems.
