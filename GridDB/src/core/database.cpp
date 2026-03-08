#include "database.h"
#include "storage/file_manager.h"
#include <algorithm>
#include <iostream>

Database::Database(const std::string& filename) : filename_(filename) {
    load();
}

void Database::executeQuery(const std::string& query) {
    std::cout << "Executing query: " << query << "\n";
}

Table* Database::getTable(const std::string& name) {
    auto it = std::find_if(tables_.begin(), tables_.end(),
        [&](const Table& t) { return t.getName() == name; });
    if (it != tables_.end()) return &(*it);
    return nullptr;
}

void Database::load() {}

void Database::save() {}