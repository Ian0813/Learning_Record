/*
 * =====================================================================================
 *
 *       Filename:  861_score_after_flipping_matrix.c
 *
 *    Description:  score after flipping matrix
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

#define GET_FIRST_FROM_ROW(arr, row) ((arr[row][0]))
#define INVERT(val) (!(val) ? 1 : 0)

enum direction {
    ROW = 0,
    COLUMN = 1
};

static int count_column_one(int **grid, int column, int gridSize) {

    int count = 0;

    for (int i = 0; i < gridSize; i++) {
        if (grid[i][column]) {
            count++; 
        }
    }
    return count;
}

static void inverter(int **grid, enum direction dir, int row, int column, int gridSize, int *gridColSize) {

    if (dir == ROW) {
        for (int i = 0; i < gridColSize[row]; i++) {
            grid[row][i] = INVERT(grid[row][i]);
        }
    } else if (dir == COLUMN) {
        for (int i = 0; i < gridSize; i++) {
            grid[i][column] = INVERT(grid[i][column]);
        }
    }
    return;
}

static int get_score(int **grid, int row, int *gridColSize) {

    int sum = 0, step = 0, value = 0;

    for (int i = 0; i < gridColSize[row]; i++) {
        sum = 2 * sum;
        sum += grid[row][i];
    }
    return sum;
}    

int matrixScore(int** grid, int gridSize, int* gridColSize) {

    int count_one = 0;
    int score = 0;

    for (int i = 0; i < gridSize; i++) {
        if (!GET_FIRST_FROM_ROW(grid, i)) {
            inverter(grid, ROW, i, 0, gridSize, gridColSize);    
        }
    }

    for (int i = 0; i < *gridColSize; i++) {
        count_one = count_column_one(grid, i, gridSize); 
        if (count_one < (gridSize-count_one)) {
            inverter(grid, COLUMN, 0, i, gridSize, gridColSize);
        }
    }

    for (int i = 0; i < gridSize; i++) {
        score += get_score(grid, i, gridColSize);
    }
    return score;
}
