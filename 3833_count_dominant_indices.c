/*
 * =====================================================================================
 *
 *       Filename:  3833_count_dominant_indices.c
 *
 *    Description:  count dominant indices
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
#include <stdbool.h>

static bool create_average_list(int *nums, int numsSize, int *average_nums) {

    int sum = 0;

    if (!nums || !average_nums)
        return false;

    for (int i = numsSize-1; i > 0; i--) {
        sum += nums[i];
        average_nums[i-1] = (sum/(numsSize-i));
    }
    return true;
}

int dominantIndices(int* nums, int numsSize) {

    int *average_nums = NULL, dominant_count = 0;

    average_nums = calloc(numsSize-1, sizeof(int));

    create_average_list(nums, numsSize, average_nums);

    for (int i = 0; i < numsSize-1; i++) {
        if (nums[i] > average_nums[i])
            dominant_count++;
    }
    return dominant_count;
}
