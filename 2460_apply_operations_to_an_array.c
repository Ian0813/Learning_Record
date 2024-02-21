/*
 * =====================================================================================
 *
 *       Filename:  2460_apply_operations_to_an_array.c
 *
 *    Description:  Apply operations to an array
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
int* applyOperations(int* nums, int numsSize, int* returnSize) {

    int *result = (int *) malloc(sizeof(int) * numsSize);
    int index = 0, zero_count = 0;

    memset(result, 0, sizeof(int) * numsSize);

    for (int i = 0; i < (numsSize-1); i++) {

        if (!nums[i]) {
            continue;
        } else if (nums[i] == nums[i+1]) {
            result[index++] = nums[i] * 2;
            nums[i+1] = 0;
        } else if (nums[i] != 0) {
            result[index++] = nums[i];
        }
    }

    memset(result+index, 0, sizeof(int) * (numsSize-index));
    *returnSize = numsSize; 
    return result;
}
