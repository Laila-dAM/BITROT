#include "row.h"

Row::Row() {}

void Row::addCell(const Cell& cell) {
    cells_.push_back(cell);
}

const std::vector<Cell>& Row::getCells() const {
    return cells_;
}