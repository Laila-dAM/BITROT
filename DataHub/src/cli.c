#include "cli.h"
#include "commands.h"
#include <stdio.h>
#include <string.h>

void handle_command(int argc, char **argv) {
    if (argc < 2) {
        printf("Nenhum comando informado\n");
        return;
    }

    if (strcmp(argv[1], "login") == 0) {
        cmd_login(argc, argv);
    } else {
        printf("Comando desconhecido: %s\n", argv[1]);
    }
}
