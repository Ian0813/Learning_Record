/*
 * =====================================================================================
 *
 *       Filename:  118_pascals_triangle.c
 *
 *    Description:  pascals triangle
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

static void fill_column_sizes(int *column_sizes, int row) {

    for (int i = 0; i < row; i++) {
        column_sizes[i] = i+1;
    }
    return;
}

static void form_triangle(int **result, int numRows) {

    int level = 0, index = 0, tindex = 0;

    for (int i = 0; i < numRows; i++) {

        result[i] = (int *) calloc(i+1, sizeof(int));    
        level = i+1;

        if (level == 1) {
            result[i][index] = 1;  
        } else {
            for (int j = 0; j < level; j++) {
                if (!j || j == level-1) {
                    tindex = j == level-1 ? j-1 : 0;
                    result[i][index++] = result[i-1][tindex];
                } else {
                    result[i][index++] = result[i-1][j] + result[i-1][j-1];
                }
            }
        }
        index = 0;
    }
    return;
}

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {

    int **result = NULL;

    if (numRows) {

        *returnSize = numRows;
        *returnColumnSizes = (int *) calloc(numRows, sizeof(int));
        result = (int **) calloc(numRows, sizeof(int *));

        fill_column_sizes(*returnColumnSizes, numRows);
        form_triangle(result, numRows);
    }
    return result;
}
