#pragma once
#include "statement.h"
#include <string>

class DeleteStatement : public Statement
{
public:
    std::string tableName;

    DeleteStatement(const std::string& name)
        : tableName(name) {}

    StatementType type() const override
    {
        return StatementType::DELETE;
    }
};