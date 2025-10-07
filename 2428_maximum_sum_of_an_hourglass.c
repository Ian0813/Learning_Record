/*
 * =====================================================================================
 *
 *       Filename:  2428 maximum sum of an hourglass.c
 *
 *    Description:  maximum sum of an hourglass
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

typedef enum {
    HOURGLASS_HEIGHT = 3,
    HOURGLASS_WIDTH = 3
} hourglass_t;

static int get_hourglass(int **grid, int row, int col) {

    int sum = 0;

    for (int i = 0 + row; i < HOURGLASS_WIDTH + row; i++) {
        for (int j = 0 + col; j < HOURGLASS_HEIGHT + col; j++) {
            sum += grid[i][j];
        }
    }

    sum -= (grid[1 + row][0 + col] + grid[1 + row][2 + col]);
    return sum;
}

int maxSum(int** grid, int gridSize, int* gridColSize) {

    int max = 0, sum = 0 ;

    for (int i = 0; i < (gridSize - HOURGLASS_WIDTH) + 1; i++) {
        for (int j = 0; j < (gridColSize[i] - HOURGLASS_HEIGHT) + 1; j++) {
            sum  = get_hourglass(grid, i, j);
            max = max > sum ? max : sum;
        }
    }

    return max;
}
