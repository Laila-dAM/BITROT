#pragma once
#include <string>
#include <vector>

enum class StatementType
{
    CREATE_TABLE,
    INSERT,
    SELECT,
    DELETE
};

class Statement
{
public:
    virtual ~Statement() = default;
    virtual StatementType type() const = 0;
};