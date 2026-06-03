/*
 * =====================================================================================
 *
 *       Filename:  3940_limit_occurrences_in_sorted_array.c
 *
 *    Description:  limit occurrences in sorted array
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04.3) 11.4.0
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
int* limitOccurrences(int* nums, int numsSize, int k, int* returnSize) {

    int size = 0, last_value = 0, count = 0; 

    last_value = nums[0];
    count++;
    size++;

    for (int i = 1; i < (numsSize); i++) {

        if (last_value == nums[i]) {
            count++;
        } else if (last_value != nums[i]) {
            count = 1;
            last_value = nums[i];
        }

        if (count <= k) {
            nums[size++] = nums[i];
        }

    }

    *returnSize = size;
    return nums;
}
