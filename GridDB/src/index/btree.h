#pragma once
#include <vector>
#include <string>

class BTreeNode
{
public:
    bool leaf;
    std::vector<std::string> keys;
    std::vector<size_t> values;
    std::vector<BTreeNode*> children;

    BTreeNode(bool leaf);
};

class BTree
{
private:
    BTreeNode* root;
    int degree;

    void splitChild(BTreeNode* parent, int index, BTreeNode* child);
    void insertNonFull(BTreeNode* node, const std::string& key, size_t value);
    void searchNode(BTreeNode* node, const std::string& key, std::vector<size_t>& result) const;
    void clearNode(BTreeNode* node);

public:
    BTree(int degree = 3);
    ~BTree();

    void insert(const std::string& key, size_t value);
    std::vector<size_t> search(const std::string& key) const;
    void clear();
};