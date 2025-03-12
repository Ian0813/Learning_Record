/*
 * =====================================================================================
 *
 *       Filename:  2529_maximum_count_of_positive_integer_and_negative_integer.c
 *
 *    Description:  maximum count of positive integer and negative integer
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

#define INCREASE_COUNT(val, neg, pos) if (val>0) pos++; else if (val<0) neg++;

int maximumCount(int* nums, int numsSize) {

    int neg_count = 0, pos_count = 0;

    for (int i = 0, j = numsSize-1; i <= j; i++, j--) {

        INCREASE_COUNT(nums[i], neg_count, pos_count);
        if (i == j)
            continue;
        INCREASE_COUNT(nums[j], neg_count, pos_count);
    }
    return pos_count > neg_count ? pos_count : neg_count;
}
