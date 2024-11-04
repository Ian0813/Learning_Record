/*
 * =====================================================================================
 *
 *       Filename:  1337 the k weakest rows in a matrix.c
 *
 *    Description:  the k weakest rows in a matrix
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

#define MAX_ROW_SIZE 100

typedef struct {
  int soliders;  
  int index;
} row_info;

static void swap(row_info *info1, row_info *info2) {

    row_info temp = {.soliders = info1->soliders, .index = info1->index};
    memcpy(info1, info2, sizeof(row_info));
    memcpy(info2, &temp, sizeof(row_info));
    return;
}

static bool compare(row_info info1, row_info info2) {

    bool rc = true;

    if (info1.soliders < info2.soliders || (info1.soliders == info2.soliders && info1.index < info2.index)) {
        rc = false;
    }
    return rc;
}

static void quick_sort(row_info *arr, int head, int end, bool (*compare)(row_info info1, row_info info2)) {

    int front = head, pivot = head, tail = end-1;

    if (front < tail) {

        while (pivot < tail) {
            if (compare(arr[head], arr[tail])) {
                pivot++;
                swap(&arr[pivot], &arr[tail]);
                continue;
            }
            tail--;
        }

        swap(&arr[head], &arr[pivot]);
        quick_sort(arr, head, pivot, compare);
        quick_sort(arr, pivot+1, end, compare);
    }
    return;
}

static void collect_row_info(row_info *arr, int **mat, int matSize, int *matColSize) {

    int index = 0;
    int count = 0;

    for (int i = 0; i < matSize; i++) {
        for (int j = 0; j < matColSize[i]; j++) {
            if (mat[i][j]) {
                count++;
                continue;
            }
            break;
        }
        arr[i].soliders = count;
        arr[i].index = i;
        count = 0;
    }
    return;
}

int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize) {

    row_info row_arr[MAX_ROW_SIZE] = {0};
    int *result = (int *) calloc(k, sizeof(int)); 

    collect_row_info(row_arr, mat, matSize, matColSize);

#if  0
    for (int i = 0; i < matSize; i++) {
        printf("[%s] soliders:%d, index: %d\n", __func__, row_arr[i].soliders, row_arr[i].index);
    }
#endif

    quick_sort(row_arr, 0, matSize, compare);

#if  0
    for (int i = 0; i < matSize; i++) {
        printf("[%s] soliders:%d, index: %d\n", __func__, row_arr[i].soliders, row_arr[i].index);
    }
#endif

    for (int i = 0; i < k; i++) {
        result[i] = row_arr[i].index;
    }
    *returnSize = k;
    return result; 
}
