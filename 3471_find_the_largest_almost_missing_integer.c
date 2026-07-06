/*
 * =====================================================================================
 *
 *       Filename:  3471_find_the_largest_almost_missing_integer.c
 *
 *    Description:  find the largest almost missing integer
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

#define TABLE_SIZE 51

static void count_occurrence(int *nums, int numsSize, int k, int *table) {

    bool flags[TABLE_SIZE] = {false};  

    for (int i = 0; i < numsSize; i++) {
        if ((i+(k-1)) < numsSize) {
            for (int j = i; j < (i+k); j++) {
                if (!flags[nums[j]])
                    table[nums[j]]++;     
                flags[nums[j]] = true; 
            }
            memset(flags, false, sizeof(flags));
            continue;
        }
        break;
    }
    return;
}

int largestInteger(int* nums, int numsSize, int k) {

    int result = -1, count_table[TABLE_SIZE] = {0};

    count_occurrence(nums, numsSize, k, count_table);

    for (int i = TABLE_SIZE-1; i >= 0; i--) {
        if (count_table[i] && count_table[i] == 1) {
            result = i;
            break; 
        }
    }
    return result;
}
