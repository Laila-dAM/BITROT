#ifndef TABLE_H
#define TABLE_H

#include <string>
#include <vector>
#include "column.h"
#include "row.h"

class Table {
public:
    Table(const std::string& name);
    const std::string& getName() const;
    void addColumn(const Column& column);
    void addRow(const Row& row);
    const std::vector<Column>& getColumns() const;
    const std::vector<Row>& getRows() const;
private:
    std::string name_;
    std::vector<Column> columns_;
    std::vector<Row> rows_;
};

#endiffile_manager.cpp