/*
 * =====================================================================================
 *
 *       Filename:  566_reshape_the_matrix.c
 *
 *    Description:  reshape the matrix
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

typedef enum {false, true} bool;

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

static int **allocate_matrix(int r, int c) {

    int **matrix = NULL;

    matrix = (int **) calloc(r, sizeof(int *));

    for (int i = 0; i < r; i++) {
        matrix[i] = (int *) calloc(c, sizeof(int));
    }

    return matrix;
}

static void move_to_array(int **mat, int matSize, int *matColSize, int **arr) {

    int index = 0;

    if (!mat)
        return;

    *arr = (int *) calloc(matSize * (*matColSize), sizeof(int));

    for (int i = 0; i < matSize; i++) {
        for (int j = 0; j < matColSize[i]; j++) {
            (*arr)[index++] = mat[i][j];
        }
    }

    return;
}

static bool precheck(int matSize, int matColSize, int r, int c) {
    return (matSize * matColSize) == (r * c);
}

int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {

    int **matrix = NULL;
    int *arr = NULL, index = 0;

    if (!precheck(matSize, *matColSize, r, c)) {
        matrix = mat;
        *returnSize = matSize;
        *returnColumnSizes = matColSize;
        goto EXIT_POINT;
    }

    *returnColumnSizes = (int *) calloc(r, sizeof(int));
    matrix = allocate_matrix(r, c);
    move_to_array(mat, matSize, matColSize, &arr);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            matrix[i][j] = arr[index++];
        }
    }

    free(arr);
    *returnSize = r;

    for (int i = 0; i < r; i++) {
        (*returnColumnSizes)[i] = c;
    }

EXIT_POINT:;
    return matrix;
}
