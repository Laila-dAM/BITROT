#include <stdio.h>
#include <string.h>
#include "commands.h"

void handle_command(int argc, char *argv[]) {
    if (argc < 2) {
        cmd_help();
        return;
    }

    if (strcmp(argv[1], "help") == 0) {
        cmd_help();
    } else if (strcmp(argv[1], "init") == 0) {
        cmd_init();
    } else if (strcmp(argv[1], "status") == 0) {
        cmd_status();
    } else if (strcmp(argv[1], "add-user") == 0) {
        if (argc < 5) {
            printf("Usage: add-user <username> <password> <role>\n");
            return;
        }
        cmd_add_user(argv[2], argv[3], argv[4]);
    } else if (strcmp(argv[1], "list-users") == 0) {
        cmd_list_users();
    } else {
        printf("Comando desconhecido: %s\n", argv[1]);
    }
}
