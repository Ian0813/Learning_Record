/*
 * =====================================================================================
 *
 *       Filename:  2317_maximum_xor_after_operations.c
 *
 *    Description:  maximum xor after operations
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

#define BIT_COUNT_OF(type) (sizeof(type)*8)

static int get_range_xor(int *nums, int start, int end) {

    int result = 0;

    if (start < end) {

        result = nums[start];

        for (int i = start+1; i < end; i++) {
            result ^= nums[i]; 
        }
    }
    return result;
}

static int get_range_or(int *nums, int start, int end) {

    int result = 0;

    if (start < end) {

        result = nums[start];

        for (int i = start+1; i < end; i++) {
            result |= nums[i]; 
        }
    }
    return result;
}

int maximumXOR(int* nums, int numsSize) {

    int or_result = 0;

    if (numsSize) {
        or_result = get_range_xor(nums, 0, numsSize);
    }
    return or_result;
}
