#include "RedBlackTree.h"
#include <string.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cmath>
RedBlackTree::RedBlackTree()
{
    //ctor
    root = NULL;
    sVal = 0;
}
void RedBlackTree::wordFrequencies(){
    printNgramFrequenciesAux(root);
}
int RedBlackTree::wordCount(){
    int counter = 0;
    getTotalNgramCountAux(root, counter);
    return counter;
}
void RedBlackTree::getTotalNgramCountAux(RedBlackNode *n, int c){
    if(n == NULL) return;
    else{
        getTotalNgramCountAux(n->right, c);
        c++;
        getTotalNgramCountAux(n->left, c);

    }
}
void RedBlackTree:: inorder(RedBlackNode* root,int n,int m)
{
    if(root)
    {
        inorder(root->left, root->ctr,m);
        if(root->ctr>m)
            n =m;

        inorder(root->right,root->ctr,m);
    }
}

void RedBlackTree::lessFrequent(){
    inorder(root,root->ctr,0);
}
int RedBlackTree::printHeight(){
    return getHeightAux(root);
}
int RedBlackTree::getHeightAux(RedBlackNode *ptr){
    if(ptr == NULL)
        return 0;
    else
        return 1 + getMax(getHeightAux(ptr->left),getHeightAux(ptr->right));
}
int RedBlackTree::getMax(int a, int b){
    if(a < b)
        return b;
    else
        return a;
}
void RedBlackTree::printNgramFrequenciesAux(RedBlackNode* n){
    if(n == NULL) return;
    else{
        printNgramFrequenciesAux(n->right);
        cout<<"- "<<n->key<<" has "<<n->ctr<< " appareances."<<endl;
        printNgramFrequenciesAux(n->left);
    }
}
void RedBlackTree::generateTree(string fileName, int n){
    this->sVal = n;
    ifstream inputfile;
    inputfile.open(fileName.c_str());
    string input;
    while(inputfile>> input){
        if(input.length()>=this->sVal)
            addNgram(input);
    }
    inputfile.close();
}

void RedBlackTree::addNgram(string ngram){
    if(ngram.length() != this->sVal){
        string nGrS;
        int i = 0;
        while(i < ngram.length()){
            int j = 0;
            while(j < sVal && (i + sVal <  ngram.length()+1)){
                nGrS = nGrS + ngram.at(i + j);
                j++;
            }
            addNgram(nGrS);
            nGrS.clear();
            i++;
        }
    }else{
        if(root == NULL){
            root = new RedBlackNode(ngram);
            root->ctr++;
        }else{
            insertItem(root,ngram);
        }

    }
}


void RedBlackTree:: ApplyFixCase1(RedBlackNode* &node)
{
    node->parent->parent->color = "RED";
    node->parent->parent->right->color = "BLACK";
    node->parent->color = "BLACK";
    node->color = "BLACK";
}

void RedBlackTree:: ApplyFixCase2(RedBlackNode* &node)
{
    RedBlackNode* parent = node->parent;
    node->parent->parent->left = node;
    node->left = parent;
    node = parent;
}

void RedBlackTree:: ApplyFixCase3(RedBlackNode* &node)
{
    node->parent->parent = node->parent->right;
    node->parent->color = "BLACK";
    node->parent->right->color = "RED";
}


void RedBlackTree::insertItem(RedBlackNode *&treePtr, const string &newItem){
    if(treePtr == NULL){
        treePtr = new RedBlackNode(newItem);
        if (treePtr == NULL){
            cout<<"insertion failed"<<endl;
        }
    }

    else if(newItem <= treePtr->key){
        insertItem(treePtr->left, newItem);
    }
    else
        insertItem(treePtr->right, newItem);
}


void RedBlackTree:: addWord(string word)
{
    RedBlackNode* n = root;
    insertItem(n, word);

    cout<<"key: "<<n->key<<" color: "<<n->color<<" frequency: "<<n->frequency;
    if(n->parent)
        cout<< "parent: "<< n->parent->key<<endl;
    else
        cout<<endl;

    while(n->parent && n->color == "RED")
    {
        if(n->parent == n->parent->parent->left)
        {
            RedBlackNode* y = n->parent->parent->right;
            if(y->color == "RED")
            {
                ApplyFixCase1(n);
            }
            else if (n == n->parent->right)
            {
                ApplyFixCase2(n);
                ApplyFixCase3(n);
            }
        }
        else
        {
            RedBlackNode* y = n->parent->parent->left;
            if(y->color == "RED")
            {
                ApplyFixCase1(n);
            }
            else if (n == n->parent->left)
            {
                ApplyFixCase2(n);
                ApplyFixCase3(n);
            }
        }
    }
}
RedBlackTree::~RedBlackTree()
{
    //dtor
}
