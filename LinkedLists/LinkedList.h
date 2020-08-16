// Created by Ali Emre on 23.06.2020.

#ifndef LINKEDLISTS_LINKEDLIST_H
#define LINKEDLISTS_LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int data;
    struct ListNode *next;
}ListNode;

ListNode* AllacoteList(int data);
int ListLength(ListNode *head);

void InsertLinkedList(ListNode **head, int data, int position);
void DeleteLinkedList(ListNode **head,int position);
void PrintLinkedList(ListNode **head);
void PrintReverse(ListNode *head);

int FindBeginofLoop(ListNode *head);
int IsLengthEven(ListNode *head);
ListNode *InsertSorted(ListNode *head, ListNode *newNode);
ListNode *ReverseList(ListNode *head);
ListNode *RecursiveReverse(ListNode *head);
ListNode *MergeSorted(ListNode *a, ListNode *b);



#endif //LINKEDLISTS_LINKEDLIST_H
