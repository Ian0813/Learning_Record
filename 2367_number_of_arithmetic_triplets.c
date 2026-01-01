/*
 * =====================================================================================
 *
 *       Filename:  2367_number_of_arithmetic_triplets.c
 *
 *    Description:  number of arithmetic triplets
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

#define IS_SATISFY(val, diff) ((val) == (diff))
#define IS_TRIPLET(a, b, c) ((a) != (b) && (a) != (c) && (b) != (c))

int arithmeticTriplets(int* nums, int numsSize, int diff) {

    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        for (int j = i+1; j < numsSize; j++) {
            for (int k = j+1; k < numsSize; k++) {
                if (IS_SATISFY((nums[j]-nums[i]), diff) && IS_SATISFY((nums[k]-nums[j]), diff) && IS_TRIPLET(nums[i], nums[j], nums[k])) {
                    count++;
                }
            }
        }
    }

    return count;
}
