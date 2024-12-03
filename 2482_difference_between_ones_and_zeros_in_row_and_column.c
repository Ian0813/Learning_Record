/*
 * =====================================================================================
 *
 *       Filename:  2482_difference_between_ones_and_zeros_in_row_and_column.c
 *
 *    Description:  difference between ones and zeros in row and column
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

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define TABLE_ROW_SIZE 2

enum {
    ROW_ZERO = 0,
    ROW_ONE = 1,
    COLUMN_ZERO = 0,
    COLUMN_ONE = 1,
};

enum {
    DIRECTION_HORIZONTAL = 0,
    DIRECTION_VERTICAL = 1
};

struct record_table {
    int **rt;
    int **ct;
};

static int **diff_allocate(int row, int column) {

    int **diff = NULL;

    diff = (int **) calloc(row, sizeof(int *));

    for (int i = 0; i < row; i++) {
        diff[i] = (int *) calloc(column, sizeof(int));
    }
    return diff;
}

static void table_alloc(struct record_table *table, int row, int column) {

    table->rt = (int **) calloc(TABLE_ROW_SIZE, sizeof(int *));
    table->ct = (int **) calloc(TABLE_ROW_SIZE, sizeof(int *));

    table->rt[ROW_ZERO] = (int *) calloc(row, sizeof(int));
    table->rt[ROW_ONE] = (int *) calloc(row, sizeof(int));
    table->ct[COLUMN_ZERO] = (int *) calloc(column, sizeof(int));
    table->ct[COLUMN_ONE] = (int *) calloc(column, sizeof(int));
    return;
}

static void table_dealloc(struct record_table *table) {

    for (int i = 0; i < TABLE_ROW_SIZE; i++) {
        if (table->rt[i]) free(table->rt[i]);
        if (table->ct[i]) free(table->ct[i]);
    }
    return;
}

static int count(int **numbers, int row, int column, int target, int direction) {

    int count = 0;

    if (direction == DIRECTION_HORIZONTAL) {
        for (int i = 0; i < column; i++) {
            if (target == numbers[row][i]) {
                count++;
            }
        }
    } else if (direction == DIRECTION_VERTICAL) {
        for (int i = 0; i < row; i++) {
            if (target == numbers[i][column]) {
                count++;
            }
        }
    }
    return count;
}    

static void record(int **grid, int row, int column, struct record_table *table) {

    table_alloc(table, row, column);

    for (int i = 0; i < row; i++) {
        table->rt[ROW_ZERO][i] = count(grid, i, column, 0, DIRECTION_HORIZONTAL);
        table->rt[ROW_ONE][i] = count(grid, i, column, 1, DIRECTION_HORIZONTAL);
    }

    for (int i = 0; i < column; i++) {
        table->ct[COLUMN_ZERO][i] = count(grid, row, i, 0, DIRECTION_VERTICAL);
        table->ct[COLUMN_ONE][i] = count(grid, row, i, 1, DIRECTION_VERTICAL);
    }
    return;
}

static void diff_fillin(int **diff, int row, int column, struct record_table *table) {


    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            diff[i][j] = table->rt[ROW_ONE][i] + table->ct[COLUMN_ONE][j] - table->rt[ROW_ZERO][i] - table->ct[COLUMN_ZERO][j];
        }
    }
    return;
}

int** onesMinusZeros(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {

    int **diff = NULL;
    struct record_table table = {0};

    if (gridSize) {
        *returnSize = gridSize;
        *returnColumnSizes = (int *) calloc(gridSize, sizeof(int));
        memcpy(*returnColumnSizes, gridColSize, sizeof(int) * gridSize);
        diff = diff_allocate(gridSize, *gridColSize);    
        record(grid, gridSize, *gridColSize, &table);
        diff_fillin(diff, gridSize, *gridColSize, &table);
        table_dealloc(&table);
    }   
    return diff;
}
