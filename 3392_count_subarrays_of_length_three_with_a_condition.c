/*
 * =====================================================================================
 *
 *       Filename:  3392_count_subarrays_of_length_three_with_a_condition.c
 *
 *    Description:  count subarrays of length three with a condition
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
#include <stdbool.h>

static bool check_condition(int *nums) {

    double value = (nums[1] * 1.0F) / 2.0F;

    if ((nums[0]+nums[2])*1.0F == (value)) {
        return true;
    }
    return false;
}

int countSubarrays(int* nums, int numsSize) {

    int count = 0;

    for (int i = 0; i < numsSize-2; i++) {
        count += check_condition(&nums[i]);
    }
    return count;
}
