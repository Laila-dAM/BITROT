#include "../include/memory.h"
#include "../include/kernel.h"

#define ALIGN4(x) (((((x) - 1) >> 2) << 2) + 4)

static uint8_t* heap_start = (uint8_t*)KERNEL_HEAP_START;
static heap_block_t* free_list = 0;

void memory_init()
{
    free_list = (heap_block_t*)heap_start;
    free_list->size = KERNEL_HEAP_SIZE - sizeof(heap_block_t);
    free_list->status = HEAP_BLOCK_FREE;
    free_list->next = 0;
}

static void split_block(heap_block_t* block, size_t size)
{
    heap_block_t* new_block = (heap_block_t*)((uint8_t*)block + sizeof(heap_block_t) + size);
    new_block->size = block->size - size - sizeof(heap_block_t);
    new_block->status = HEAP_BLOCK_FREE;
    new_block->next = block->next;

    block->size = size;
    block->next = new_block;
}

void* kmalloc(size_t size)
{
    if (size == 0)
        return 0;

    size = ALIGN4(size);

    heap_block_t* current = free_list;

    while (current)
    {
        if (current->status == HEAP_BLOCK_FREE && current->size >= size)
        {
            if (current->size > size + sizeof(heap_block_t))
            {
                split_block(current, size);
            }

            current->status = HEAP_BLOCK_USED;
            return (void*)((uint8_t*)current + sizeof(heap_block_t));
        }

        current = current->next;
    }

    return 0;
}

static void merge_free_blocks()
{
    heap_block_t* current = free_list;

    while (current && current->next)
    {
        if (current->status == HEAP_BLOCK_FREE &&
            current->next->status == HEAP_BLOCK_FREE)
        {
            current->size += sizeof(heap_block_t) + current->next->size;
            current->next = current->next->next;
        }
        else
        {
            current = current->next;
        }
    }
}

void kfree(void* ptr)
{
    if (!ptr)
        return;

    heap_block_t* block = (heap_block_t*)((uint8_t*)ptr - sizeof(heap_block_t));
    block->status = HEAP_BLOCK_FREE;

    merge_free_blocks();
}
