#include <stdio.h>
#include <string.h>
#include "config.h"

void show_help() {
    printf("DataHub CLI\n");
    printf("Usage:\n");
    printf("  datahub init     Initialize system\n");
    printf("  datahub status   Show system status\n");
    printf("  datahub help     Show this help\n");
}

int main(int argc, char *argv[]) {
    printf("DataHub CLI starting...\n");

    if (argc < 2) {
        show_help();
        return 0;
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

    return 0;
}
