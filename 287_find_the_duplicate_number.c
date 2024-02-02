/*
 * =====================================================================================
 *
 *       Filename:  287_find_the_duplicate_number.c
 *
 *    Description:  Find the duplicate number  
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

int findDuplicate(int* nums, int numsSize) {

    int bound = numsSize;
    int dup = 0;

    for (int i = 0; i < numsSize; i++) {
        nums[nums[i]%bound] += bound;
    }

    for (int i = 1; i < numsSize; i++) {
        if ((nums[i]/bound) >= 2) {
            dup = i;
        }
    }

    for (int i = 0; i < numsSize; i++) {
        nums[i] = nums[i]%bound;
    }

    return dup;
}
