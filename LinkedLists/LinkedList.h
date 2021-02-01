//
// Created by Ali Emre on 06.01.2021.
//

#ifndef LIST_LINKEDLIST_H
#define LIST_LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}SLL;

typedef struct DoubleNode{
    int data;
    struct DoubleNode* previous;
    struct DoubleNode* next;
}DLL;
/*---------SLL-----------*/
int ListLength(SLL *head);
void InsertSLL(SLL** head,int data,int position);
void DeleteNodeSLL(SLL** head, int position);
void DeleteSLL(SLL** head);
void printSLList(SLL *head);
void PrintList(SLL *head);
/*------------------------*/
void InsertDLL(DLL **head,int data, int position);
void DeleteDLL(DLL **head,int position);

SLL* NthNodeFromEnd(SLL *head,int NthNode);
int IsLooped(SLL* head);
SLL* FindBeginLoop(SLL* head);
#endif //LIST_LINKEDLIST_H
