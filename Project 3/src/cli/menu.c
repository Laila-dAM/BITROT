#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "item.h"

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

static void add_item(void)
{
    Item item;

    printf("Item ID: ");
    scanf("%d", &item.id);

    printf("Item name: ");
    scanf("%63s", item.name);

    printf("Quantity: ");
    scanf("%d", &item.quantity);

    item_create(&item);
}

static void update_item(void)
{
    Item item;

    printf("Item ID: ");
    scanf("%d", &item.id);

    printf("New name: ");
    scanf("%63s", item.name);

    printf("New quantity: ");
    scanf("%d", &item.quantity);

    item_update(&item);
}

static void delete_item(void)
{
    int id;

    printf("Item ID: ");
    scanf("%d", &id);

    item_delete(id);
}

static void view_item(void)
{
    Item item;
    int id;

    printf("Item ID: ");
    scanf("%d", &id);

    if (item_get(id, &item) == 0)
    {
        printf("ID: %d\n", item.id);
        printf("Name: %s\n", item.name);
        printf("Quantity: %d\n", item.quantity);
    }
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
            case 1:
                add_item();
