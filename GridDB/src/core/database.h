#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>
#include "table.h"

class Database {
public:
    Database(const std::string& filename);
    void executeQuery(const std::string& query);
    Table* getTable(const std::string& name);
private:
    std::string filename_;
    std::vector<Table> tables_;
    void load();
    void save();
};

#endif