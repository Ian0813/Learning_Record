/*
 * =====================================================================================
 *
 *       Filename:  1030_matrix_cells_in_distance_order.c
 *
 *    Description:  matrix cells in distance order
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

#define COORDINATE_SIZE 2
#define GET_DISTANCE(r1, c1, r2, c2) (abs(r1-r2)+abs(c1-c2))

struct matrix_info {
    int **matrix;
    int *distances;
    int cols, rows, length;
};

enum {
    R_INDEX = 0,
    C_INDEX = 1
};

void swap(int *v1, int *v2) {

    int temp = *v1;
    *v1 = *v2;
    *v2 = temp;
    return;
}

void swap_ptr(int **v1, int **v2) {

    int *temp = *v1;
    *v1 = *v2;
    *v2 = temp;
    return;
}

static void quick_sort(struct matrix_info *result, int head, int end) {

    int front = head, last = head, tail = end-1;

    if (front < tail) {
        while (last < tail) {
            if (result->distances[head] > result->distances[tail]) {
                last++;
                swap(&result->distances[last], &result->distances[tail]);
                swap_ptr(&result->matrix[last], &result->matrix[tail]);
                continue;
            }
            tail--;
        }
        swap(&result->distances[head], &result->distances[last]);
        swap_ptr(&result->matrix[head], &result->matrix[last]);
        quick_sort(result, head, last);
        quick_sort(result, last+1, end);
    }
    return;
}

static int **allocate_matrix(int rows, int cols) {

    int **matrix = NULL, amount = 0, index = 0;

    amount = rows*cols;

    matrix = (int **) calloc(amount, sizeof(int *));

    for (int i = 0; i < amount; i++) {
        matrix[i] = (int *) calloc(COORDINATE_SIZE, sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[index][R_INDEX] = i;
            matrix[index][C_INDEX] = j;
            index++;
        }
        putchar('\n');
    }
    return matrix;
}

static void get_distances(struct matrix_info *result, int rCenter, int cCenter) {

    int index = 0;

    result->distances = (int *) calloc(result->cols*result->rows, sizeof(int));

    for (int i = 0; i < result->length; i++) {
        result->distances[i] = GET_DISTANCE(result->matrix[i][R_INDEX], result->matrix[i][C_INDEX], rCenter, cCenter);
    }

    return;
}

static int *get_column_sizes(struct matrix_info *result) {

    int *columnSizes = NULL;

    columnSizes = (int *) calloc(result->length, sizeof(int));

    for (int i = 0; i < result->length; i++) {
        columnSizes[i] = COORDINATE_SIZE;
    }
    return columnSizes;
}

int** allCellsDistOrder(int rows, int cols, int rCenter, int cCenter, int* returnSize, int** returnColumnSizes) {

    struct matrix_info result = {.cols = cols, .rows = rows, .length = (rows*cols)};
    int **matrix = NULL;

    result.matrix = allocate_matrix(rows, cols);
    get_distances(&result, rCenter, cCenter);

    quick_sort(&result, 0, result.length);
    cols = 0;

    *returnSize = result.length;
    *returnColumnSizes = get_column_sizes(&result); 

    free(result.distances);
    return result.matrix;
}
