/*
 * =====================================================================================
 *
 *       Filename:  260_single_number_iii.c
 *
 *    Description:  single number iii
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

#define RESULT_SIZE 2

enum {
    GROUP_ONE = 0,
    GROUP_TWO = 1
};

int xor_range(int *nums, int head, int end) {

    int value = 0;

    for (head; head < end; head++) {
        value ^= nums[head];
    }
    return value;
}


int* singleNumber(int* nums, int numsSize, int* returnSize) {

    int xor_all = 0;
    int differ = 0;
    int *result = NULL;

    if (numsSize) {

        result = (int *) calloc(RESULT_SIZE, sizeof(int)); 

        xor_all = xor_range(nums, 0, numsSize);

        differ = xor_all & -((unsigned int) xor_all);

        for (int i = 0; i < numsSize; i++) {
            if (nums[i] & differ) {
                result[GROUP_ONE] ^= nums[i];
            } else {
                result[GROUP_TWO] ^= nums[i];
            }
        }
    }
    *returnSize = RESULT_SIZE;
    return result;
}
