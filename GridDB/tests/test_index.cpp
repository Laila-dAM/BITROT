#include <cassert>
#include <iostream>
#include "../src/index/hash_index.h"
#include "../src/index/btree.h"

int main()
{
    HashIndex hash;

    hash.insert("1", 0);
    hash.insert("1", 1);
    hash.insert("2", 2);

    auto result1 = hash.find("1");

    assert(result1.size() == 2);
    assert(result1[0] == 0);
    assert(result1[1] == 1);

    hash.remove("1", 0);

    auto result2 = hash.find("1");

    assert(result2.size() == 1);
    assert(result2[0] == 1);

    BTree tree;

    tree.insert("10", 0);
    tree.insert("20", 1);
    tree.insert("30", 2);
    tree.insert("20", 3);

    auto r = tree.search("20");

    assert(r.size() >= 1);

    std::cout << "test_index passed\n";

    return 0;
}