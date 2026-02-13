#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "../kernel/include/fs.h"

int main()
{
    fs_init();

    const char* name = "test.txt";
    const uint8_t data[] = "Hello MiniOS";
    uint8_t buffer[FS_MAX_FILE_SIZE];

    if (fs_create(name, data, sizeof(data) - 1) != 0)
    {
        printf("File creation failed\n");
        return 1;
    }

    int size = fs_read(name, buffer, FS_MAX_FILE_SIZE);
    if (size < 0)
    {
        printf("File read failed\n");
        return 1;
    }

    buffer[size] = '\0';

    if (strcmp((char*)buffer, "Hello MiniOS") != 0)
    {
        printf("File content mismatch\n");
        return 1;
    }

    printf("File system tests passed\n");
    return 0;
}
