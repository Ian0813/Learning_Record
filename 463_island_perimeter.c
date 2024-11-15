/*
 * =====================================================================================
 *
 *       Filename:  463_island_perimeter.c
 *
 *    Description:  Island Perimeter  
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

#define DEFAULT_SIDES 4

static inline int check_adjacent(int **grid, int row, int column, int row_end, int column_end) {

    int size = DEFAULT_SIDES;

    if (grid) {
        if (row && column) {
            size = grid[row-1][column] ? size-1 : size;
            size = grid[row][column-1] ? size-1 : size;
        } else if (!row && column) {
            size = grid[row][column-1] ? size-1 : size;
        } else if (row && !column) {
            size = grid[row-1][column] ? size-1 : size;
        }
        if (row+1 != row_end)
            size = grid[row+1][column] ? size-1 : size;
        if (column+1 != column_end)
            size = grid[row][column+1] ? size-1 : size;
    }
    return size;
}

int islandPerimeter(int** grid, int gridSize, int* gridColSize) {

    int perimeter = 0;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j])  
                perimeter += check_adjacent(grid, i, j, gridSize, gridColSize[i]);
        }
    }

    return perimeter;
}
