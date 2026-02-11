#include <stdio.h>
#include <stdlib.h>
#include "app.h"
#include "../session.h"
#include "../auth.h"
#include "../commands.h"

void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void cli_main_menu(Session *session) {
    int choice = 0;

    while (1) {
        clear_screen();
        printf("=== DataHub Main Menu ===\n");
        printf("1. Manage Users\n");
        printf("2. Manage Roles\n");
        printf("3. Manage Permissions\n");
        printf("4. View Reports\n");
        printf("5. Logout\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            while(getchar() != '\n');
            choice = 0;
        }
        getchar();

        handle_user_choice(session, choice);
    }
}

void handle_user_choice(Session *session, int choice) {
    switch (choice) {
        case 1:
            execute_user_commands(session);
            break;
        case 2:
            execute_role_commands(session);
            break;
        case 3:
            execute_permission_commands(session);
            break;
        case 4:
            execute_report_commands(session);
            break;
        case 5:
            logout(session);
            exit(0);
        default:
            printf("Invalid choice. Press Enter to continue.\n");
            getchar();
            break;
    }
}
