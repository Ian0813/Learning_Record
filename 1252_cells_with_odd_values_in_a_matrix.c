/*
 * =====================================================================================
 *
 *       Filename:  1252_cells_with_odd_values_in_a_matrix.c
 *
 *    Description:  cells with odd values in a matrix
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

#define MAX_SIZE 50

enum {
    ROW_INDEX = 0,
    COLUMN_INDEX = 1
};

static int **allocate_matrix(int row, int column) {

    int **matrix = NULL;

    matrix = (int **) calloc(row, sizeof(int *));

    for (int i = 0; i < row; i++) {
        matrix[i] = (int *) calloc(column, sizeof(int));
    }

    return matrix;
}

static int count_odd_values(int **matrix, int m, int n) {

    int count = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j]%2) {
                count++; 
            }
        }
    }
    return count;
}    

int oddCells(int m, int n, int** indices, int indicesSize, int* indicesColSize) {

    int row_counter[MAX_SIZE] = {0}, column_counter[MAX_SIZE] = {0};  
    int **matrix = NULL, odd_number = 0;

    for (int i = 0; i < indicesSize; i++) {
        row_counter[indices[i][ROW_INDEX]]++;
        column_counter[indices[i][COLUMN_INDEX]]++;
    }

    matrix = allocate_matrix(m, n);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] += row_counter[i];
            matrix[i][j] += column_counter[j];
        }
    }

    odd_number = count_odd_values(matrix, m, n);
    free(matrix);

    return odd_number;
}
