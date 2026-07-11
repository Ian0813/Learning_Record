/*
 * =====================================================================================
 *
 *       Filename:  1685_sum_of_absolute_differences_in_a_sorted_array.c
 *
 *    Description:  sum of absolute differences in a sorted array
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

typedef enum {
    PRE_SUM_INDEX = 0,
    POST_SUM_INDEX = 1,
    SUM_INDEX_LEN = 2
} sum_index_t;

static void get_diff_nums(int *nums, int numsSize, int *diff_nums, int base_index, int sum_collection[][SUM_INDEX_LEN]) {

    if (!nums || !numsSize || !diff_nums || (base_index < 0))
        return;

    int sum = 0;

    for (int i = 0; i < numsSize; i++) {
        diff_nums[i] = abs(nums[i]-nums[base_index]);
        sum += diff_nums[i];
        sum_collection[i][PRE_SUM_INDEX] = sum; 
    }

    for (int i = 0; i < numsSize; i++) {
        sum_collection[i][POST_SUM_INDEX] = sum - sum_collection[i][PRE_SUM_INDEX];
    }
    return;
}


int* getSumAbsoluteDifferences(int* nums, int numsSize, int* returnSize){

    int *diff_nums = NULL, *result = NULL, base_index = 0, diff_unit = 0;
    int sum_collection[numsSize][SUM_INDEX_LEN];

    memset(sum_collection, 0, sizeof(sum_collection));

    diff_nums = calloc(numsSize, sizeof(int));
    result = calloc(numsSize, sizeof(int));

    if (diff_nums)
        get_diff_nums(nums, numsSize, diff_nums, base_index, sum_collection);

    result[0] = sum_collection[0][POST_SUM_INDEX];

    for (int i = 1; i < numsSize; i++) {
        diff_unit = nums[i]-nums[base_index];
        result[i] = (sum_collection[i][POST_SUM_INDEX]-(((numsSize-1)-i) * diff_unit)) + \
                    (((diff_unit * (i-1))-(sum_collection[i][PRE_SUM_INDEX]-diff_unit)) + diff_unit);
    }

    *returnSize = numsSize;
    free(diff_nums);
    return result;
}
