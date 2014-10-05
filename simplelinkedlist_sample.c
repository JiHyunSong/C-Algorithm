#include <stdio.h>
#include <stdlib.h>
#include "simplelinkedlist.h"

int main(){
    int i = 0;
    int arrayCount = 0;
    LinkedList *pList = NULL;
    ListNode* pNode = NULL;
    ListNode node;

    pList = createLinkedList();
    if(pList != NULL) {
        node.data = 1;
        addLLElement(pList, 0, node);

        node.data = 3;
        addLLElement(pList, 1, node);

        node.data = 5;
        addLLElement(pList, 2, node);

        displayLinkedList(pList);

        printf("Remove element in 1st node\n");
        removeLLElement(pList, 0);
        displayLinkedList(pList);

        printf("add element in 2nd node\n");
        node.data = 10;
        addLLElement(pList, 1, node);
        displayLinkedList(pList);

        deleteLinkedList(pList);
    }

    return 0;

}
