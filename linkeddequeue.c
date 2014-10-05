#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkeddequeue.h"

LinkedDeque* createLinkedDeque() {
    LinkedDeque *pReturn = NULL;
    int i = 0;

    pReturn = (LinkedDeque*)malloc(sizeof(LinkedDeque));

    if(pReturn != NULL) {
        memset(pReturn, 0, sizeof(LinkedDeque));
    }
    else {
        printf("ERROR! Allocate Memory in createLinkedDeque()\n");
        return NULL;
    }

    return pReturn;
}

int insertFrontLD(LinkedDeque* pDeque, DequeNode element) {
    int ret = FALSE;
    DequeNode *pNode = NULL;

    if(pDeque != NULL) {
        pNode = (DequeNode*)malloc(sizeof(DequeNode));
        if(pNode != NULL) {
            *pNode = element;
            pNode->pRLink = NULL;
            pNode->pLLink = NULL;

            if(isLinkedDequeEmpty(pDeque) == TRUE) {
                pDeque->pFrontNode = pNode;
                pDeque->pRearNode = pNode;
            }
            else {
                pDeque->pFrontNode->pLLink = pNode;
                pNode->pRLink = pDeque->pFrontNode;
                pDeque->pFrontNode = pNode;
            }
            pDeque->currentElementCount++;
            ret = TRUE;
        }
        else {
            printf("ERROR! Allocate Memory in insertFrontLD()\n");
        }
    }

    return ret;
}

int insertRearLD(LinkedDeque* pDeque, DequeNode element) {
    int ret = FALSE;
    DequeNode *pNode = NULL;

    if(pDeque != NULL) {
        pNode = (DequeNode*)malloc(sizeof(DequeNode));
        if(pNode != NULL) {
            *pNode = element;
            pNode->pRLink = NULL;
            pNode->pLLink = NULL;

            if(isLinkedDequeEmpty(pDeque) == TRUE) {
                pDeque->pFrontNode = pNode;
                pDeque->pRearNode = pNode;
            }
            else {
                pDeque->pRearNode->pRLink = pNode;
                pNode->pLLink = pDeque->pRearNode;
                pDeque->pRearNode = pNode;
            }
            pDeque->currentElementCount++;
            ret = TRUE;
        }
        else {
            printf("ERROR! Allocate Memory in insertRearLD()\n");
        }
    }

    return ret;
}

DequeNode* deleteFrontLD(LinkedDeque* pDeque) {
    DequeNode* pReturn = NULL;
    if(pDeque != NULL) {
        if(isLinkedDequeEmpty(pDeque) == FALSE) {
            pReturn = pDeque->pFrontNode;
            pDeque->pFrontNode = pDeque->pFrontNode->pRLink;
            pReturn->pRLink = NULL;

            pDeque->currentElementCount--;
            if(isLinkedDequeEmpty(pDeque) == TRUE) {
                pDeque->pRearNode = NULL;
            }
            else {
                pDeque->pFrontNode->pLLink = NULL;
            }
        }
    }

    return pReturn;
}

DequeNode* peekFrontLD(LinkedDeque* pDeque) {
    DequeNode* pReturn = NULL;
    if(pDeque != NULL) {
        if(isLinkedDequeEmpty(pDeque) == FALSE) {
            pReturn = pDeque->pFrontNode;
        }
    }

    return pReturn;
}

DequeNode* deleteRearLD(LinkedDeque* pDeque) {
    DequeNode* pReturn = NULL;
    if(pDeque != NULL) {
        if(isLinkedDequeEmpty(pDeque) == FALSE) {
            pReturn = pDeque->pRearNode;
            pDeque->pRearNode = pDeque->pRearNode->pLLink;
            pReturn->pLLink = NULL;

            pDeque->currentElementCount--;
            if(isLinkedDequeEmpty(pDeque) == TRUE) {
                pDeque->pFrontNode = NULL;
            }
            else {
                pDeque->pRearNode->pRLink = NULL;
            }
        }
    }

    return pReturn;
}

DequeNode* peekRearLD(LinkedDeque* pDeque) {
    DequeNode* pReturn = NULL;
    if(pDeque != NULL) {
        if(isLinkedDequeEmpty(pDeque) == FALSE) {
            pReturn = pDeque->pRearNode;
        }
    }

    return pReturn;
}

void deleteLinkedDeque(LinkedDeque* pDeque) {
    DequeNode *pNode = NULL;
    DequeNode *pDelNode = NULL;

    if(pDeque != NULL) {
        pNode = pDeque->pFrontNode;
        while(pNode != NULL) {
            pDelNode = pNode;
            pNode = pNode->pRLink;
            free(pDelNode);
        }
    }
}

int isLinkedDequeFull(LinkedDeque* pDeque) {
    int ret = FALSE;
    return ret;
}

int isLinkedDequeEmpty(LinkedDeque* pDeque) {
    int ret = FALSE;

    if(pDeque != NULL) {
        if(pDeque->currentElementCount == 0) {
            ret = TRUE;
        }
    }

    return ret;
}

void displayLinkedDeque(LinkedDeque *pDeque) {
    DequeNode *pNode = NULL;
    int i = 0;

    if(pDeque != NULL) {
        printf("current count of LinkedDeque nodes : %d\n", pDeque->currentElementCount);
        pNode = pDeque->pFrontNode;

        while(pNode != NULL) {
            printf("[%d] %c\n", i, pNode->data);
            i++;
            pNode = pNode->pRLink;
        }
    }
}

