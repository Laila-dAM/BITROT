#pragma once
#include "statement.h"
#include <string>
#include <vector>

class InsertStatement : public Statement
{
public:
    std::string tableName;
    std::vector<std::string> values;

    InsertStatement(const std::string& name, const std::vector<std::string>& vals)
        : tableName(name), values(vals) {}

    StatementType type() const override
    {
        return StatementType::INSERT;
    }
};