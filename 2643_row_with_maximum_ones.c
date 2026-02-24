/*
 * =====================================================================================
 *
 *       Filename:  2643_row_with_maximum_ones.c
 *
 *    Description:  row with maximum ones
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
#include <limits.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define RESULT_LEN 2
#define IS_ONE(val) ((val) == 1)

enum {
    ROW_INDEX = 0,
    NUM_INDEX = 1,
};

static void get_result(int **mat, int row, int col, int *result) {

    int max_row = 0, max = 0, count = 0;
     
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            count = IS_ONE(mat[i][j]) ? (count + 1) : count; 
        }

        if (count > max) {
            max = count; 
            max_row = i;
        }

        if (max == col)
            break;

        count = 0;
    }

    result[ROW_INDEX] = max_row;
    result[NUM_INDEX] = max;
    return; 
}

int* rowAndMaximumOnes(int** mat, int matSize, int* matColSize, int* returnSize) {

    int *result = NULL;

    result = (int *) calloc(RESULT_LEN, sizeof(int));
    get_result(mat, matSize, *matColSize, result);

    *returnSize = RESULT_LEN;

    return result;
}

