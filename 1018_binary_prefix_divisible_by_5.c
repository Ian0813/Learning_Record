/*
 * =====================================================================================
 *
 *       Filename:  1018_binary_prefix_divisible_by_5.c
 *
 *    Description:  binary prefix divisible by 5
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

typedef enum {false, true} bool;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

static void calculate(bool *result, int *nums, int numsSize) {

    int value = 0;

    for (int i = 0; i < numsSize; i++) {

        if (value)
            value <<= 1;

        value |= nums[i];

        if (!(value%5)) {
            result[i] = true;
        } else {
            result[i] = false;
        }
        value %= 5;
    }
    return;
}

bool* prefixesDivBy5(int* nums, int numsSize, int* returnSize) {

    bool *result = NULL;

    if (numsSize) {
        result = (bool *) calloc(numsSize, sizeof(*result));
        calculate(result, nums, numsSize);
    }

    *returnSize = numsSize;
    return result;
}
