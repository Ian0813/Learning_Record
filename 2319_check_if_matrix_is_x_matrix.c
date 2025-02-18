/*
 * =====================================================================================
 *
 *       Filename:  2319_check_if_matrix_is_x_matrix.c
 *
 *    Description:  check if matrix is x matrix
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

typedef enum {false, true} bool;

bool check_integrity(int **grid, int r, int c, int gridSize) {

    bool rc = true;

    if (r == c || r == (gridSize-c-1)) {
        rc = grid[r][c] ? true : false;
    } else {
        rc = !grid[r][c] ? true : false;
    }
    return rc;
}

bool checkXMatrix(int** grid, int gridSize, int* gridColSize) {

    bool rc = true;

    for (int i = 0; i < gridSize && rc; i++) {
        for (int j = 0; j < gridColSize[i] && rc; j++) {
            rc = check_integrity(grid, i, j, gridSize);
        }
    }
    return rc;
}
