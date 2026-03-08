#include "serializer.h"
#include <cstring>

std::vector<char> Serializer::serializeTable(const Table& table) {
    std::vector<char> result;
    return result;
}

Table Serializer::deserializeTable(const std::vector<char>& data) {
    return Table("table");
}

std::vector<char> Serializer::serializeRow(const Row& row) {
    std::vector<char> result;
    return result;
}

Row Serializer::deserializeRow(const std::vector<char>& data) {
    return Row();
}