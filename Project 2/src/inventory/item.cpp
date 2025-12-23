#include "item.h"
#include <sstream>

Inventory::Inventory(Database& database) : db(database) {}

bool Inventory::addItem(const Item& item) {
    std::stringstream ss;
    ss << "INSERT INTO items (name, quantity, price) VALUES ('"
       << item.name << "', " << item.quantity << ", " << item.price << ");";
    return db.execute(ss.str());
}

std::vector<Item> Inventory::getAllItems() {
    std::vector<Item> items;
    sqlite3_stmt* stmt;
    const char* query = "SELECT id, name, quantity, price, deleted FROM items WHERE deleted = 0;";
    if (sqlite3_prepare_v2(db.db, query, -1, &stmt, 0) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            Item item;
            item.id = sqlite3_column_int(stmt, 0);
            item.name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            item.quantity = sqlite3_column_int(stmt, 2);
            item.price = sqlite3_column_double(stmt, 3);
            item.deleted = sqlite3_column_int(stmt, 4);
            items.push_back(item);
        }
    }
    sqlite3_finalize(stmt);
    return items;
}

bool Inventory::updateItem(const Item& item) {
    std::stringstream ss;
    ss << "UPDATE items SET name = '" << item.name
       << "', quantity = " << item.quantity
       << ", price = " << item.price
       << " WHERE id = " << item.id << ";";
    return db.execute(ss.str());
}

bool Inventory::softDeleteItem(int id) {
    std::stringstream ss;
    ss << "UPDATE items SET deleted = 1 WHERE id = " << id << ";";
    return db.execute(ss.str());
}
