#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "../session.h"
#include "../commands.h"

void show_user_menu(Session *session) {
    int choice = 0;
    while (1) {
        printf("\n=== User Management Menu ===\n");
        printf("1. Create User\n");
        printf("2. List Users\n");
        printf("3. Update User\n");
        printf("4. Delete User\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            while(getchar() != '\n');
            choice = 0;
        }
        getchar();

        switch (choice) {
            case 1: create_user(session); break;
            case 2: list_users(session); break;
            case 3: update_user(session); break;
            case 4: delete_user(session); break;
            case 5: return;
            default:
                printf("Invalid choice. Press Enter to continue.\n");
                getchar();
                break;
        }
    }
}

void show_role_menu(Session *session) {
    int choice = 0;
    while (1) {
        printf("\n=== Role Management Menu ===\n");
        printf("1. Create Role\n");
        printf("2. List Roles\n");
        printf("3. Update Role\n");
        printf("4. Delete Role\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            while(getchar() != '\n');
            choice = 0;
        }
        getchar();

        switch (choice) {
            case 1: create_role(session); break;
            case 2: list_roles(session); break;
            case 3: update_role(session); break;
            case 4: delete_role(session); break;
            case 5: return;
            default:
                printf("Invalid choice. Press Enter to continue.\n");
                getchar();
                break;
        }
    }
}

void show_permission_menu(Session *session) {
    int choice = 0;
    while (1) {
        printf("\n=== Permission Management Menu ===\n");
        printf("1. Create Permission\n");
        printf("2. List Permissions\n");
        printf("3. Update Permission\n");
        printf("4. Delete Permission\n");
        printf("5. Back to Main Menu\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            while(getchar() != '\n');
            choice = 0;
        }
        getchar();

        switch (choice) {
            case 1: create_permission(session); break;
            case 2: list_permissions(session); break;
            case 3: update_permission(session); break;
            case 4: delete_permission(session); break;
            case 5: return;
            default:
                printf("Invalid choice. Press Enter to continue.\n");
                getchar();
                break;
        }
    }
}

void show_report_menu(Session *session) {
    int choice = 0;
    while (1) {
        printf("\n=== Reports Menu ===\n");
        printf("1. Users Report\n");
        printf("2. Access Logs Report\n");
        printf("3. Role Permissions Report\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            while(getchar() != '\n');
            choice = 0;
        }
        getchar();

        switch (choice) {
            case 1: generate_users_report(session); break;
            case 2: generate_access_logs_report(session); break;
            case 3: generate_role_permissions_report(session); break;
            case 4: return;
            default:
                printf("Invalid choice. Press Enter to continue.\n");
                getchar();
                break;
        }
    }
}
