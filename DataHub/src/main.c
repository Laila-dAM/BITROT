#include <stdio.h>
#include <string.h>

#include "auth.h"
#include "session.h"

int main(int argc, char *argv[]) {
    printf("DataHub CLI starting...\n");

    if (argc == 4 && strcmp(argv[1], "login") == 0) {
        if (auth_login(argv[2], argv[3])) {
            printf("Login OK\n");
            printf("User: %s | Role: %s\n",
                   session_user(),
                   session_role());
        } else {
            printf("Login inválido\n");
        }
        return 0;
    }

    printf("Comando desconhecido\n");
    return 0;
}
