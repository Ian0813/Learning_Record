/*
 * =====================================================================================
 *
 *       Filename:  1470_shuffle_the_array.c
 *
 *    Description:  shuffle the array
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

static void do_shuffle(int *result, int *nums, int numsSize, int n) {

    int index = 0; 

    for (int i = 0, j = n; i < n; i++, j++) {
        result[index++] = nums[i];
        result[index++] = nums[j];
    }

    return;
}

int* shuffle(int* nums, int numsSize, int n, int* returnSize) {

    int *result = NULL;                

    if (numsSize) {
        result = (int *) calloc(numsSize, sizeof(*result));
        *returnSize = numsSize;
        do_shuffle(result, nums, numsSize, n);
    }
    return result;
}
