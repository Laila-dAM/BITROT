#include "btree.h"

BTreeNode::BTreeNode(bool leaf)
    : leaf(leaf)
{
}

BTree::BTree(int degree)
    : degree(degree)
{
    root = new BTreeNode(true);
}

BTree::~BTree()
{
    clear();
}

void BTree::clearNode(BTreeNode* node)
{
    if (!node)
        return;

    if (!node->leaf)
    {
        for (auto child : node->children)
            clearNode(child);
    }

    delete node;
}

void BTree::clear()
{
    clearNode(root);
    root = new BTreeNode(true);
}

void BTree::splitChild(BTreeNode* parent, int index, BTreeNode* child)
{
    BTreeNode* newNode = new BTreeNode(child->leaf);

    for (int j = 0; j < degree - 1; j++)
    {
        newNode->keys.push_back(child->keys[j + degree]);
        newNode->values.push_back(child->values[j + degree]);
    }

    if (!child->leaf)
    {
        for (int j = 0; j < degree; j++)
        {
            newNode->children.push_back(child->children[j + degree]);
        }
    }

    child->keys.resize(degree - 1);
    child->values.resize(degree - 1);

    if (!child->leaf)
        child->children.resize(degree);

    parent->children.insert(parent->children.begin() + index + 1, newNode);
    parent->keys.insert(parent->keys.begin() + index, child->keys[degree - 1]);
    parent->values.insert(parent->values.begin() + index, child->values[degree - 1]);
}

void BTree::insert(const std::string& key, size_t value)
{
    BTreeNode* r = root;

    if ((int)r->keys.size() == 2 * degree - 1)
    {
        BTreeNode* s = new BTreeNode(false);
        root = s;

        s->children.push_back(r);

        splitChild(s, 0, r);
        insertNonFull(s, key, value);
    }
    else
    {
        insertNonFull(r, key, value);
    }
}

void BTree::insertNonFull(BTreeNode* node, const std::string& key, size_t value)
{
    int i = node->keys.size() - 1;

    if (node->leaf)
    {
        node->keys.push_back("");
        node->values.push_back(0);

        while (i >= 0 && key < node->keys[i])
        {
            node->keys[i + 1] = node->keys[i];
            node->values[i + 1] = node->values[i];
            i--;
        }

        node->keys[i + 1] = key;
        node->values[i + 1] = value;
    }
    else
    {
        while (i >= 0 && key < node->keys[i])
            i--;

        i++;

        if ((int)node->children[i]->keys.size() == 2 * degree - 1)
        {
            splitChild(node, i, node->children[i]);

            if (key > node->keys[i])
                i++;
        }

        insertNonFull(node->children[i], key, value);
    }
}

void BTree::searchNode(BTreeNode* node, const std::string& key, std::vector<size_t>& result) const
{
    int i = 0;

    while (i < (int)node->keys.size() && key > node->keys[i])
        i++;

    if (i < (int)node->keys.size() && key == node->keys[i])
        result.push_back(node->values[i]);

    if (node->leaf)
        return;

    searchNode(node->children[i], key, result);
}

std::vector<size_t> BTree::search(const std::string& key) const
{
    std::vector<size_t> result;
    searchNode(root, key, result);
    return result;
}