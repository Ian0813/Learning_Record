/*
 * =====================================================================================
 *
 *       Filename:  2639_find_the_width_of_columns_of_a_grid.c
 *
 *    Description:  find the width of columns of a grid
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
#include <limits.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef enum {
    GRID_ROW = (1 << 0),
    GRID_COL = (1 << 1),
} main_direction;

static inline int get_digitlen(int value) {

    int digit_len = 0; 

    digit_len = value < 0 ? (digit_len + 1) : digit_len;
    value = abs(value);

    do {
        digit_len++;
        value /= 10;
    } while (value);

    return digit_len;
}

static void get_gwidth_bydirection(int **grid, int gridSize, int gridColSize, main_direction direction, int *result) {

    int max = 0, min = INT_MAX, max_len = 0, min_len = 0;

    if (direction != GRID_COL && direction != GRID_ROW)
        return;

    if (direction == GRID_ROW) {
        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridColSize; j++) {
                printf("%d ", grid[i][j]);    
            }
            putchar('\n');
        }
    } else if (direction == GRID_COL) {
        for (int i = 0; i < gridColSize; i++) {
            for (int j = 0; j < gridSize; j++) {
                max = grid[j][i] > max ? grid[j][i] : max;
                min = grid[j][i] < min ? grid[j][i] : min;
            }
            max_len = get_digitlen(max);
            min_len = get_digitlen(min);
            result[i] = max_len > min_len ? max_len : min_len;
            max = max_len = min_len = 0;
            min = INT_MAX; 
        }
    }

    return;
}

int* findColumnWidth(int** grid, int gridSize, int* gridColSize, int* returnSize) {

    int *result = NULL;

    if (gridSize && *gridColSize) {

        result = (int *) calloc(*gridColSize, sizeof(int));
        *returnSize = *gridColSize;
        get_gwidth_bydirection(grid, gridSize, *gridColSize, GRID_COL, result);
    }

    return result; 
}
