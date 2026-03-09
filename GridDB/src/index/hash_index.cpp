#include "hash_index.h"
#include <algorithm>

void HashIndex::insert(const std::string& key, size_t rowId)
{
    index[key].push_back(rowId);
}

std::vector<size_t> HashIndex::find(const std::string& key) const
{
    auto it = index.find(key);
    if (it == index.end())
        return {};
    return it->second;
}

void HashIndex::remove(const std::string& key, size_t rowId)
{
    auto it = index.find(key);
    if (it == index.end())
        return;

    auto& vec = it->second;
    vec.erase(std::remove(vec.begin(), vec.end(), rowId), vec.end());

    if (vec.empty())
        index.erase(it);
}

void HashIndex::clear()
{
    index.clear();
}