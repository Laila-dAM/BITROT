#include "../include/fs.h"

static fs_file_t files[FS_MAX_FILES];

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

static void str_copy(char* dst, const char* src, size_t max)
{
    size_t i = 0;
    while (src[i] && i < max - 1)
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
}

void fs_init()
{
    for (int i = 0; i < FS_MAX_FILES; i++)
    {
        files[i].used = 0;
        files[i].size = 0;
    }
}

int fs_create(const char* name, const uint8_t* data, size_t size)
{
    if (size > FS_MAX_FILE_SIZE)
        return -1;

    for (int i = 0; i < FS_MAX_FILES; i++)
    {
        if (!files[i].used)
        {
            files[i].used = 1;
            str_copy(files[i].name, name, FS_MAX_NAME_LENGTH);

            for (size_t j = 0; j < size; j++)
            {
                files[i].data[j] = data[j];
            }

            files[i].size = size;
            return 0;
        }
    }

    return -1;
}

const fs_file_t* fs_get(const char* name)
{
    for (int i = 0; i < FS_MAX_FILES; i++)
    {
        if (files[i].used && str_equal(files[i].name, name))
        {
            return &files[i];
        }
    }

    return 0;
}

int fs_read(const char* name, uint8_t* buffer, size_t buffer_size)
{
    const fs_file_t* file = fs_get(name);
    if (!file)
        return -1;

    if (buffer_size < file->size)
        return -1;

    for (size_t i = 0; i < file->size; i++)
    {
        buffer[i] = file->data[i];
    }

    return file->size;
}
