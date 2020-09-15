#include "Tree.h"

int main()
{
    BinarySearchTreeNode *root;
    root = NULL;
    root = Insert(root,45);
    root = Insert(root,5);
    root = Insert(root,67);
    root = Insert(root,75);
    root = Insert(root,60);
    InOrder(root);

    root = Delete(root,5);

    InOrder(root);


    return 0;
}