/*
 * =====================================================================================
 *
 *       Filename:  3046_split_the_array.c
 *
 *    Description:  Split The Array 
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

#define TABLE_SIZE 101

void fill_table(int *nums, int numsSize, int *table) {

    for (int i = 0; i < numsSize; i++) {
        table[nums[i]]++;
    }
    return;
}

bool isPossibleToSplit(int* nums, int numsSize) {

    int table[TABLE_SIZE] = {0};
    int rc = true;

    fill_table(nums, numsSize, table);

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] > 2) {
            rc = false;
            break;
        }
    }

    return rc;
}
