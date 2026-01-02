#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

static int running = 1;

static void show_menu(void)
{
    printf("\n");
    printf("1. Add item\n");
    printf("2. Update item\n");
    printf("3. Delete item\n");
    printf("4. View item\n");
    printf("0. Exit\n");
    printf("Select an option: ");
}

void menu_start(void)
{
    int option;

    while (running)
    {
        show_menu();

        if (scanf("%d", &option) != 1)
        {
            exit(EXIT_FAILURE);
        }

        switch (option)
        {
            case 0:
                running = 0;
                break;
            default:
                printf("Option not implemented\n");
                break;
        }
    }
}
