/*
 * =====================================================================================
 *
 *       Filename:  3880_minimum_absolute_difference_between_two_values.c
 *
 *    Description:  minimum absolute difference between two values
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
#include <limits.h>

int minAbsoluteDifference(int* nums, int numsSize) {

    int diff = 0, mini = INT_MAX;

    for (int i = 0; i < numsSize-1; i++) {

        if (nums[i] != 1 && nums[i] != 2)
            continue;   
        for (int j = i + 1; j < numsSize; j++) {

            diff = abs(i-j);

            if (nums[i] == 1 && nums[j] == 2)
                mini = mini > diff ? diff : mini;
            else if (nums[j] == 1 && nums[i] == 2) 
                mini = mini > diff ? diff : mini;
        }
    }
    return mini == INT_MAX ? -1 : mini;
}
