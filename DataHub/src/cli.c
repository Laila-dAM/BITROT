#include <stdio.h>
#include <string.h>
#include "cli.h"

static void show_help() {
    printf("DataHub CLI\n");
    printf("Commands:\n");
    printf("  help      Show this help\n");
    printf("  init      Initialize system\n");
    printf("  status    Show system status\n");
}

void handle_command(int argc, char *argv[]) {
    if (argc < 2) {
        show_help();
        return;
    }

    if (strcmp(argv[1], "help") == 0) {
        show_help();
    }
    else if (strcmp(argv[1], "init") == 0) {
        printf("System initialized successfully.\n");
    }
    else if (strcmp(argv[1], "status") == 0) {
        printf("System status: OK\n");
    }
    else {
        printf("Unknown command: %s\n", argv[1]);
        show_help();
    }
}
