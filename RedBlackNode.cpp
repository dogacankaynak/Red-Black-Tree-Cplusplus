#include "RedBlackNode.h"

RedBlackNode:: RedBlackNode()
{

}
RedBlackNode:: RedBlackNode(string item)
{
    key = item;
    frequency = 1;
    right = NULL;
    left = NULL;
    parent = NULL;
    color = "RED";
    ctr = 0;
}

RedBlackNode:: RedBlackNode(const RedBlackNode &node): key(node.key),frequency(node.frequency), color(node.color), left(node.left), right(node.right), parent(node.parent)
{
}
RedBlackNode :: ~RedBlackNode()
{

}
