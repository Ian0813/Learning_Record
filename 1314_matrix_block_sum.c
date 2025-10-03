/*
 * =====================================================================================
 *
 *       Filename:  1314 matrix block sum.c
 *
 *    Description:  matrix block sum
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

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define MAX(v1, v2) ((v1) > (v2) ? (v1) : (v2))
#define MIN(v1, v2) ((v1) < (v2) ? (v1) : (v2))

typedef struct answer_matrix {
    int **matrix;
    int row;
    int *column;
    int scope;
} ans_matrix;

static void matrix_range_sumup(int **mat, int mrow, int mcol, ans_matrix *answer) {

    int max_row = 0, max_col = 0, min_row = 0, min_col = 0;

    if (!mat || !answer)
        return;

    max_row = MIN((mrow + answer->scope), answer->row - 1);
    max_col = MIN((mcol + answer->scope), *answer->column - 1);
    min_row = MAX((mrow - answer->scope), 0);
    min_col = MAX((mcol - answer->scope), 0);

    for (int i = min_row; i <= max_row; i++) {
        for (int j = min_col; j <= max_col; j++) {
            answer->matrix[mrow][mcol] += mat[i][j];
        }
    }

    return;
}

int** matrixBlockSum(int** mat, int matSize, int* matColSize, int k, int* returnSize, int** returnColumnSizes) {

    ans_matrix answer = {0};  

    if (mat) {

        answer.matrix = (int **) calloc(matSize, sizeof(int *));

        for (int i = 0; i < matSize; i++)
            answer.matrix[i] = (int *) calloc(*matColSize, sizeof(int));

        answer.scope = k; 
        answer.row = matSize;
        answer.column = matColSize;

        for (int i = 0; i < matSize; i++) {
            for (int j = 0; j < *matColSize; j++) {
                matrix_range_sumup(mat, i, j, &answer);
            }
        }
    }

    *returnSize = answer.row;
    *returnColumnSizes = answer.column;

    return answer.matrix;
}

