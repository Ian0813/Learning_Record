/*
 * =====================================================================================
 *
 *       Filename:  2373 largest local values in a matrix.c
 *
 *    Description:  largest local values in a matrix
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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


static int **matrix_allocate(int row, int col) {

    int **ptr = NULL;

    ptr = (int **) calloc(row, sizeof(int *));

    for (int i = 0; i < row; i++) {
        ptr[i] = (int *) calloc(col, sizeof(int)); 
    }

    return ptr;
}

static void arr_allocate(int **ptr, int len, int fillin) {

    *ptr = (int *) calloc(len, sizeof(int));

    for (int i = 0; i < len; i++)
        (*ptr)[i] = fillin;

    return; 
}

static int get_max_value(int **ptr, int row, int col) {

    int max = INT_MIN;

    for (int i = row; i < (row+3); i++) {
        for (int j = col; j < (col+3); j++) {
            if (ptr[i][j] > max)  
                max = ptr[i][j]; 
        }
    }

    return max; 
}

int** largestLocal(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {

    int **result = NULL;

    result = matrix_allocate(gridSize-2, *gridColSize-2);

    for (int i = 0; i < gridSize-2; i++) {
        for (int j = 0; j < *gridColSize-2; j++) {
            result[i][j] = get_max_value(grid, i, j);
        }
    }

    *returnSize = gridSize-2;
    arr_allocate(returnColumnSizes, gridSize-2, *gridColSize-2);

    return result;
}
