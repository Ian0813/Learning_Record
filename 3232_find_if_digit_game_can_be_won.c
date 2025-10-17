/*
 * =====================================================================================
 *
 *       Filename:  3232 find if digit game can be won.c
 *
 *    Description:  find if digit game can be won
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

typedef enum {false, true} bool;

#define IS_SINGLE_DIGIT(val) ((val < 10) ? true : false)

bool canAliceWin(int* nums, int numsSize) {

    int total = 0, single_digit_sum = 0;

    for (int i = 0; i < numsSize; i++) {
        total += nums[i];
        single_digit_sum += (IS_SINGLE_DIGIT(nums[i]) ? nums[i] : 0);
    }

    return (single_digit_sum == (total - single_digit_sum)) ? false : true; 
}

