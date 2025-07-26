/*
 * =====================================================================================
 *
 *       Filename:  3487_maximum_unique_subarray_sum_after_deletion.c
 *
 *    Description:  maximum unique subarray sum after deletion
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
#include <limits.h>

typedef enum {false, true} bool;

#define TABLE_SIZE 101

static int get_subsum(int *nums, int numsSize) {

    int table[TABLE_SIZE] = {0};
    int subsum = 0;

    for (int i = 0; i < numsSize; i++) {

        if (nums[i] <= 0) {
            continue;
        }

        if (table[nums[i]])
            continue;

        subsum += nums[i];
        table[nums[i]] = true;
    }

    return subsum;
}

static int check_positive(int *nums, int numsSize) {

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] >= 0)
            return true;
    }
    return false;
}

static int get_maximum_item(int *nums, int numsSize) {

    int maximum = INT_MIN;

    for (int i = 0; i < numsSize; i++) {
        if (maximum < nums[i]) {
            maximum = nums[i];
        }
    }
    return maximum;
}

int maxSum(int* nums, int numsSize) {

    int result = 0;
    int flag = 0;

    flag = check_positive(nums, numsSize);

    if (!flag) {
        result = get_maximum_item(nums, numsSize);
    } else {
        result = get_subsum(nums, numsSize);
    }
    return result;
}
