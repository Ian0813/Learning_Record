/*
 * =====================================================================================
 *
 *       Filename:  892 surface area of 3d shapes.c
 *
 *    Description:  surface area of 3d shapes
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

#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef enum {
    AREA_ROW = 0,
    AREA_COL = 1,
} area_t;

typedef struct {
    int value;
    int vindex;
} value_node;

static int get_diff(int **grid, int rmax, int cmax, int pos, area_t area) {

    if (!grid)
        return 0;

    int diff = 0, nsize = 0;
    int *ptr = NULL, pindex = 0, value = 0;

    nsize = area == AREA_ROW ? cmax : rmax;
    ptr = (int *) calloc(nsize, sizeof(int));

    if (area == AREA_ROW) {
        for (int i = 0; i < nsize; i++) {
            ptr[pindex++] = grid[pos][i];
        }
    } else if (area == AREA_COL) {
        for (int i = 0; i < nsize; i++) {
            ptr[pindex++] = grid[i][pos];
        }
    }

    for (int i = 1; i < pindex; i++) {
        diff += (2 * MIN(ptr[i], ptr[i-1]));
    }

    free(ptr);
    return diff;
}

int surfaceArea(int** grid, int gridSize, int* gridColSize) {

    int value = 0, result = 0;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j])
                result += ((4 * grid[i][j]) + 2);
        }
    }

    for (int i = 0; i < gridSize; i++) {
        value = get_diff(grid, gridSize, *gridColSize, i, AREA_ROW);
        result -= value;
    }

    for (int i = 0; i < *gridColSize; i++) {
        value = get_diff(grid, gridSize, *gridColSize, i, AREA_COL);
        result -= value;
    }

    return result;
}
