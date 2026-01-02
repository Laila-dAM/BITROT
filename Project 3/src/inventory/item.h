#ifndef ITEM_H
#define ITEM_H

typedef struct
{
    int id;
    char name[64];
    int quantity;
} Item;

int item_create(const Item *item);
int item_update(const Item *item);
int item_delete(int id);
int item_get(int id, Item *item);

#endif
