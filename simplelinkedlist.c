#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simplelinkedlist.h"

LinkedList* createLinkedList() {
    LinkedList *pReturn = NULL;
    int i = 0;

    pReturn = (LinkedList *)malloc(sizeof(LinkedList));

    if(pReturn != NULL) {
        memset(pReturn, 0, sizeof(LinkedList));
    }
    else {
        printf("ERROR! Allocate Memory in createLinkedList()!\n");
        return NULL;
    }

    return pReturn;
}

int addLLElement(LinkedList *pList, int position, ListNode element) {
    int ret = FALSE;
    int i = 0;
    ListNode* pPreNode = NULL;
    ListNode* pNewNode = NULL;

    if(pList != NULL) {
        if(position >= 0 && position <= pList->currentElementCount) {
            pNewNode = (ListNode*)malloc(sizeof(ListNode));
            if(pNewNode != NULL) {
                *pNewNode = element;
                pNewNode->pLink = NULL; // initial Link

                // move the position to last for adding
                pPreNode = &(pList->headerNode);
                for(i=0; i<position; i++) {
                    pPreNode = pPreNode->pLink;
                }

                // link resettled for newNode and existedNode
                pNewNode->pLink = pPreNode->pLink;
                pPreNode->pLink = pNewNode;

                // increment currentElementCount
                pList->currentElementCount++;
                ret = TRUE;
            }
            else {
                printf("ERROR! memory allocation in addLLElement()\n");
                return ret;
            }
        }
        else {
            printf("ERROR! index error [%d] in addLLElement()\n"
                   , position);
        }
    } 

    return ret;
}

int removeLLElement(LinkedList* pList, int position) {
    int ret = FALSE;
    int i = 0;
    int arrayCount = 0;
    ListNode* pNode = NULL;
    ListNode* pDelNode = NULL;

    if(pList != NULL) {
        arrayCount = getLinkedListLength(pList);
        if(position >= 0 && position < arrayCount) {
            pNode = &(pList->headerNode);
            // move to delete node position
            for(i=0; i<position; i++) {
                pNode = pNode->pLink;
            }

            pDelNode = pNode->pLink;
            pNode->pLink = pDelNode->pLink;

            free(pDelNode);

            pList->currentElementCount--;

            ret = TRUE;
        }
        else {
            printf("ERROR! index error [%d] in removeLLElement()\n"
                    , position);
        }
    }
    
    return ret;
}

ListNode* getLLElement(LinkedList* pList, int position) {
    ListNode* pReturn = NULL;
    int i = 0;
    ListNode* pNode = NULL;

    if(pList != NULL) {
        if(position >= 0 && position < pList->currentElementCount) {
            pNode = &(pList->headerNode);
            for(i=0; i<=position; i++) {
                pNode = pNode->pLink;
            }

            pReturn = pNode;
        }
    }

    return pReturn;
}

void deleteLinkedList(LinkedList* pList) {
    int i = 0;
    if (pList != NULL) {
        clearLinkedList(pList);
        free(pList);
    }
}

void clearLinkedList(LinkedList* pList) {
    if(pList != NULL) {
        if(pList->currentElementCount > 0) {
            removeLLElement(pList, 0);
        }
    }
}

int getLinkedListLength(LinkedList* pList) {
    int ret = 0;

    if(pList != NULL) {
        ret = pList->currentElementCount;
    }

    return ret;
}

int isEmpty(LinkedList* pList) {
    int ret = FALSE;

    if(pList != NULL) {
        if(pList->currentElementCount == 0) {
            ret = TRUE;
        }
    }

    return ret;
}

void displayLinkedList(LinkedList* pList) {
    int i = 0;

    if(pList != NULL) {
        printf("current element count : %d\n", pList->currentElementCount);

        for(i=0; i<pList->currentElementCount; i++) {
            printf("[%d] %d\n", i, getLLElement(pList, i)->data);
        }
    }
    else {
        printf("No element exist!\n");
    }
}
