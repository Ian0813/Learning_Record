/*
 * =====================================================================================
 *
 *       Filename:  3069_distribute_elements_into_two_arrays_i.c
 *
 *    Description:  distribute elements into two arrays i
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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
static inline void zero_out_array(int *arr, int size) {
    memset(arr, 0, sizeof(int)*size);
    return;
}

int* resultArray(int* nums, int numsSize, int* returnSize) {

    int arr1[numsSize], arr2[numsSize];
    int a1index = 0, a2index = 0, length = numsSize-2, step = 2;
    int *result = NULL;

    if (numsSize) {
        result = (int *) calloc(numsSize, sizeof(int));
        zero_out_array(arr1, numsSize);
        zero_out_array(arr2, numsSize);

        arr1[a1index++] = nums[0];
        arr2[a2index++] = nums[1];

        do {
            if (arr1[a1index-1] > arr2[a2index-1]) {
                arr1[a1index++] = nums[step++];
            } else {
                arr2[a2index++] = nums[step++];
            }
            length--;
        } while (length);
        memcpy(result, arr1, sizeof(int)*a1index);
        memcpy(result+a1index, arr2, sizeof(int)*a2index);
    }

    *returnSize = numsSize;
    return result;
}
