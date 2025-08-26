/*
 * =====================================================================================
 *
 *       Filename:  3550_smallest_index_with_digit_sum_equal_to_index.c
 *
 *    Description:  smallest index with digit sum equal to index
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

static int digit_sum(int val) {

    int sum = 0;

    while (val) {
        sum += (val % 10);
        val /= 10;
    }

    return sum;
}

int smallestIndex(int* nums, int numsSize) {

    int index = -1; 

    for (int i = 0; i < numsSize; i++) {
        if (i == digit_sum(nums[i])) {
            index = i;
            break;
        }
    }

    return index;
}
