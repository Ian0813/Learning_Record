/*
 * =====================================================================================
 *
 *       Filename:  3300 minimum element after replacement with digit sum.c
 *
 *    Description:  minimum element after replacement with digit sum
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

static int get_digits_sum(int value) {

    int sum = 0;

    while (value) {
        sum += (value%10);
        value /= 10;
    }

    return sum;
}

int minElement(int* nums, int numsSize) {

    int minimum = INT_MAX, value = 0;

    for (int i = 0; i < numsSize; i++) {
        value = get_digits_sum(nums[i]);
        minimum = minimum > value ? value : minimum; 
    }
    return minimum;
}
