/*
 * =====================================================================================
 *
 *       Filename:  2016_maximum_difference_between_increasing_elements.c
 *
 *    Description:  maximum difference between increasing elements
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

static int get_maxdiff(int *nums, int numsSize) {

    int max = -1, min = nums[0];

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > min) {
            if (max < (nums[i]-min)) {
                max = nums[i]-min;  
            }
        }
        min = min > nums[i] ? nums[i] : min;
    }
    return max;
}

int maximumDifference(int* nums, int numsSize) {

    int max_diff = 0;

    max_diff = get_maxdiff(nums, numsSize);

    return max_diff;
}
