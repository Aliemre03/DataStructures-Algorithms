//
// Created by Ali Emre on 10.09.2020.
//

#include "Tree.h"

void PreOrder(BinarySearchTreeNode *root){
    if(root == NULL)
        return;
    printf("%d", root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}
void InOrder(BinarySearchTreeNode *root){
    if(root == NULL)
        return;
    InOrder(root->left);
    printf("%d\n", root->data);
    InOrder(root->right);
}

void PostOrder(BinarySearchTreeNode *root){
    if(root)
        return;
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d", root->data);
}

BinarySearchTreeNode *Find(BinarySearchTreeNode *root, int data){
    if(root == NULL)
        return NULL;
    if (data < root->data)
        return Find(root->left,data);
    else if (data > root->data)
        return Find(root->right,data);
    return root;
}
BinarySearchTreeNode *FindMin(BinarySearchTreeNode *root){
    if(root == NULL)
        return NULL;
    else if (root->left == NULL)
        return root;
    else
        return FindMin(root->left);
}

BinarySearchTreeNode *FindMax(BinarySearchTreeNode *root){
    if(root == NULL)
        return NULL;
    while (root->right != NULL)
        root = root->right;
    return root;
}

BinarySearchTreeNode *Insert(BinarySearchTreeNode *root, int data){
    if(root == NULL){
        root = malloc(sizeof(BinarySearchTreeNode));

    if (root == NULL){
        printf("Memory error\n");
        return root;
    }
    else{
        root->data = data;
        root->right = root->left = NULL;
        }
    }
    else{
        if (data < root->data)
            root->left = Insert(root->left,data);
        else if (data > root->data)
            root->right = Insert(root->right,data);
    }
    return root;
}

BinarySearchTreeNode *Delete(BinarySearchTreeNode *root, int data){
    BinarySearchTreeNode *temp;
    if(root == NULL)
        printf("Element not there\n");
    else if (data < root->data)
        root->left = Delete(root->left,data);
    else if (data > root->data)
        root->right = Delete(root->right,data);
    else{
        //Found
        if (root->left != NULL && root->right != NULL){
            //replace largest left subtree
            temp = FindMax(root->left);
            root->data = temp->data;
            root->left = Delete(root->left,root->data);
        }
        else{
            //one child
            temp = root;
            if (root->left == NULL)
                root = root->right;
            if (root->right == NULL)
                root = root->left;
            free(temp);
        }
    }
    return root;
}