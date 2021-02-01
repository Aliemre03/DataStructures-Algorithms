//
// Created by Ali Emre on 21.01.2021.
//

#include "hash.h"
#include <stdlib.h>
HashTable* CreateHashTable(int size){
    HashTable *hashtable = (HashTable*)malloc(sizeof(HashTable));
    if(!hashtable){
        printf("ERROR");
        return NULL;
    }
    hashtable->size = size / LOAD_FACTOR;
    hashtable->count = 0;
    hashtable->table = malloc(sizeof(HashTableNode*) * hashtable->size);
    if(!hashtable->table){
        printf("ERROR");
        return NULL;
    }
    for(int i = 0; i< hashtable->size; i++){
        hashtable->table[i]->next = NULL;
        hashtable->table[i]->blockCount = 0;
    }
    return hashtable;
}
int HashSearch(HashTable *h,int data){
    ListNode *temp = h->table[Hash(data,h->size)]->next;  //Hash built-in function
}