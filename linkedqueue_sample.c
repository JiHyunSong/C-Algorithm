#include <stdio.h>
#include <stdlib.h>
#include "linkedqueue.h"

int main(){
    int i = 0;
    LinkedQueue *pQueue = NULL;
    QueueNode *pNode = NULL;
    QueueNode node;
    char value = 0;

    pQueue = createLinkedQueue();
    if(pQueue != NULL) {

        node.data = 'A';
        enqueueLQ(pQueue, node);
        
        node.data = 'B';
        enqueueLQ(pQueue, node);
        
        node.data = 'C';
        enqueueLQ(pQueue, node);
        
        node.data = 'D';
        enqueueLQ(pQueue, node);
        
        displayLinkedQueue(pQueue);

        pNode = dequeueLQ(pQueue);
        if(pNode != NULL) {
            printf("Dequeue %c\n", pNode->data);
            free(pNode);
        }

        displayLinkedQueue(pQueue);
    }

    return 0;

}
