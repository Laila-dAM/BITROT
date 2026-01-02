#include <string.h>
#include "item.h"

int item_create(const Item *item)
{
    if (!item)
    {
        return 1;
    }
    return 0;
}

int item_update(const Item *item)
{
    if (!item)
    {
        return 1;
    }
    return 0;
}

int item_delete(int id)
{
    if (id <= 0)
    {
        return 1;
    }
    return 0;
}

int item_get(int id, Item *item)
{
    if (id <= 0 || !item)
    {
        return 1;
    }

    item->id = id;
    strcpy(item->name, "Sample Item");
    item->quantity = 0;

    return 0;
}
