//
// Created by Ali Emre on 10.09.2020.
//

#ifndef TREE_TREE_H
#define TREE_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct BinarySearchTreeNode {
    int data;
    struct BinarySearchTreeNode *left;
    struct BinarySearchTreeNode *right;
}BinarySearchTreeNode;

void PreOrder( BinarySearchTreeNode *root);
void PostOrder(BinarySearchTreeNode *root);
void InOrder( BinarySearchTreeNode *root);

BinarySearchTreeNode *Find(BinarySearchTreeNode *root, int data);
BinarySearchTreeNode *FindMin(BinarySearchTreeNode *root);
BinarySearchTreeNode *Insert(BinarySearchTreeNode *root, int data);
BinarySearchTreeNode *Delete(BinarySearchTreeNode *root, int data);

#endif //TREE_TREE_H
