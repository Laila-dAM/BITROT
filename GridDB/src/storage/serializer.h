#ifndef SERIALIZER_H
#define SERIALIZER_H

#include <vector>
#include "core/table.h"
#include "core/row.h"

class Serializer {
public:
    static std::vector<char> serializeTable(const Table& table);
    static Table deserializeTable(const std::vector<char>& data);
    static std::vector<char> serializeRow(const Row& row);
    static Row deserializeRow(const std::vector<char>& data);
};

#endif