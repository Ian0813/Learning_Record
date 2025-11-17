/*
 * =====================================================================================
 *
 *       Filename:  2656_maximum_sum_with_exactly_k_elements.c
 *
 *    Description:  maximum sum with exactly k elements
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
#include <stdint.h>
#include <limits.h>
#include <ctype.h>

static int find_maximum(int *nums, int numsSize) {

    int max = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] > max) max = nums[i];
    }
    return max;
}

int maximizeSum(int* nums, int numsSize, int k) {

    int max_value = 0;

    max_value = find_maximum(nums, numsSize);
    max_value *= k;
    max_value += (((k-1) * k)/2);

    return max_value;
}
