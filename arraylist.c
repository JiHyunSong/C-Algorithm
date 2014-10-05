#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraylist.h"

ArrayList* createArrayList(int maxElementCount) {
    ArrayList *pReturn = NULL;
    int i=0;

    if(maxElementCount > 0) {
        pReturn = (ArrayList *)malloc(sizeof(ArrayList));

        if(pReturn != NULL) {
            pReturn->maxElementCount = maxElementCount;
            pReturn->currentElementCount = 0;
            pReturn->pElement = NULL;
        }
        else {
            printf("ERROR! Allocate Memory in createArrayList()!\n");
            return NULL;
        }
    }
    else {
        printf("ERROR! maxElementCount must be greater than ZERO!\n");
        return NULL;
    }

    pReturn->pElement = (ArrayListNode *)malloc(sizeof(ArrayListNode) * maxElementCount);

    if(pReturn->pElement == NULL) {
        printf("ERROR! Second allocate Memory!\n");
        free(pReturn);
        return NULL;
    }

    memset(pReturn->pElement, 0, sizeof(ArrayListNode) * maxElementCount);

    return pReturn;
}

int addALElement(ArrayList* pList, int position, ArrayListNode element) {
    int ret = FALSE;
    int i = 0;

    if(pList != NULL) {
        if(isArrayListFull(pList) != TRUE) {
            if(position >= 0 && position <= pList->currentElementCount) {
                for(i = pList->currentElementCount-1; i>= position; i--) {
                    pList->pElement[i+1] = pList->pElement[i];
                }

                pList->pElement[position] = element;
                pList->currentElementCount++;

                ret = TRUE;
            }
            else {
                printf("ERROR! index [%d] indexOutOfBounds in addALElement()\n", position);
            }
        }
        else {
            printf("ERROR! list max!! [%d]/[%d]\n", position, pList->maxElementCount);
        }
    }

    return ret;
}

int removeALElement(ArrayList* pList, int position) {
    int ret = FALSE;
    int i = 0;

    if(pList != NULL) {
        if(position >= 0 && position < pList->currentElementCount) {
            for(i=position; i<pList->currentElementCount-1; i++) {
                pList->pElement[i] = pList->pElement[i+1];
            }
            pList->currentElementCount--;
            ret = TRUE;
        }
        else {
            printf("ERROR! outOfIndex [%d]/[%d] in removeALElement()\n"
                    , position, getArrayListLength(pList));
        }
    }

    return ret;
}

ArrayListNode* getALElement(ArrayList* pList, int position) {
    ArrayListNode* pReturn = NULL;
    if(pList != NULL) {
        if(position >= 0 && position < getArrayListLength(pList)) {
            pReturn = &(pList->pElement[position]);
        }
        else {
            printf("ERROR! outOfIndex [%d]/[%d] in getALElement()\n"
                    , position, getArrayListLength(pList));
        }
    }

    return pReturn;
}

void displayArrayList(ArrayList* pList) {
    int i = 0;
    if(pList != NULL) {
        printf("Maximum Element count : %d\n", pList->maxElementCount);
        printf("Current Element count : %d\n", pList->currentElementCount);

        for(i=0; i<pList->currentElementCount; i++) {
            printf("[%d] %d\n", i, getALElement(pList, i)->data);
        }

        i = pList->currentElementCount;
        for(; i<pList->maxElementCount; i++) {
            printf("[%d] Empty\n", i);
        }
    }
    else {
        printf("ArrayList is NULL!");
    }
}

int isArrayListFull(ArrayList* pList) {
    int ret = FALSE;

    if(pList != NULL) {
        if(pList->currentElementCount == pList->maxElementCount) {
            ret = TRUE;
        }
    }

    return ret;
}

int getArrayListLength(ArrayList* pList) {
    int ret = 0;

    if(pList != NULL) {
        ret = pList->currentElementCount;
    }

    return ret;
}

void deleteArrayList(ArrayList* pList) {
    int i = 0;
    if(pList != NULL) {
        free(pList->pElement);
        free(pList);
    }
}

int addALElementFirst(ArrayList* pList, ArrayListNode element) {
    int position = 0;
    return addALElement(pList, position, element);
}

int addALElementLast(ArrayList* pList, ArrayListNode element) {
    int ret = FALSE;
    int position = 0;
    if(pList != NULL) {
        position = getArrayListLength(pList);
        ret = addALElement(pList, position, element);
    }

    return ret;
}
