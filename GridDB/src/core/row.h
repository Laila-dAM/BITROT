#ifndef ROW_H
#define ROW_H

#include <vector>
#include <variant>
#include <string>

using Cell = std::variant<int, float, std::string, bool>;

class Row {
public:
    Row();
    void addCell(const Cell& cell);
    const std::vector<Cell>& getCells() const;
private:
    std::vector<Cell> cells_;
};

#endif