#include "linkedlist.h"

int main() {
    SLL* head = NULL;
    for(int i = 1; i<10; ++i)
        InsertSLL(&head,i*10,i);

    printf("Length of linkedlist: %d\n",ListLength(head));
    printSLList(head);

    SLL* temp =  NthNodeFromEnd(head,2);
    printSLList(temp);

    return 0;
}
