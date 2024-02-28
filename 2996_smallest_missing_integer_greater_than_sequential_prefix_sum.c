/*
 * =====================================================================================
 *
 *       Filename:  2996_smallest_missing_integer_greater_than_sequential_prefix_sum.c
 *
 *    Description:  Smallest missing integer greater than sequential prefix sum 
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

#define TABLE_SIZE 2501

void fill_table(int *table, int *nums, int size) {

    for (int i = 0; i < size; i++) {
        table[nums[i]] = 1;
    }
    return;
}

int missingInteger(int* nums, int numsSize) {

    int pre_index = 0, pre_sum = 0, miss = 0, flag = 0;
    int table[TABLE_SIZE];

    memset(table, 0, sizeof(int) * TABLE_SIZE);

    for (int i = pre_index; i < (numsSize-1); i++) {
        if (nums[i]+1 == nums[i+1]) {
            pre_index = i+1; 
        } else {
            break;
		}
    }

    for (int i = 0; i < (pre_index+1); i++) {
        pre_sum += nums[i];
    }

    fill_table(table, nums, numsSize);
    miss = pre_sum;

    while (!flag) {
        if (table[miss]) {
            miss++;
        } else {
            flag = 1;  
        }
    }

    return miss; 
}

