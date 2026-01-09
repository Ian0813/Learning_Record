/*
 * =====================================================================================
 *
 *       Filename:  1260_shift_2d_grid.c
 *
 *    Description:  shift 2d grid
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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

static void matrix_offset(int **grid, int gridSize, int gridColSize, int offset) {

    int *arr = NULL, index = 0, total_len = gridSize * gridColSize;

    arr = (int *) calloc(gridSize * gridColSize, sizeof(int));

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize; j++) {
            arr[(index + offset) % total_len] = grid[i][j];
            index++;
        }
    }

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize; j++) {
            grid[i][j] = arr[j + (i * gridColSize)];  
        }
    }
    return; 
}

static int *allocate_list(int len, int fillin) {

    int *arr = NULL;

    arr = (int *) calloc(len, sizeof(int));

    for (int i = 0; i < len; i++) {
        arr[i] = fillin; 
    }
    return arr;
}

int** shiftGrid(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes) {

    matrix_offset(grid, gridSize, *gridColSize, k);

    *returnSize = gridSize;
    *returnColumnSizes = allocate_list(gridSize, *gridColSize);

    return grid;
}
