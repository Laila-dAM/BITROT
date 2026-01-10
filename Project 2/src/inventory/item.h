#ifndef ITEM_H
#define ITEM_H

#include "../db/database.h"
#include <string>
#include <vector>

struct Item {
    int id;
    std::string name;
    int quantity;
    double price;
    bool deleted;
};

class Inventory {
public:
    Inventory(Database& db);
    bool addItem(const Item& item);
    std::vector<Item> getAllItems();
    bool updateItem(const Item& item);
    bool softDeleteItem(int id);

private:
    Database& db;
};

#endif
