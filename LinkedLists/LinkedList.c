//
// Created by Ali Emre on 06.01.2021.
//

#include "linkedlist.h"

int ListLength(SLL *head)
{
    SLL *current = head;
    int count = 0;
    while (current != NULL){
        count++;
        current = current->next;
    }
    return count;
}

void InsertSLL(SLL** head,int data,int position)
{
    int counter = 1;
    SLL* newNode = malloc(sizeof(SLL));
    newNode->data = data;
    SLL* current = *head;
    SLL* previous;
    //inserting begging
    if(position == 1){
        newNode->next = current;
        *head = newNode;
    }
    //travel until position
    else{
        while(current != NULL && counter < position){
            counter++;
            previous = current;
            current = current->next;
        }
        previous->next = newNode;
        newNode->next = current;
    }
}

void DeleteNodeSLL(SLL** head, int position){
    int counter = 1;
    SLL* previous,*current;
    current = *head;

    if(position == 1){
        *head = (*head)->next;
        free(current);
        return;
    }
    //travel until position
    else{
        while(current != NULL && counter < position){
            counter++;
            previous = current;
            current= current->next;
        }
        if(current == NULL)
            printf("Position doesn't exist !!\n");
        else{
            previous->next = current->next;
            free(current);
        }
    }
}

void DeleteSLL(SLL** head){
    SLL *auxilaryNode,*iterator;
    iterator = *head;

    while(iterator != NULL){
        auxilaryNode = iterator->next;
        free(iterator);
        iterator = auxilaryNode;
    }
    *head = NULL;
}

void printSLList(SLL *head){
    while(head != NULL){
        printf("%d->",head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void InsertDLL(DLL **head,int data, int position){
    int counter = 1;
    DLL *temp,*newNode;
    newNode = malloc(sizeof(DLL));
    newNode->data = data;

    if(position == 1){ // Inserting at beginnig
        newNode->next = *head;
        newNode->previous = NULL;
        if(*head != NULL)
            (*head)->previous = newNode;

        *head = newNode;
        return;
    }
    temp = *head;
    while(temp->next != NULL && counter < position -1){
        counter++;
        temp = temp->next;
    }
    if(counter != position)
        printf("Position does NOT exist\n");
    newNode->next = temp->next;
    newNode->previous = temp;

    if(temp->next)
        temp->next->previous = newNode;

    temp->next = newNode;
    return;
}

void DeleteDLL(DLL **head,int position){
    int counter = 1;
    DLL *temp,*temp2;
    temp = *head;
    if(*head == NULL){
        printf("List is empty!\n");
        return;
    }
    if(position == 1){
        *head = (*head)->next;
        if(*head != NULL)
            (*head)->previous = NULL;
        free(temp);
        return;
    }
    while(temp->next != NULL && counter < position){
        counter++;
        temp = temp->next;
    }
    if(counter != position -1)
        printf("Position does NOT exist!!\n");
    temp2 = temp->previous;
    temp2->next = temp->next;
    if(temp->next)
        temp->next->previous = temp2;
    free(temp);
    return;
}

SLL* NthNodeFromEnd(SLL *head,int NthNode){
    SLL *thNode = NULL,*temp = head;

    for(int count = 1; count < NthNode; ++count){
        if(temp)
            temp = temp->next;
    }
    while(temp){
        if(thNode == NULL)
            thNode = head;
        else
            thNode = thNode->next;
        temp = temp->next;
    }
    if(thNode)
        return thNode;
    return NULL;
}

int IsLooped(SLL* head){
    SLL *fastPtr = head, *slowPtr = head;

    while(fastPtr && slowPtr && fastPtr->next){
        fastPtr = fastPtr->next->next;
        slowPtr = slowPtr->next;
        if(slowPtr == fastPtr)
            return 1; // cyclic
    }
    return 0;
}

SLL* FindBeginLoop(SLL* head){
    SLL *fastPtr = head, *slowPtr = head;
    int loopExist = IsLooped(head);

    if(loopExist){
        while(slowPtr != fastPtr){
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
        }
        return slowPtr;
    }
    return NULL;
}
