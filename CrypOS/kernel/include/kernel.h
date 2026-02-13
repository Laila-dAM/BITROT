#ifndef KERNEL_H
#define KERNEL_H

#include <stddef.h>
#include <stdint.h>

#define KERNEL_HEAP_START 0x0100000
#define KERNEL_HEAP_SIZE  0x00100000

void kernel_main();

void kernel_init();
void kernel_halt();

void kernel_print(const char* str);
void kernel_clear();

#endif
