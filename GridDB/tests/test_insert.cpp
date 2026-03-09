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

    Row row1;
    row1.values = {"1", "Alice"};

    Row row2;
    row2.values = {"2", "Bob"};

    table.insert(row1);
    table.insert(row2);

    const auto& rows = table.getRows();

    assert(rows.size() == 2);
    assert(rows[0].values[0] == "1");
    assert(rows[0].values[1] == "Alice");
    assert(rows[1].values[0] == "2");
    assert(rows[1].values[1] == "Bob");

    std::cout << "test_insert passed\n";

    return 0;
}