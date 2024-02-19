/*
 * =====================================================================================
 *
 *       Filename:  283_move_zeroes.c
 *
 *    Description:  Move zeros
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

void moveZeroes(int* nums, int numsSize) {

    int index = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i]) {
            nums[index++] = nums[i];
        }
    }

    memset(nums+index, 0, (numsSize - index) * sizeof(int));

    return;
}
