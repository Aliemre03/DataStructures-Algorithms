#include <stdio.h>
#include "LinkedList.h"
int main() {
    ListNode *head = AllacoteList(1);

    for(int i = 0; i < 5; ++i)
    InsertLinkedList(&head,i*10,i);

   PrintLinkedList(&head);


    return 0;
}

