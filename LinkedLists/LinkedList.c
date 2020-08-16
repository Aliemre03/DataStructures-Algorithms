//
// Created by Ali Emre on 23.06.2020.
//
#include "LinkedList.h"

int ListLength(ListNode *head){
    ListNode *current = head;
    int count = 0;

    while(current != NULL){
        count++;
        current = current->next;
    }
    return count;
}

ListNode* AllacoteList(int data){
    ListNode *newNode;
    newNode = malloc(sizeof(ListNode));

    if(!newNode){
        printf("Memory error !!!\n");
        return NULL;
    }
    newNode->data = data;
    return newNode;
}

void InsertLinkedList(ListNode **head, int data, int position){
    int k = 1;
    ListNode *p;
    ListNode *q = NULL;
    ListNode *newNode;

    newNode = AllacoteList(data);

    p = *head;

    if(position == 1){
        newNode->next = p;
        *head = newNode;
    }
    else{
        while((p != NULL) && (k < position)){
            k++;
            q = p;
            p = p->next;
        }
        q->next = newNode;
        newNode->next = p;
    }
}

void DeleteLinkedList(ListNode **head,int position){
    int k = 1;
    ListNode *p,*q;

    if(*head == NULL) {
        printf("list is empty \n");
        return;
    }

    p = *head;

    if(position == 1){
        *head = (*head)->next;
        free(p);
        return;
    }
    else{
        while((p != NULL) && ( k < position)){
            k++;
            q = p;
            p = p->next;
        }
        if(p == NULL)
            printf("Position doesn't exist");
        else{
            q->next = p->next;
            free(p);
        }
    }

}

void PrintLinkedList(ListNode **head){
    ListNode *iter = *head;
    int i = 1;
    while(iter->next != NULL){
        printf("%d) %d\n",i,iter->data);
        iter = iter->next;
        ++i;
    }
    return;
}

int FindBeginofLoop(ListNode *head){
    ListNode *fastptr = head,*slowptr = head;

    int loopExist = 0;

    while(slowptr && fastptr && fastptr->next){
       slowptr = slowptr->next;
       fastptr = fastptr->next->next;

       if(slowptr == fastptr){
           loopExist = 1;
           break;
       }
    }

    if(loopExist){
        slowptr = head;
        while(slowptr != fastptr){
            slowptr = slowptr->next;
            fastptr = fastptr->next;
        }
        return slowptr;
    }
    return NULL;
}

ListNode *InsertSorted(ListNode *head, ListNode *newNode){
    ListNode *current = head,*temp;

    if(!head)
        return newNode;

    while(current != NULL && current->data < newNode->data){
        temp = current;
        current = current->next;
    }
    newNode->next = current;
    temp->next =newNode;
    return head;
}

ListNode *ReverseList(ListNode *head){
    ListNode *temp = NULL, *nextNode = NULL;

    while(head){
        nextNode = head->next;
        head->next = temp;
        temp = head;
        head = nextNode;
    }
    return temp;
}

ListNode *RecursiveReverse(ListNode *head){
    if(head == NULL)
        return NULL;
    if(head->next == NULL)
        return head;

    ListNode *second = head->next;
    head->next = NULL;
    ListNode *reverseRest = RecursiveReverse(second);
    second->next = head;
    return reverseRest;
}

void PrintReverse(ListNode *head){
    if(!head)
        return;

    PrintReverse(head->next);
    printf("%d ",head->data);
}

int IsLengthEven(ListNode *head){
    while(head && head->next)
        head = head->next;
    if(!head)
        return 0;
    return 1;
}

ListNode *MergeSorted(ListNode *a, ListNode *b){
    ListNode *result =  NULL;

    if(a == NULL) return b;
    if(b == NULL) return a;

    if(a->data <= b->data){
        result = a;
        result->next = MergeSorted(a->next,b);
    }
    else{
        result = b;
        result->next = MergeSorted(a,b->next);
    }
    return result;

}
