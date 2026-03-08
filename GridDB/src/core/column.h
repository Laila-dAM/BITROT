#ifndef COLUMN_H
#define COLUMN_H

#include <string>

enum class ColumnType {
    INT,
    FLOAT,
    STRING,
    BOOL
};

class Column {
public:
    Column(const std::string& name, ColumnType type);
    const std::string& getName() const;
    ColumnType getType() const;
private:
    std::string name_;
    ColumnType type_;
};

#endif