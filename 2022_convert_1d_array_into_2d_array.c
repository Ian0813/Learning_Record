/*
 * =====================================================================================
 *
 *       Filename:  2022_convert_1d_array_into_2d_array.c
 *
 *    Description:  convert 1d array into 2d array
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

#define CHECK_CAPACITY(s1, s2) ((s1) == (s2))

static int **allocate_matrix(int m, int n, int **columnSizes) {

    int **matrix = NULL;

    matrix = (int **) calloc(m, sizeof(int *));
    *columnSizes = (int *) calloc(m, sizeof(int));

    for (int i = 0; i < m; i++) {
        matrix[i] = (int *) calloc(n, sizeof(int));
        (*columnSizes)[i] = n;
    }

    return matrix;
}

int** construct2DArray(int* original, int originalSize, int m, int n, int* returnSize, int** returnColumnSizes) {

    int **matrix = NULL, index = 0;

    if (!CHECK_CAPACITY(originalSize, (m * n))) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        goto EXIT_POINT;
    }

    *returnSize = m;
    matrix = allocate_matrix(m, n, returnColumnSizes);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = original[index++];
        }
    }

EXIT_POINT:;
    return matrix;
}
