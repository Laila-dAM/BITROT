#include <stdio.h>
#include <string.h>
#include "commands.h"
#include "config.h"
#include "db.h"

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
    Config config;

    if (!load_config("config/datahub.conf", &config)) {
        printf("Failed to load configuration.\n");
        return;
    }

    if (!db_open(config.database_path)) {
        printf("Failed to open database.\n");
        return;
    }

    if (!db_init_schema("sql/schema.sql")) {
        printf("Failed to initialize database schema.\n");
        db_close();
        return;
    }

    printf("Database initialized successfully.\n");
    db_close();
}


void command_status(void) {
    Config config;
if (load_config("config/datahub.conf", &config)) {
        printf("DataHub status:\n");
        printf("  Database file: %s\n", config.database_path);
        printf("  Database: ready\n");
        printf("  Users: 0\n");
    } else {
        printf("Configuration not loaded.\n");
    }
}