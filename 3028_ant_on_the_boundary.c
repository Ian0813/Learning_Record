/*
 * =====================================================================================
 *
 *       Filename:  3028_ant_on_the_boundary.c
 *
 *    Description:  ant on the boundary
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

int returnToBoundaryCount(int* nums, int numsSize) {

    int positive = 0, negative = 0, return_count = 0;    

    for (int i = 0; i < numsSize; i++) {

        if (nums[i] > 0) {
            positive += nums[i];
        } else {
            negative += abs(nums[i]);
        }

        if (positive == negative) {
            return_count++;
            positive = negative = 0;
        }
    }

    return return_count;
}
