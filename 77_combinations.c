/*
 * =====================================================================================
 *
 *       Filename:  77_combinations.c
 *
 *    Description:  combinations
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

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define COMBINE_LIST_LEN (500000)

typedef struct {
    int **lists;
    int *list_lens;
    int list_cursize;
    int list_size;
} combine_info;

static void combination_generator(int val, int n, int k, combine_info *obj, int *numbers, int nlen) {

    int flag = 0;

    if (val > n)
        return;

    if (nlen < k) {
        numbers[nlen] = val;
        nlen++;
        val++;

        if (nlen == k) {
            obj->lists[obj->list_cursize] = calloc(k, sizeof(int)); 
            memcpy(obj->lists[obj->list_cursize], numbers, sizeof(int) * k);
            obj->list_lens[obj->list_cursize] = k;
            obj->list_cursize++;
            nlen--;
            flag = 1;
        }
        combination_generator(val, n, k, obj, numbers, nlen);
    }

    if (val < n && !flag) {
        nlen--;
        combination_generator(val, n, k, obj, numbers, nlen);
    }
    return;
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes) {

    int *numbers = NULL;
    combine_info *obj = NULL;

    obj = calloc(1, sizeof(*obj));
    obj->lists = calloc(COMBINE_LIST_LEN, sizeof(int *));
    obj->list_lens = calloc(COMBINE_LIST_LEN, sizeof(int));

    numbers = calloc(k, sizeof(int));
    combination_generator(1, n, k, obj, numbers, 0);
    free(numbers);

    *returnSize = obj->list_cursize;
    *returnColumnSizes = obj->list_lens;
    return obj->lists;
}
