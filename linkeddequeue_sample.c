#include <stdio.h>
#include <stdlib.h>
#include "linkeddequeue.h"

int main() {
    LinkedDeque *pDeque = NULL;
    DequeNode *pNode = NULL;

    DequeNode node;

    pDeque = createLinkedDeque();
    if(pDeque != NULL) {
        node.data = 'A';
        insertFrontLD(pDeque, node);

        node.data = 'B';
        insertFrontLD(pDeque, node);
        
        node.data = 'C';
        insertFrontLD(pDeque, node);

        node.data = 'D';
        insertFrontLD(pDeque, node);

        displayLinkedDeque(pDeque);

        pNode = deleteFrontLD(pDeque);
        if(pNode != NULL) {
            printf("delete FrontLD Value %c \n ", pNode->data);
            free(pNode);
        }

        displayLinkedDeque(pDeque);
        deleteLinkedDeque(pDeque);
    }

    return 0;

}
