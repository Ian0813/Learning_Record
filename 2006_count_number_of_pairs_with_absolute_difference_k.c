/*
 * =====================================================================================
 *
 *       Filename:  2006_count_number_of_pairs_with_absolute_difference_k.c
 *
 *    Description:  count number of pairs with absolute difference k
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

int countKDifference(int* nums, int numsSize, int k) {
    int count = 0;

    for (int i = 0; i < numsSize-1; i++) {
        for (int j = i+1; j < numsSize; j++) {
            if (nums[j] == (nums[i]+k) || nums[j] == (nums[i]-k))
                count++; 
        }
    }
    return count;
}
