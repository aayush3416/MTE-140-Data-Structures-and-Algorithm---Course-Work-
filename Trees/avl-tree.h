#ifndef LAB3_AVL_TREE_H
#define LAB3_AVL_TREE_H

#include "binary-search-tree.h"

class AVLTree : public BinarySearchTree {
public:
    // Overriden insert and remove functions
    // Do not modify these definitions

    // The AVL tree should be kept balanced after calling just insert or remove.
    bool insert(DataType val);
    bool remove(DataType val);

    // Define additional functions and attributes below if you need
private:
    void left(Node *node);
    void right(Node *node);
    void leftRight(Node *node);
    void rightLeft(Node *node);
    int heightDiff(Node *node);
    void checkBalance(Node *node);
    int getAvlBalance(Node *node);
    // void updateNodeBalance(Node *parent);
};

#endif  // LAB3_AVL_TREE_H