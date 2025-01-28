/*
 * =====================================================================================
 *
 *       Filename:  73_set_matrix_zeroes.c
 *
 *    Description:  set matrix zeroes
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

struct zero_location {
    int *rows;
    int *columns;
    int size;
};

static struct zero_location *zero_locator_init(int length) {

    struct zero_location *zero_locator = NULL;    

    if (length) {
        zero_locator = (struct zero_location *) malloc(sizeof(*zero_locator));
        zero_locator->rows = (int *) calloc(length, sizeof(int));
        zero_locator->columns = (int *) calloc(length, sizeof(int));
        zero_locator->size = 0;
    }
    return zero_locator;
}

static void zero_locate(int **matrix, int matrixSize, int *matrixColSize, struct zero_location *zero_locator) {

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[i]; j++) {
            if (!matrix[i][j]) {
                zero_locator->rows[zero_locator->size] = i;
                zero_locator->columns[zero_locator->size++] = j;
            }
        }
    }
    return;
}

static void free_zero_locator(struct zero_location *zero_locator) {
    if (zero_locator) {
        free(zero_locator->rows);
        free(zero_locator->columns);
        free(zero_locator);
    }
    return;
}

static void print_zero_location(struct zero_location *zero_locator) {

    if (zero_locator) {
        for (int i = 0; i < zero_locator->size; i++) {
            printf("[%d][%d] ", zero_locator->rows[i], zero_locator->columns[i]); 
        }
        putchar('\n');
    }
    return;
}

static void fill_zeros(int **matrix, int row_size, int column_size, int row_point, int column_point) {

    for (int i = 0; i < column_size; i++) {
        matrix[row_point][i] = 0;
    }

    for (int i = 0; i < row_size; i++) {
        matrix[i][column_point] = 0;
    }
    return;
}

void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {

    struct zero_location *zero_locator = NULL;

    if (matrixSize) {
        zero_locator = zero_locator_init(matrixSize*(*matrixColSize));
        zero_locate(matrix, matrixSize, matrixColSize, zero_locator);

        for (int i = 0; i < zero_locator->size; i++) {
            fill_zeros(matrix, matrixSize, *matrixColSize, zero_locator->rows[i], zero_locator->columns[i]);
        }
        free_zero_locator(zero_locator);
    }
    return;
}
