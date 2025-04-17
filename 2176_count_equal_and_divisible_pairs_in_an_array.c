/*
 * =====================================================================================
 *
 *       Filename:  2176_count_equal_and_divisible_pairs_in_an_array.c
 *
 *    Description:  count equal and divisible pairs in an array
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

#define IS_EQUAL(v1, v2) ((v1) == (v2))
#define IS_DIVISIBLE(v1, v2) (!((v1)%v2))

int countPairs(int* nums, int numsSize, int k) {

    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        for (int j = i+1; j < numsSize; j++) {
            if (IS_EQUAL(nums[i], nums[j]) && IS_DIVISIBLE((i*j), k))
                count++;
        }
    }
    return count;
}
