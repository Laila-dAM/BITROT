#include <stdio.h>
#include <string.h>
#include "commands.h"
#include "config.h"

void print_help(void) {
    printf("DataHub CLI\n");
    printf("Commands:\n");
    printf("  help        Show this help\n");
    printf("  init        Initialize system\n");
    printf("  status      Show system status\n");
}

void print_command_help(const char *command) {
    if (strcmp(command, "init") == 0) {
        printf("init:\n");
        printf("  Initializes the DataHub system\n");
    }
    else if (strcmp(command, "status") == 0) {
        printf("status:\n");
        printf("  Displays current system status\n");
    }
    else {
        printf("No help available for '%s'\n", command);
    }
}

void command_init(void) {
    printf("Initializing DataHub system...\n");
    printf("System initialized successfully.\n");
}

void command_status(void) {
    Config config;

    if (load_config("config/datahub.conf", &config)) {
        printf("DataHub status:\n");
        printf("  Database: %s\n", config.database_path);
        printf("  Log level: %s\n", config.log_level);
    } else {
        printf("DataHub status:\n");
        printf("  Configuration not loaded\n");
    }
}