/*
 * =====================================================================================
 *
 *       Filename:  2670_find_the_distinct_difference_array.c
 *
 *    Description:  find the distinct difference array
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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define TABLE_SIZE 51 

static void count_distinct(int *t, int tsize, int *nums, int numsSize, int **counts) {

    int table[TABLE_SIZE] = {0}, total_distinct = 0;

    if (tsize != TABLE_SIZE) {
        fprintf(stderr, "[%s] table size is not correct, please check the passed tsize %d\n", __func__, tsize);
        return;
    }

    for (int i = 0; i < numsSize; i++) {
        if (!table[nums[i]])
            total_distinct++; 
        table[nums[i]]++;
    }

    *counts = calloc(numsSize, sizeof(int));

    if (!counts)
        return;

    (*counts)[numsSize-1] = total_distinct;   
    memcpy(t, table, sizeof(table));

    for (int i = numsSize-1; i > 0; i--) {
        table[nums[i]]--;

        if (!table[nums[i]])
            total_distinct--;
        (*counts)[i-1] = total_distinct;
    }

    return;
}

int* distinctDifferenceArray(int* nums, int numsSize, int* returnSize) {

    int *counts = NULL, *result = NULL, remove_count = 0;
    int table[TABLE_SIZE] = {0}, total_distinct = 0;

    *returnSize = 0;
    count_distinct(table, TABLE_SIZE, nums, numsSize, &counts);

    if (counts) {
        total_distinct = counts[numsSize-1];
        result = calloc(numsSize, sizeof(int));
        for (int i = 0; i < numsSize-1; i++) {

            table[nums[i]]--;

            if (!table[nums[i]])
                remove_count++;
            result[i] = counts[i] - (total_distinct - remove_count);
        }
        result[numsSize-1] = total_distinct; 
        *returnSize = numsSize;
        free(counts);
    }
    return result;
}
