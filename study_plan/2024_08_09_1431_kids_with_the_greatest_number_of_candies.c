/*
 * =====================================================================================
 *
 *       Filename:  2024_08_09_1431_kids_with_the_greatest_number_of_candies.c
 *
 *    Description:  kids with the greatest number of candies  
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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef enum {false, true} bool;

bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {

    int max = 0;
    bool *result = (bool *) calloc(candiesSize, sizeof(bool));
    int index = 0;

    if (candiesSize) {
        for (int i = 0; i < candiesSize; i++) {
            if (candies[i] > max) {
                max = candies[i];
            }
        }

        for (int i = 0; i < candiesSize; i++) {
            if (candies[i]+extraCandies >= max) {
                result[i] = true; 
            } else {
                result[i] = false;
            }
        }
    }
    *returnSize = candiesSize;
    return result;
}



