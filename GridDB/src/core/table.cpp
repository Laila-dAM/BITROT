#include "table.h"

Table::Table(const std::string& name) : name_(name) {}

const std::string& Table::getName() const {
    return name_;
}

void Table::addColumn(const Column& column) {
    columns_.push_back(column);
}

void Table::addRow(const Row& row) {
    rows_.push_back(row);
}

const std::vector<Column>& Table::getColumns() const {
    return columns_;
}

const std::vector<Row>& Table::getRows() const {
    return rows_;
}