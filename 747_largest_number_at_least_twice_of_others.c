/*
 * =====================================================================================
 *
 *       Filename:  747_largest_number_at_least_twice_of_others.c
 *
 *    Description:  largest number at least twice of others
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

typedef enum {false, true} bool;

struct array_info {
    int *arr;
    int arrsSize;
    int *tracker;
};

static void swap(int *v1, int *v2) {

    int temp = *v1;       

    *v1 = *v2;
    *v2 = temp;

    return;
}

static void quick_sort(int *arr, int head, int end, int *tracker) {

    int last = head, tail = end;

    if (head < end) {

        while (last < tail) {
            if (arr[head] < arr[tail]) {
                last++;
                swap(&arr[last], &arr[tail]);
                swap(&tracker[last], &tracker[tail]);
                continue;
            }
            tail--;
        }

        swap(&arr[head], &arr[last]);
        swap(&tracker[head], &tracker[last]);
        quick_sort(arr, head, last-1, tracker);
        quick_sort(arr, last+1, end, tracker);
    }

    return;
}

int dominantIndex(int* nums, int numsSize) {

    struct array_info arr_info = {0};
    int rc = -1;

    arr_info.arr = nums; 
    arr_info.arrsSize = numsSize;
    arr_info.tracker = (int *) calloc(numsSize, sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        arr_info.tracker[i] = i;
    }

    quick_sort(arr_info.arr, 0, arr_info.arrsSize - 1, arr_info.tracker);

    if (arr_info.arr[0] >= (arr_info.arr[1] * 2)) {
        rc = arr_info.tracker[0];
    }

    free(arr_info.tracker);

    return rc; 
}
