#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input.h"

void read_string(const char *prompt, char *buffer, int size) {
    printf("%s", prompt);
    if (fgets(buffer, size, stdin) != NULL) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
    }
}

int read_int(const char *prompt) {
    char buffer[32];
    read_string(prompt, buffer, sizeof(buffer));
    return atoi(buffer);
}
