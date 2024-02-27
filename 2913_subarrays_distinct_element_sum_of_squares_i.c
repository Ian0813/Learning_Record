/*
 * =====================================================================================
 *
 *       Filename:  2913_subarrays_distinct_element_sum_of_squares_i.c
 *
 *    Description:  Subarrays distinct element sum of squares  
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

int get_distinct(int *table, int *nums, int index, int size) {

    int count = 0; 
    int dup[TABLE_SIZE] = {0};

    memcpy(dup, table, sizeof(int) * TABLE_SIZE);

    for (int i = index; i < size; i++) {
        if (dup[nums[i]]) {
            dup[nums[i]] = 0; 
            count++;
        }
    }
    return count;
}

int sumCounts(int* nums, int numsSize){

    int table[TABLE_SIZE] = {0};
    int sum = 0, value = 0;

    for (int i = 0; i < numsSize; i++) {
        table[nums[i]] = 1;
    }

    for (int i = 0; i < numsSize; i++) {
        for (int j = i; j < numsSize; j++) {
            value = get_distinct(table, nums, i, j+1);
            sum = sum + value * value;
        }
    }
    return sum;
}

