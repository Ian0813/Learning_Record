/*
 * =====================================================================================
 *
 *       Filename:  240_search_a_2d_matrix_ii.c
 *
 *    Description:  search a 2d matrix ii
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

typedef enum {false, true} bool;

#define EQUAL_ON_TYPE(matrix, index, middle, type, key) \
    type == SEARCH_ROW ? (matrix[middle][index] == key) : (matrix[index][middle] == key)

#define GREATER_ON_TYPE(matrix, index, middle, type, key) \
    type == SEARCH_ROW ? (matrix[middle][index] > key) : (matrix[index][middle] > key)

#define LESS_ON_TYPE(matrix, index, middle, type, key) \
    type == SEARCH_ROW ? (matrix[middle][index] < key) : (matrix[index][middle] < key)

typedef enum {
    SEARCH_ROW = 0,
    SEARCH_COL = 1
} search_type;

static int binary_search(int **matrix, int index, int start, int end, search_type type, int key) {

    int middle = (start+end) / 2;
    int i = middle;

    if (start < end) {
        if (GREATER_ON_TYPE(matrix, index, middle, type, key)) {
            i = binary_search(matrix, index, start, middle, type, key); 
        } else if (LESS_ON_TYPE(matrix, index, middle, type, key)) {
            i = binary_search(matrix, index, middle+1, end, type, key); 
        }
    }

    return i;
}

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {

    bool rc = false;
    int col_index = 0, row_index = 0;

    if (matrix) {

        col_index = binary_search(matrix, row_index, 0, *matrixColSize, SEARCH_COL, target);

        if (col_index < *matrixColSize && matrix[row_index][col_index] == target) {
            rc = true; 
        }

        col_index--;

        if (!rc && col_index >= 0) {
            for (int i = col_index; !rc && i >= 0; i--) {
                row_index = binary_search(matrix, i, 0, matrixSize, SEARCH_ROW, target);

                if (row_index < matrixSize && matrix[row_index][i] == target) {
                    rc = true;
                }
            }
        }
    }
    return rc;
}
