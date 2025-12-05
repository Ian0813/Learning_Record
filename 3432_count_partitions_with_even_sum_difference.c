/*
 * =====================================================================================
 *
 *       Filename:  3432_count_partitions_with_even_sum_difference.c
 *
 *    Description:  count partitions with even sum difference
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

static int get_array_sum(int *nums, int numsSize) {

    int value = 0;

    for (int i = 0; i < numsSize; i++)
        value += nums[i];
    return value;
}

int countPartitions(int* nums, int numsSize) {

    int sum = 0, count = 0, temp = 0;

    sum = get_array_sum(nums, numsSize);

    for (int i = 0; i < numsSize - 1; i++) {

        sum -= nums[i];

        if (!(((temp + nums[i]) - sum)%2)) {
            count++;
        }
        temp += nums[i];
    }
    return count;
}

