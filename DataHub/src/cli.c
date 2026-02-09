#include <stdio.h>
#include <string.h>
#include "cli.h"
#include "commands.h"

void handle_command(int argc, char *argv[]) {
    if (argc < 2) {
        print_help();
        return;
    }

    if (strcmp(argv[1], "help") == 0) {
        if (argc == 3) {
            print_command_help(argv[2]);
        } else {
            print_help();
        }
    }
    else if (strcmp(argv[1], "init") == 0) {
        command_init();
    }
    else if (strcmp(argv[1], "status") == 0) {
        command_status();
    }
    else {
        printf("Error: unknown command '%s'\n", argv[1]);
        printf("Run 'datahub help' to see available commands.\n");
    }
}
