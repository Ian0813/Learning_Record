/*
 * =====================================================================================
 *
 *       Filename:  3142_check_if_grid_satisfies_conditions.c
 *
 *    Description:  check if grid satisfies conditions
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

typedef enum {false, true} bool;

#define IS_EQUAL(a, b) ((a) == (b))

static bool check_grids(int **grids, int gridSize, int col) {

    bool rc = true;

    for (int i = 0; i < gridSize; i++) {

        for (int j = 0; j < col; j++) {
            if (i < gridSize-1) {
                rc = IS_EQUAL(grids[i][j], grids[i+1][j]);

                if (!rc)
                    return rc;
            }

            if (j < (col-1)) {
                rc = !(IS_EQUAL(grids[i][j], grids[i][j+1]));

                if (!rc)
                    return rc;
            }
        }
    }
    return true;
}

bool satisfiesConditions(int** grid, int gridSize, int* gridColSize) {
    return check_grids(grid, gridSize, *gridColSize);
}
