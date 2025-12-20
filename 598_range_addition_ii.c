/*
 * =====================================================================================
 *
 *       Filename:  598_range_addition_ii.c
 *
 *    Description:  range addition ii
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

typedef enum {false, true} bool;

enum {
    INDEX_ROW = 0,
    INDEX_COL = 1,
    INDEX_LEN 
};

int maxCount(int m, int n, int** ops, int opsSize, int* opsColSize) {

    int max = 0, minimum_row = INT_MAX, minimum_col = INT_MAX;
    bool countable = false; 

    for (int i = 0; i < opsSize; i++) {

        countable = true;

        if (ops[i][INDEX_ROW] < minimum_row) {
            minimum_row = ops[i][INDEX_ROW]; 
        }

        if (ops[i][INDEX_COL] < minimum_col) {
            minimum_col = ops[i][INDEX_COL]; 
        }
    }

    if (countable)
        max = minimum_row * minimum_col;

    return max ? max : (m*n);
}
