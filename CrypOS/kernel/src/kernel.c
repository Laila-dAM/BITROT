#include "../include/kernel.h"
#include "../include/memory.h"
#include "../include/scheduler.h"
#include "../include/fs.h"

#define VGA_WIDTH 80
#define VGA_HEIGHT 25
#define VGA_MEMORY ((uint16_t*)0xB8000)

static uint16_t* vga_buffer = VGA_MEMORY;
static size_t terminal_row = 0;
static size_t terminal_column = 0;
static uint8_t terminal_color = 0x0F;

static inline uint16_t vga_entry(unsigned char c, uint8_t color)
{
    return (uint16_t)c | (uint16_t)color << 8;
}

void kernel_clear()
{
    for (size_t y = 0; y < VGA_HEIGHT; y++)
    {
        for (size_t x = 0; x < VGA_WIDTH; x++)
        {
            const size_t index = y * VGA_WIDTH + x;
            vga_buffer[index] = vga_entry(' ', terminal_color);
        }
    }

    terminal_row = 0;
    terminal_column = 0;
}

static void terminal_put_char(char c)
{
    if (c == '\n')
    {
        terminal_column = 0;
        terminal_row++;
        return;
    }

    const size_t index = terminal_row * VGA_WIDTH + terminal_column;
    vga_buffer[index] = vga_entry(c, terminal_color);

    terminal_column++;
    if (terminal_column >= VGA_WIDTH)
    {
        terminal_column = 0;
        terminal_row++;
    }

    if (terminal_row >= VGA_HEIGHT)
    {
        terminal_row = 0;
    }
}

void kernel_print(const char* str)
{
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        terminal_put_char(str[i]);
    }
}

void kernel_init()
{
    kernel_clear();
    memory_init();
    scheduler_init();
    fs_init();
}

void kernel_halt()
{
    while (1)
    {
        __asm__ __volatile__("hlt");
    }
}

void kernel_main()
{
    kernel_init();

    kernel_print("MiniOS\n");
    kernel_print("Initializing subsystems...\n");

    scheduler_run();

    kernel_halt();
}
