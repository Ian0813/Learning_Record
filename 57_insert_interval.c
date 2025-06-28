/*
 * =====================================================================================
 *
 *       Filename:  57_insert_interval.c
 *
 *    Description:  insert interval
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

typedef enum {
    NO_MOVE = 0,
    DO_MOVE = 1
} movement_t;

static int get_insert_index(int **intervals, int head, int end, int *newInterval) {

    int middle = (head+end)/2;
    int rc = middle;

    if (head < end) {
        if (intervals[middle][E_INDEX] == newInterval[E_INDEX]) {
            rc = middle; 
        } else if (intervals[middle][E_INDEX] > newInterval[E_INDEX]) {
            rc = get_insert_index(intervals, head, middle, newInterval);
        } else if (intervals[middle][E_INDEX] < newInterval[E_INDEX]) {
            rc = get_insert_index(intervals, middle+1, end, newInterval);
        }
    }
    return rc;
}

static void place_item(int **intervals, int intervalsSize, int *newInterval, int **arr) {

    int index = 0, size = 0;

    if (!intervalsSize) {
        arr[intervalsSize] = newInterval;
    } else {
        if (intervals[0][E_INDEX] >= newInterval[E_INDEX]) {
            arr[size++] = newInterval;
            memcpy(&arr[size], intervals, sizeof(int *) * intervalsSize);
        } else if (intervals[intervalsSize-1][E_INDEX] <= newInterval[E_INDEX]) {
            arr[intervalsSize] = newInterval;
            memcpy(&arr[size], intervals, sizeof(int *) * intervalsSize);
        } else {
            index = get_insert_index(intervals, 0, intervalsSize, newInterval); 
            memcpy(&arr[size], &intervals[0], index * sizeof(int *));
            arr[index] = newInterval;
            memcpy(&arr[index+1], &intervals[index], (intervalsSize-index)*sizeof(int *));
        }
    }
    return;
}

static int **allocate_dimension(int rsize, int csize) {

    int **arr = NULL; 

    if (rsize) {
        arr = (int **) calloc(rsize, sizeof(int *));
    }

    if (csize) {
        for (int i = 0; i < rsize; i++) {
            arr[i] = (int *) calloc(UNIT_LEN, sizeof(int));
        }
    }
    return arr;
}

static int *allocate_colsize(int size) {

    int *arr = NULL; 

    if (size) {

        arr = (int *) calloc(size, sizeof(int));
        for (int i = 0; i < size; i++) {
            arr[i] = UNIT_LEN; 
        }
    }
    return arr;
}

static movement_t do_compact(int **arr, int arrSize, int **dup, int *dupSize) {

    movement_t move = NO_MOVE;

    for (int i = 0; i < arrSize-1; i++) {
        if (arr[i][E_INDEX] >= arr[i+1][S_INDEX]) {
            arr[i+1][S_INDEX] = arr[i][S_INDEX] > arr[i+1][S_INDEX] ? arr[i+1][S_INDEX] : arr[i][S_INDEX];
            arr[i+1][E_INDEX] = arr[i+1][E_INDEX];
            move = DO_MOVE;
        } else {
            dup[*dupSize] = arr[i];  
            *dupSize += 1;
        }                
    }

    dup[*dupSize] = arr[arrSize-1];
    *dupSize += 1;

    return move;
}

int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes) {

    int **result = NULL, **dup = NULL;
    int rindex = 0, dindex = 0;

    result = allocate_dimension(intervalsSize+1, 0);
    dup = allocate_dimension(intervalsSize+1, 0);
    place_item(intervals, intervalsSize, newInterval, result);
    rindex = intervalsSize + 1;

    while (do_compact(result, rindex, dup, &dindex)) {
        memset(result, 0, sizeof(int *) * rindex);                         
        memcpy(result, dup, dindex * sizeof(int *));
        rindex = dindex;
        memset(dup, 0, sizeof(int *) * dindex);
        dindex = 0;
    }

    *returnSize = rindex;
    *returnColumnSizes = allocate_colsize(rindex); 

    return result;
}
