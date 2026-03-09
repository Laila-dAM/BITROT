#include "executor.h"
#include "../core/table.h"
#include "../core/row.h"

Executor::Executor(Database& db)
    : database(db)
{
}

std::vector<std::vector<std::string>> Executor::execute(std::unique_ptr<Statement> stmt)
{
    switch (stmt->type())
    {
        case StatementType::CREATE_TABLE:
        {
            auto* s = static_cast<CreateTableStatement*>(stmt.get());
            executeCreateTable(*s);
            return {};
        }

        case StatementType::INSERT:
        {
            auto* s = static_cast<InsertStatement*>(stmt.get());
            executeInsert(*s);
            return {};
        }

        case StatementType::SELECT:
        {
            auto* s = static_cast<SelectStatement*>(stmt.get());
            return executeSelect(*s);
        }

        case StatementType::DELETE:
        {
            auto* s = static_cast<DeleteStatement*>(stmt.get());
            executeDelete(*s);
            return {};
        }
    }

    return {};
}

void Executor::executeCreateTable(const CreateTableStatement& stmt)
{
    std::vector<Column> columns;

    for (const auto& c : stmt.columns)
    {
        columns.emplace_back(c.name, c.type);
    }

    database.createTable(stmt.tableName, columns);
}

void Executor::executeInsert(const InsertStatement& stmt)
{
    Table& table = database.getTable(stmt.tableName);

    Row row;
    row.values = stmt.values;

    table.insert(row);
}

std::vector<std::vector<std::string>> Executor::executeSelect(const SelectStatement& stmt)
{
    Table& table = database.getTable(stmt.tableName);

    std::vector<std::vector<std::string>> result;

    const auto& rows = table.getRows();

    for (const auto& row : rows)
    {
        result.push_back(row.values);
    }

    return result;
}

void Executor::executeDelete(const DeleteStatement& stmt)
{
    Table& table = database.getTable(stmt.tableName);
    table.clear();
}