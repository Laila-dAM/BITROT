#pragma once
#include "statement.h"
#include <string>
#include <vector>

class SelectStatement : public Statement
{
public:
    std::string tableName;
    std::vector<std::string> columns;

    SelectStatement(const std::string& name, const std::vector<std::string>& cols)
        : tableName(name), columns(cols) {}

    StatementType type() const override
    {
        return StatementType::SELECT;
    }
};