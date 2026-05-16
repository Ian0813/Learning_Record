/*
 * =====================================================================================
 *
 *       Filename:  2784 check if array is good.c
 *
 *    Description:  check if array is good
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

typedef enum {false, true} bool;

bool isGood(int* nums, int numsSize) {

    int *table = NULL, tindex = 0;

    if (numsSize < 2)
        return false;

    table = (int *) calloc(numsSize+1, sizeof(int));

    for (int i = 0; i < numsSize; i++) {

        if (nums[i] <= 0 || nums[i] > numsSize) {
            free(table);  
            return false;
        }

        table[nums[i]]++;

        if (nums[i] < (numsSize-1) && table[nums[i]] > 1) {
            free(table);
            return false;
        }

        if (nums[i] == (numsSize-1) && table[nums[i]] > 2) {
            free(table);
            return false;
        }
    }

    for (int i = 1; i <= numsSize; i++) {
        if (i < (numsSize-1) && table[i] != 1) {
            free(table);  
            return false;
        } else if (i == (numsSize-1) && table[i] != 2) {
            free(table); 
            return false;
        }
    }

    return true;
}
