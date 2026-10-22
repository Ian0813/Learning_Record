/*
 * =====================================================================================
 *
 *       Filename:  4083_minimum_deletions_to_make_array_sharp.c
 *
 *    Description:  4083 minimum deletions to make array sharp
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

int minDeletions(int* nums, int numsSize) {

    int count = 0;

    for (int index = 0; index < (numsSize-1); index++) {
        if (nums[index+1] == nums[index]) {
            count++;
        }
    }
    return count;
}
