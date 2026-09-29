/*
 * =====================================================================================
 *
 *       Filename:  950_reveal_cards_in_increasing_order.c
 *
 *    Description:  Reveal cards in increasing order  
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
 *
 *         Author:  Ian
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef enum {false, true} bool;

static void swap(int *v1, int *v2) {

    int temp = *v1;
    *v1 = *v2;
    *v2 = temp;
    return;
}

static void quick_sort(int *arr, int head, int end) {

    int front = head, last = head, tail = end-1;

    if (front < tail) {

        while (last < tail) {
            if (arr[head] > arr[tail]) {
                last++; 
                swap(&arr[last], &arr[tail]);
                continue;
            }
            tail--;
        }
        swap(&arr[head], &arr[last]);
        quick_sort(arr, head, last);
        quick_sort(arr, last+1, end);
    }
    return;
}

static int get_available(int *start, bool *array_flags, int asize) {

    int pos = 0, flag = 0;

    for (*start; *start < asize; *start = (*start + 1) % asize) {
        if (!array_flags[*start]) {
            pos = *start; 
            array_flags[*start] = true;
            break;
        }
    }

    *start = (*start + 1) % asize;

    for (*start; *start < asize; *start = (*start + 1) % asize) {
        if (!array_flags[*start]) {
            if (flag)
                break;
            flag = 1;
        }
    }
    return pos;
}

int* deckRevealedIncreasing(int* deck, int deckSize, int* returnSize) {

    int *result = NULL, count = 0, start = 0, pos = 0, index = 0;
    bool *array_flags = NULL;

    if (deckSize) {

        quick_sort(deck, 0, deckSize);
        count = deckSize;

        result = calloc(deckSize, sizeof(int));
        array_flags = calloc(deckSize, sizeof(bool));

        while (count > 1) {
            pos = get_available(&start, array_flags, deckSize);     
            result[pos] = deck[index];
            index++;
            count--;
        }

        for (int i = 0; i < deckSize; i++) {
            if (!array_flags[i]) {
                result[i] = deck[index];
                break;
            }
        }
        *returnSize = deckSize;
    }
    return result;
}
