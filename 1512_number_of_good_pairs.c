/*
 * =====================================================================================
 *
 *       Filename:  1512_number_of_good_pairs.c
 *
 *    Description:  Number of good pairs  
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

int numIdenticalPairs(int* nums, int numsSize) {

    int count = 0;

    for (int i = 0; i < (numsSize-1); i++) {
        for (int j = i+1; j < numsSize; j++) {
            if (nums[i] == nums[j]) {
                count++; 
            }
        }
    }
    return count;
}
