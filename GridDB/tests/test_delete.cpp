#include <cassert>
#include <iostream>
#include "../src/core/database.h"
#include "../src/core/table.h"
#include "../src/core/row.h"
#include "../src/core/column.h"

int main()
{
    Database db;

    std::vector<Column> columns;
    columns.emplace_back("id", "INT");
    columns.emplace_back("name", "TEXT");

    db.createTable("users", columns);

    Table& table = db.getTable("users");

    Row r1;
    r1.values = {"1", "Alice"};

    Row r2;
    r2.values = {"2", "Bob"};

    table.insert(r1);
    table.insert(r2);

    table.clear();

    const auto& rows = table.getRows();

    assert(rows.empty());

    std::cout << "test_delete passed\n";

    return 0;
}