#include "commands.h"
#include "auth.h"
#include <stdio.h>

void cmd_login(int argc, char **argv) {
    if (argc < 4) {
        printf("Uso: login <user> <password>\n");
        return;
    }

    if (auth_login(argv[2], argv[3])) {
        printf("Login OK\n");
        printf("User: %s\n", auth_current_user());
    } else {
        printf("Login inválido\n");
    }
}
