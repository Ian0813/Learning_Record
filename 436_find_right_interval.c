/*
 * =====================================================================================
 *
 *       Filename:  436_find_right_interval.c
 *
 *    Description:  find right interval
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04.2) 11.4.0
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

enum {
    S_INDEX = 0,
    E_INDEX = 1
};

typedef struct collection {
    int **intervals;
    int intervalsSize;
    int *indices;
    int *result;
} collection;

static void swap_ptr(int **p1, int **p2) {

    int *temp = *p1;

    *p1 = *p2;
    *p2 = temp;

    return;
}

static void swap(int *v1, int *v2) {

    int temp = *v1;

    *v1 = *v2;
    *v2 = temp;

    return;
}

static void collection_init(collection *col, int **arr, int size) {

    if (!col || !arr)
        return;

    col->intervals = arr;
    col->intervalsSize = size;
    col->indices = (int *) calloc(size, sizeof(int)); 
    col->result = (int *) calloc(size, sizeof(int)); 

    for (int i = 0; i < size; i++) {
        col->indices[i] = i;
    }
    
    return;
}

static void collection_free(collection *col) {

    if (!col || col->indices)
        return;

    free(col->indices);

    return;
}

static void quick_sort(int **arr, int head, int end, int *indices) {

    int last = head, tail = end;

    if (head < tail) {

        while (last < tail) {

            if (arr[head][S_INDEX] > arr[tail][S_INDEX]) {
                last++;
                swap_ptr(&arr[last], &arr[tail]);
                swap(&indices[last], &indices[tail]);
                continue;
            }
            tail--;
        }

        swap_ptr(&arr[head], &arr[last]);
        swap(&indices[head], &indices[last]);
        quick_sort(arr, head, last-1, indices);
        quick_sort(arr, last+1, end, indices);
    }    

    return;
}

static int binary_search(collection *col, int low, int high, int target) {

    int middle = (high+low) / 2;
    int rc = middle;

    if (low < high) {
        if (col->intervals[middle][S_INDEX] == target) {
            rc = middle;
        } else if (col->intervals[middle][S_INDEX] > target) {
            rc = binary_search(col, low, middle, target);    
        } else if (col->intervals[middle][S_INDEX] < target) {
            rc = binary_search(col, middle+1, high, target);
        }
    }

    return rc;
}    

static void mark_right_interval(collection *col) {

    int index = 0;

    if (col) {

        for (int i = 0; i < col->intervalsSize; i++) {

            index = binary_search(col, 0, col->intervalsSize, col->intervals[i][E_INDEX]); 

            if (index >= col->intervalsSize) {
                col->result[col->indices[i]] = -1; 
            } else if (col->intervals[i][E_INDEX] > col->intervals[index][S_INDEX]) {
                col->result[col->indices[i]] = -1; 
            } else {
                col->result[col->indices[i]] = col->indices[index];
            }
        }
    }

    return;
}

int* findRightInterval(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize) {

    collection interval_info = {0};
    int *result = NULL;

    collection_init(&interval_info, intervals, intervalsSize);

    quick_sort(interval_info.intervals, 0, intervalsSize-1, interval_info.indices);

    mark_right_interval(&interval_info);
    result = interval_info.result;

    *returnSize = intervalsSize;
    collection_free(&interval_info);
    
    return result;
}
