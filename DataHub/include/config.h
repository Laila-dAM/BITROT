#ifndef CONFIG_H
#define CONFIG_H

typedef struct {
    char database_path[256];
    char log_level[32];
} Config;

int load_config(const char *filename, Config *config);

#endif
