//
// Created by Ali Emre on 21.01.2021.
//

#ifndef HASH_HASH_H
#define HASH_HASH_H

#include <stdio.h>
#include <stdlib.h>

#define LOAD_FACTOR 20

typedef struct ListNode{
    int key;
    int data;
    struct ListNode *next;
}ListNode;

typedef struct HashTableNode{
    int blockCount; //number of elements in block
    ListNode *next;
}HashTableNode;

typedef struct HashTable{
    int size;
    int count;
    HashTableNode **table;
}HashTable;

HashTable* CreateHashTable(int size);
int HashSearch(HashTable *h,int data);

#endif //HASH_HASH_H
