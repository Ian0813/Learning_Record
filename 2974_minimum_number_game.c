/*
 * =====================================================================================
 *
 *       Filename:  2974 minimum number game.c
 *
 *    Description:  minimum number game
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

static void swap(int *v1, int *v2) {

    int temp = *v1;

    *v1 = *v2;
    *v2 = temp;

    return;
}

static void quick_sort(int *arr, int head, int end) {

    int last = head, tail = end;          

    if (head < end) {

        while (last < tail) {
            if (arr[head] > arr[tail]) {
                last++;
                swap(&arr[last], &arr[tail]);
                continue;
            }
            tail--;
        }

        swap(&arr[last], &arr[head]);
        quick_sort(arr, head, last-1);
        quick_sort(arr, last+1, end); 
    }

    return;
}

static void start_gaming(int *nums, int numsSize, int *result) {

    int index = 0;

    quick_sort(nums, 0, numsSize-1);

    for (int i = 0; i < numsSize; i += 2) {
        result[index++] = nums[i+1];
        result[index++] = nums[i];
    }

    return;
}

int* numberGame(int* nums, int numsSize, int* returnSize) {

    int *result = NULL;

    if (numsSize) {

        result = (int *) calloc(numsSize, sizeof(int));
        start_gaming(nums, numsSize, result);
        *returnSize = numsSize;
    }

    return result;
}

