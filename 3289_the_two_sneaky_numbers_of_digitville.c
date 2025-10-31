/*
 * =====================================================================================
 *
 *       Filename:  3289 the two sneaky numbers of digitville.c
 *
 *    Description:  the two sneaky numbers of digitville
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04.2) 11.4.0
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

#define TABLE_SIZE 101

#define FILL_WITH_NUMBER(r, index, num, size) while (size) {\
r[index++] = num;\
size--;\
}

static void counter(int *nums, int numsSize, int *table) {

    if (!table)
        return;

    for (int i = 0; i < numsSize; i++) {
        table[nums[i]]++;
    }

    return;
}    

int* getSneakyNumbers(int* nums, int numsSize, int* returnSize) {

    int table[TABLE_SIZE] = {0};
    int *result = NULL, len = 0, size = 0;

    result = (int *) calloc(numsSize, sizeof(int));
    counter(nums, numsSize, table);

    for (int i = 0; i < TABLE_SIZE; i++) {

        if (table[i] > 1) {
            size = table[i] - 1;   
            FILL_WITH_NUMBER(result, len, i, size);
        }
    }

    *returnSize = len;
    return result;
}
