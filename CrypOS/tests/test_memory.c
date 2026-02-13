#include <stdio.h>
#include <stdint.h>
#include "../kernel/include/memory.h"

#define TEST_HEAP_SIZE 1024 * 64

static uint8_t test_heap[TEST_HEAP_SIZE];

#undef KERNEL_HEAP_START
#undef KERNEL_HEAP_SIZE
#define KERNEL_HEAP_START ((uint32_t)test_heap)
#define KERNEL_HEAP_SIZE  TEST_HEAP_SIZE

int main()
{
    memory_init();

    void* a = kmalloc(128);
    void* b = kmalloc(256);
    void* c = kmalloc(64);

    if (!a || !b || !c)
    {
        printf("Allocation failed\n");
        return 1;
    }

    kfree(b);

    void* d = kmalloc(200);

    if (!d)
    {
        printf("Reallocation failed\n");
        return 1;
    }

    kfree(a);
    kfree(c);
    kfree(d);

    void* e = kmalloc(512);

    if (!e)
    {
        printf("Merge failed\n");
        return 1;
    }

    printf("Memory tests passed\n");
    return 0;
}
