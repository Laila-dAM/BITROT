#pragma once
#include <string>
#include <vector>
#include <unordered_map>

class HashIndex
{
private:
    std::unordered_map<std::string, std::vector<size_t>> index;

public:
    void insert(const std::string& key, size_t rowId);
    std::vector<size_t> find(const std::string& key) const;
    void remove(const std::string& key, size_t rowId);
    void clear();
};