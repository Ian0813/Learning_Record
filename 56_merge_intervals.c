/*
 * =====================================================================================
 *
 *       Filename:  56_merge_intervals.c
 *
 *    Description:  merge intervals
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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define UNIT_LEN 2

enum {
    S_INDEX = 0,
    E_INDEX = 1
};

enum {
    NON_OPERATION = 0,
    DO_OPERATION = 1
};

static void merge_operation(int **arr, int head, int middle, int end) {

    int a1Size = (middle-head)+1, a2Size = (end-middle);
    int a1[a1Size][UNIT_LEN], a2[a2Size][UNIT_LEN];
    int a1_index = 0, a2_index = 0, index = head;

    for (int i = a1_index; i < a1Size; i++) {
        memcpy(a1[i], arr[head+i], UNIT_LEN * sizeof(int));
    }

    for (int i = a2_index; i < a2Size; i++) {
        memcpy(a2[i], arr[middle+i+1], UNIT_LEN * sizeof(int));
    }

    while (a1_index < a1Size && a2_index < a2Size) {
        if (a1[a1_index][E_INDEX] < a2[a2_index][E_INDEX]) {
            memcpy(arr[index++], a1[a1_index++], sizeof(int)*UNIT_LEN);
        } else {
            memcpy(arr[index++], a2[a2_index++], sizeof(int)*UNIT_LEN);
        }
    }

    while (a1_index < a1Size) {
        memcpy(arr[index++], a1[a1_index++], UNIT_LEN*sizeof(int));
    }

    while (a2_index < a2Size) {
        memcpy(arr[index++], a2[a2_index++], UNIT_LEN*sizeof(int));
    }

    return;
}

static void merge_sort(int **arr, int head, int end) {

    int middle = (head+end)/2;

    if (head < end) {
        merge_sort(arr, head, middle);
        merge_sort(arr, middle+1, end);
        merge_operation(arr, head, middle, end);
    }

    return;
}

static int **alloc_result(int len) {

    int **result = NULL;

    result = (int **) calloc(len, sizeof(int *));
    for (int i = 0; i < len; i++) {
        result[i] = (int *) calloc(UNIT_LEN, sizeof(int));
    }

    return result;
}

static int compact(int **intervals, int intervalsSize, int *return_size, int **result) {

    int cur_unit[UNIT_LEN] = {0};
    int again = NON_OPERATION;

    memcpy(&cur_unit, intervals[0], sizeof(int)*UNIT_LEN);

    for (int i = 1; i < intervalsSize; i++) {
        if (cur_unit[E_INDEX] >= intervals[i][S_INDEX]) {
            cur_unit[S_INDEX] = (cur_unit[S_INDEX] > intervals[i][S_INDEX]) ? intervals[i][S_INDEX] : cur_unit[S_INDEX];
            cur_unit[E_INDEX] = intervals[i][E_INDEX];
            again = DO_OPERATION;
        } else {
            memcpy(result[*return_size], &cur_unit, UNIT_LEN*sizeof(int));
            *return_size += 1;
            memcpy(&cur_unit, intervals[i], sizeof(int)*UNIT_LEN);
        }
    }

    memcpy(result[*return_size], &cur_unit, UNIT_LEN*sizeof(int));
    *return_size += 1;

    return again;
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {

    int **result = NULL, action = DO_OPERATION;

    *returnSize = 0;
    result = alloc_result(intervalsSize);

    merge_sort(intervals, 0, intervalsSize-1);
    while (action) {
        *returnSize = 0;
        action = compact(intervals, intervalsSize, returnSize, result);
        memcpy(intervals, result, (sizeof(int)*UNIT_LEN) * (*returnSize));
        intervalsSize = *returnSize;
    }
    *returnColumnSizes = intervalsColSize;

    return result;
}
