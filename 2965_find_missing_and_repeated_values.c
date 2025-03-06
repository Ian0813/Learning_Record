/*
 * =====================================================================================
 *
 *       Filename:  2965_find_missing_and_repeated_values.c
 *
 *    Description:  find missing and repeated values
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
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define RESULT_SIZE 2
#define REPEAT 0
#define MISSING 1

static void count_digit(int *table, int **grid, int gridSize) {

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            table[grid[i][j]]++;
        }
    }
    return;
}

int* findMissingAndRepeatedValues(int** grid, int gridSize, int* gridColSize, int* returnSize) {

    int *table = NULL;
    int tsize = (gridSize*gridSize)+1;
    int *result = (int *) calloc(RESULT_SIZE, sizeof(int));

    if (gridSize) {

        table = (int *) calloc(tsize, sizeof(int));
        count_digit(table, grid, gridSize);

        for (int i = 1; i < tsize; i++) {
            if (!table[i]) {
                result[MISSING] = i;
            } else if (table[i] == 2) {
                result[REPEAT] = i;
            }
        }
    }
    *returnSize = RESULT_SIZE;
    return result;
}
