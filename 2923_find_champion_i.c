/*
 * =====================================================================================
 *
 *       Filename:  2923_find_champion_i.c
 *
 *    Description:  find champion i
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

typedef enum {false, true} bool;

static bool contain_one(int *row, int *col, int size) {

    bool rc = false;

    for (int i = 0; i < size && !rc; i++) {
        rc = row[i] ? true : false;
        *col = i;
    }

    return rc;
}

static void check_champion(int **grid, int *row, int *col, int row_size, int col_size) {

    for (int i = *row + 1; i < row_size; i++) {
        if (grid[i][*col] && grid[i][*row]) {
            *row = i; 
            *col = i;
        }    
    }
    return;
}

int findChampion(int** grid, int gridSize, int* gridColSize) {

    int row = 0, col = 0;

    for (int i = row; i < gridSize; i++) {
        if (contain_one(grid[i], &col, gridSize)) {
            row = i; 
            break;
        }
    }

    check_champion(grid, &row, &col, gridSize, *gridColSize);

    return row;
}
