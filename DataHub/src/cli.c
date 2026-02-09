#include <stdio.h>
#include <string.h>
#include "cli.h"
#include "commands.h"

void handle_command(int argc, char *argv[]) {
    if (argc < 2) {
        cmd_help(argc, argv);
        return;
    }

    if (strcmp(argv[1], "help") == 0) {
        cmd_help(argc, argv);
    }
    else if (strcmp(argv[1], "init") == 0) {
        cmd_init(argc, argv);
    }
    else if (strcmp(argv[1], "status") == 0) {
        cmd_status(argc, argv);
    }
    else if (strcmp(argv[1], "add-user") == 0) {
        cmd_add_user(argc, argv);
    }
    else if (strcmp(argv[1], "list-users") == 0) {
        cmd_list_users(argc, argv);   // 👈 novo
    }
    else {
        printf("Comando desconhecido: %s\n", argv[1]);
    }
}
