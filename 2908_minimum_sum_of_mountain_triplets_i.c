/*
 * =====================================================================================
 *
 *       Filename:  2908_minimum_sum_of_mountain_triplets_i.c
 *
 *    Description:  minimum sum of mountain triplets i
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

int minimumSum(int* nums, int numsSize) {

    int value = 0, minimum = INT_MAX;

    for (int i = 0; i < numsSize-2; i++) {
        for (int j = i+1; j < numsSize-1; j++) {
            for (int k = j+1; k < numsSize; k++) {
                if (nums[i] < nums[j] && nums[k] < nums[j]) {
                    value = nums[i]+nums[j]+nums[k];
                    minimum = value < minimum ? value : minimum;
                }
            }
        }
    }
    return minimum == INT_MAX ? -1 : minimum;
}
