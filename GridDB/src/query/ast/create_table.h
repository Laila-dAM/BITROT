#pragma once
#include "statement.h"
#include <string>
#include <vector>

struct ColumnDefinition
{
    std::string name;
    std::string type;
};

class CreateTableStatement : public Statement
{
public:
    std::string tableName;
    std::vector<ColumnDefinition> columns;

    CreateTableStatement(const std::string& name, const std::vector<ColumnDefinition>& cols)
        : tableName(name), columns(cols) {}

    StatementType type() const override
    {
        return StatementType::CREATE_TABLE;
    }
};