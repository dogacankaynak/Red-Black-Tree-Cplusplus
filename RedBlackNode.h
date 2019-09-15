#ifndef REDBLACKNODE_H
#define REDBLACKNODE_H
using namespace std;
#include <iostream>
class RedBlackNode
{
    public:
        RedBlackNode();
        RedBlackNode(string item);
        RedBlackNode(const RedBlackNode &node);
        ~RedBlackNode();

    private:
        string key;
        int frequency;
        RedBlackNode* right;
        RedBlackNode* left;
        RedBlackNode* parent;
        string color;
        int ctr;

    friend class RedBlackTree;
};
#endif // REDBLACKNODE_H
