/*
 * =====================================================================================
 *
 *       Filename:  284_peeking_iterator.c
 *
 *    Description:  peeking iterator
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04.3) 11.4.0
 *
 *         Author:  Ian
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

/*
 *    struct Iterator {
 *        // Returns true if the iteration has more elements.
 *        bool (*hasNext)();
 *
 *         // Returns the next element in the iteration.
 *        int (*next)();
 *    };
 */

#define MAX_ARRSIZE 1000

struct PeekingIterator {
    int *arr;
    int aindex;
    int arrSize;
};

struct PeekingIterator* Constructor(struct Iterator* iter) {

    struct PeekingIterator* piter = malloc(sizeof(struct PeekingIterator));

    memset(piter, 0, sizeof(*piter));
    piter->arr = calloc(MAX_ARRSIZE, sizeof(int));

    while (iter->hasNext()) {
        piter->arr[piter->arrSize] = iter->next();
        piter->arrSize++; 
    }
    return piter;
}

int peek(struct PeekingIterator* obj) {

    int val = -1;

    if (!obj)
        return val;

    if (obj->aindex < obj->arrSize) {
        val = obj->arr[obj->aindex];  
    }
    return val;
}

int next(struct PeekingIterator* obj) {

    int val = -1;

    if (!obj)
        return val;

    if (obj->aindex < obj->arrSize) {
        val = obj->arr[obj->aindex];
        obj->aindex++;
    }
    return val;
}

bool hasNext(struct PeekingIterator* obj) {

    if (!obj)
        return false;

    if (obj->aindex >= obj->arrSize)
        return false;
    return true;
}

/**
 * Your PeekingIterator struct will be instantiated and called as such:
 * PeekingIterator* obj = peekingIteratorCreate(arr, arrSize);
 * int param_1 = peek(obj);
 * int param_2 = next(obj);
 * bool param_3 = hasNext(obj);
 * peekingIteratorFree(obj);
*/

