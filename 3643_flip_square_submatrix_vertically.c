/*
 * =====================================================================================
 *
 *       Filename:  3643_flip_square_submatrix_vertically.c
 *
 *    Description:  flip square submatrix vertically
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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

static void reverse(int **grid, int x, int y, int k) {

    int *data = NULL;

    data = (int *) calloc(k, sizeof(int));

    for (int i = x, j = (x + (k-1)); i < j; i++, j--) {
        memcpy(data, &grid[i][y], sizeof(int) * k);
        memcpy(&grid[i][y], &grid[j][y], sizeof(int) * k);
        memcpy(&grid[j][y], data, sizeof(int) * k);
    }

    free(data);
    return;
}

int** reverseSubmatrix(int** grid, int gridSize, int* gridColSize, int x, int y, int k, int* returnSize, int** returnColumnSizes) {

    *returnSize = gridSize;    
    *returnColumnSizes = gridColSize;
    reverse(grid, x, y, k);

    return grid;
}

