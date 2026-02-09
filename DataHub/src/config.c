#include <stdio.h>
#include <string.h>
#include "config.h"

int load_config(const char *filename, Config *config) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        return 0;
    }

    char line[256];

    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '#' || line[0] == '\n')
            continue;

        char key[128], value[128];
        if (sscanf(line, "%127[^=]=%127s", key, value) == 2) {
            if (strcmp(key, "database") == 0) {
                strncpy(config->database_path, value, sizeof(config->database_path));
            } else if (strcmp(key, "log_level") == 0) {
                strncpy(config->log_level, value, sizeof(config->log_level));
            }
        }
    }

    fclose(file);
    return 1;
}
