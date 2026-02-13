#ifndef MEMORY_H
#define MEMORY_H

#include <stddef.h>
#include <stdint.h>

#define HEAP_BLOCK_FREE 0
#define HEAP_BLOCK_USED 1

typedef struct heap_block {
    size_t size;
    uint8_t status;
    struct heap_block* next;
} heap_block_t;

void memory_init();
void* kmalloc(size_t size);
void kfree(void* ptr);

#endif
