/*
 * =====================================================================================
 *
 *       Filename:  3033_modify_the_matrix.c
 *
 *    Description:  modify the matrix
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04.3) 11.4.0
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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define POINT_LEN 2
#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef enum {
    INDEX_ROW = 0,
    INDEX_COL = 1
} mat_index;

typedef struct {
    int pos[POINT_LEN];
} point;

typedef struct {
    point *points;
    int len; 
} coordinate;

static void column_maximum(int **matrix, int rsize, int csize, int *col_maxval, coordinate *replace) {

    int max = INT_MIN;

    for (int i = 0; i < csize; i++) {
        for (int j = 0; j < rsize; j++) {

            max = MAX(max, matrix[j][i]);

            if (matrix[j][i] == -1) {
                replace->points[replace->len].pos[INDEX_ROW] = j;
                replace->points[replace->len].pos[INDEX_COL] = i;
                replace->len++;
            }
        }
        col_maxval[i] = max;
        max = INT_MIN;
    }
    return;
}    

static void handle_replace(int **matrix, int *col_maxval, coordinate *replace) {

    for (int i = 0; i < replace->len; i++) {
        matrix[replace->points[i].pos[INDEX_ROW]][replace->points[i].pos[INDEX_COL]] = col_maxval[replace->points[i].pos[INDEX_COL]];
    }

    return;
}

int** modifiedMatrix(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {

    int *col_maxval = NULL; 
    coordinate replace = {0};

    *returnSize = matrixSize;
    *returnColumnSizes = matrixColSize;

    replace.points = (point *) calloc(matrixSize * (*matrixColSize), sizeof(point)); 
    col_maxval = (int *) calloc(*matrixColSize, sizeof(int));

    column_maximum(matrix, matrixSize, *matrixColSize, col_maxval, &replace);
    handle_replace(matrix, col_maxval, &replace);

    free(col_maxval);
    free(replace.points);

    return matrix;
}
