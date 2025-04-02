/*
 * =====================================================================================
 *
 *       Filename:  2873_maximum_value_of_an_ordered_triplet_i.c
 *
 *    Description:  maximum value of an ordered triplet i
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

long long maximumTripletValue(int* nums, int numsSize) {

    long long maximum = 0LL, value = 0LL;

    for (int i = 0; i < (numsSize-2); i++) {
        for (int j = i+1; j < (numsSize-1); j++) {
            for (int k = j+1; k < numsSize; k++) {
                value = (nums[i]-nums[j]);
                value *= nums[k]; 
                maximum = value > maximum ? value : maximum;
            }
        }
    }
    return maximum;
}
