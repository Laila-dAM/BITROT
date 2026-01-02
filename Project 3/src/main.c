#include <stdlib.h>
#include <stdio.h>
#include "inventory_system.h"
#include "database.h"
#include "auth.h"
#include "item.h"

int system_start(void)
{
    Item item;

    printf("%s\n", APP_NAME);
    printf("Version %s\n", APP_VERSION);

    if (db_open("data/inventory.db") != 0)
    {
        return 1;
    }

    if (auth_login("admin", "admin") != 0)
    {
        return 1;
    }

    item.id = 1;
    item.quantity = 10;
    snprintf(item.name, sizeof(item.name), "Keyboard");

    item_create(&item);

    return 0;
}

int system_shutdown(void)
{
    auth_logout();
    db_close();
    return 0;
}

int main(void)
{
    if (system_start() != 0)
    {
        return EXIT_FAILURE;
    }

    system_shutdown();
    return EXIT_SUCCESS;
}
