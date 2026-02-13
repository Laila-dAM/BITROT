#include "../include/kernel.h"
#include "../include/fs.h"
#include "../include/scheduler.h"
#include "../include/memory.h"

#define INPUT_BUFFER 128

static char input[INPUT_BUFFER];

static int str_equal(const char* a, const char* b)
{
    while (*a && *b)
    {
        if (*a != *b)
            return 0;
        a++;
        b++;
    }
    return *a == *b;
}

static int str_length(const char* s)
{
    int len = 0;
    while (s[len])
        len++;
    return len;
}

static void str_copy(char* dst, const char* src)
{
    int i = 0;
    while (src[i])
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = 0;
}

static void print_prompt()
{
    kernel_print("> ");
}

static void cmd_help()
{
    kernel_print("help\n");
    kernel_print("clear\n");
    kernel_print("ls\n");
    kernel_print("cat <file>\n");
}

static void cmd_clear()
{
    kernel_clear();
}

static void cmd_ls()
{
    for (int i = 0; i < FS_MAX_FILES; i++)
    {
        extern fs_file_t files[];
        if (files[i].used)
        {
            kernel_print(files[i].name);
            kernel_print("\n");
        }
    }
}

static void cmd_cat(const char* name)
{
    uint8_t buffer[FS_MAX_FILE_SIZE];
    int size = fs_read(name, buffer, FS_MAX_FILE_SIZE);

    if (size < 0)
    {
        kernel_print("file not found\n");
        return;
    }

    for (int i = 0; i < size; i++)
    {
        char c[2];
        c[0] = buffer[i];
        c[1] = 0;
        kernel_print(c);
    }

    kernel_print("\n");
}

static void execute(char* command)
{
    if (str_equal(command, "help"))
    {
        cmd_help();
    }
    else if (str_equal(command, "clear"))
    {
        cmd_clear();
    }
    else if (str_equal(command, "ls"))
    {
        cmd_ls();
    }
    else
    {
        if (str_length(command) > 4 &&
            command[0] == 'c' &&
            command[1] == 'a' &&
            command[2] == 't' &&
            command[3] == ' ')
        {
            cmd_cat(command + 4);
        }
        else
        {
            kernel_print("unknown command\n");
        }
    }
}

void shell_run()
{
    print_prompt();
    input[0] = 0;

    while (1)
    {
        scheduler_yield();
    }
}
