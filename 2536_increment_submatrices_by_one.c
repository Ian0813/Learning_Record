/*
 * =====================================================================================
 *
 *       Filename:  2536_increment_submatrices_by_one.c
 *
 *    Description:  increment submatrices by one
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

enum {
    S_ROW_INDEX = 0,
    S_COL_INDEX = 1,
    E_ROW_INDEX = 2,
    E_COL_INDEX = 3
};

static int **create_matrix(int n, int *returnSize, int **returnColumnSizes) {

    int **matrix = NULL;

    matrix = (int **) calloc(n, sizeof(int *));

    do {
        if (!matrix)
            break;    

        *returnSize = n;
        *returnColumnSizes = (int *) calloc(n, sizeof(int));

        for (int i = 0; i < n; i++) {
            matrix[i] = (int *) calloc(n, sizeof(int));
            memset(matrix[i], 0, sizeof(int) * n);
            (*returnColumnSizes)[i] = n;
        }
    } while (0);

    return matrix;
}    

static void process_submatrix(int **matrix, int start_r, int start_c, int end_r, int end_c, int limit) {

    for (int i = start_r; i <= end_r; i++) {

            matrix[i][start_c]++; 

            if ((end_c + 1) < limit) {
                matrix[i][end_c + 1]--;
            }
    }

    return;
}

static void post_process(int **matrix, int limit) {

    for (int i = 0; i < limit; i++) {
        for (int j = 1; j < limit; j++) {
            matrix[i][j] = matrix[i][j] + matrix[i][j-1];
        }
    }    
    return;
}

int** rangeAddQueries(int n, int** queries, int queriesSize, int* queriesColSize, int* returnSize, int** returnColumnSizes) {

    int **matrix = NULL; 

    matrix = create_matrix(n, returnSize, returnColumnSizes); 

    for (int i = 0; i < queriesSize; i++) {
        process_submatrix(matrix, queries[i][S_ROW_INDEX], queries[i][S_COL_INDEX], queries[i][E_ROW_INDEX], queries[i][E_COL_INDEX], n);
    }

    post_process(matrix, n);

    return matrix;
}
