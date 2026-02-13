#ifndef FS_H
#define FS_H

#include <stddef.h>
#include <stdint.h>

#define FS_MAX_FILES 32
#define FS_MAX_NAME_LENGTH 32
#define FS_MAX_FILE_SIZE 1024

typedef struct {
    char name[FS_MAX_NAME_LENGTH];
    uint8_t data[FS_MAX_FILE_SIZE];
    size_t size;
    uint8_t used;
} fs_file_t;

void fs_init();
int fs_create(const char* name, const uint8_t* data, size_t size);
const fs_file_t* fs_get(const char* name);
int fs_read(const char* name, uint8_t* buffer, size_t buffer_size);

#endif
