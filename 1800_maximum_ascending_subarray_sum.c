/*
 * =====================================================================================
 *
 *       Filename:  1800_maximum_ascending_subarray_sum.c
 *
 *    Description:  maximum ascending subarray sum
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

int maxAscendingSum(int* nums, int numsSize) {

    int max = 0, last = 0, sum = 0;

    for (int i = 0; i < numsSize; i++) {
    
        if (nums[i] > last) {
            sum += nums[i];
        } else {
            sum = nums[i];
        }

        last = nums[i];

        if (sum > max) {
            max = sum;
        }
    }
    return max;
}
