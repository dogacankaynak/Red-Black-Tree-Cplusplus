#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H
#include "RedBlackNode.h"
using namespace std;
#include <iostream>


class RedBlackTree
{
    public:
        void lessFrequent();
        RedBlackTree();
        virtual ~RedBlackTree();
        void generateTree(string fileName, int n);
        void addNgram(string ngram);
        void insertItem(RedBlackNode *&treePtr, const string &newItem);
        void ApplyFixCase1(RedBlackNode* &node);
        void ApplyFixCase2(RedBlackNode* &node);
        void ApplyFixCase3(RedBlackNode* &node);
        void addWord(string word);
        int sVal;
        RedBlackNode *root;
        void wordFrequencies();
        int getHeightAux(RedBlackNode *ptr);
        int getMax(int a, int b);
        int wordCount();
        int printHeight();
        void inorder(RedBlackNode* root,int n,int m);
        void getTotalNgramCountAux(RedBlackNode *n, int c);
        void printNgramFrequenciesAux(RedBlackNode* n);
    protected:

    private:
};

#endif // REDBLACKTREE_H
