/*
 * =====================================================================================
 *
 *       Filename:  2475_number_of_unequal_triplets_in_array.c
 *
 *    Description:  number of unequal triplets in array
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

#define IS_TRIPLET(a, b, c) (((a) != (b)) && ((a)!= (c)) && ((b) != (c)))

int unequalTriplets(int* nums, int numsSize) {

    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            for (int k = j + 1; k < numsSize; k++) {
                count = IS_TRIPLET(nums[i], nums[j], nums[k]) ? (count + 1) : count;
            }
        }
    }
    return count;
}
