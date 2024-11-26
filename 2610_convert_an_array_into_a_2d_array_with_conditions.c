/*
 * =====================================================================================
 *
 *       Filename:  2610_convert_an_array_into_a_2d_array_with_conditions.c
 *
 *    Description:  convert an array into a 2d array with conditions
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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

typedef enum {false, true} bool;

#define MAX_ROWS 200
#define TABLE_SIZE 201

static void fill_table(int *table, int *nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        table[nums[i]]++;
    }
    return;
}

static bool get_array(int **result, int *table, int *column_sizes) {

    bool rc = false;
    int temp[TABLE_SIZE] = {0};
    int index = 0;

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i]) {
            table[i]--;
            temp[index++] = i;
            rc = true;
        }
    }

    if (rc) {
        *result = (int *) calloc(index, sizeof(int)); 
        memcpy(*result, temp, sizeof(int) * index);
        (*column_sizes) = index;
    }
    return rc; 
}

static void array_collect(int **result, int *rindex, int *table, int *column_sizes) {

    while (get_array(&result[*rindex], table, &column_sizes[*rindex])) {
        *rindex += 1;
    }
    return;
}

int** findMatrix(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {

    int **result = NULL;
    int rindex = 0, table[TABLE_SIZE] = {0};

    *returnColumnSizes = (int *) calloc(MAX_ROWS, sizeof(int));
    result = (int **) calloc(MAX_ROWS, sizeof(int *));

    fill_table(table, nums, numsSize);
    array_collect(result, &rindex, table, *returnColumnSizes);
    *returnSize = rindex;
    return result;
}
