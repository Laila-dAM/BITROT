#include "column.h"

Column::Column(const std::string& name, ColumnType type) : name_(name), type_(type) {}

const std::string& Column::getName() const { return name_; }

ColumnType Column::getType() const { return type_; }