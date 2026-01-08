#include <stdio.h>
#include "menu.h"

void menu_start(void)
{
    int option = 0;

    while (option != 3)
    {
        printf("\n1. List items\n");
        printf("2. Add item\n");
        printf("3. Exit\n");
        printf("Select option: ");

        scanf("%d", &option);

        switch (option)
        {
            case 1:
                printf("Listing items\n");
                break;
            case 2:
                printf("Adding item\n");
                break;
            case 3:
                printf("Exiting\n");
                break;
            default:
                printf("Invalid option\n");
        }
    }
}
