/*
 * =====================================================================================
 *
 *       Filename:  1727_largest_submatrix_with_rearrangements.c
 *
 *    Description:  largest submatrix with rearrangements
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

#define MAX(a, b) ((a) > (b) ? (a) : (b))

static void swap(int *v1, int *v2) {

    int temp = *v1;

    *v1 = *v2;
    *v2 = temp;

    return;
}

static void quick_sort(int *arr, int head, int end) {

    int last = head, tail = end;

    if (head < end) {
        while (last < tail) {
            if (arr[head] < arr[tail]) {
                last++;
                swap(&arr[last], &arr[tail]);
                continue;
            }
            tail--;
        }

        swap(&arr[head], &arr[last]);
        quick_sort(arr, head, last-1);
        quick_sort(arr, last+1, end);
    }
    return;
}

static int **matrix_allocate(int row, int column) {

    int **matrix = NULL;

    matrix = (int **) calloc(row, sizeof(int *));

    for (int i = 0; i < row; i++) {
        matrix[i] = (int *) calloc(column, sizeof(int));
    }

    return matrix;
}

static void matrix_free(int **matrix, int len) {

    if (matrix) {
        for (int i = 0; i < len; i++)
            free(matrix[i]);
        free(matrix);
    }
    return;
}

static void get_consecutive_by_col(int **matrix, int **counter, int col_index, int len) {

    int count_one = 0;

    for (int i = 0; i < len; i++) {

        if (matrix[i][col_index]) {
            count_one++; 
        } else {
            count_one = 0;
        }

        counter[i][col_index] = count_one;
    }

    return;
}

int largestSubmatrix(int** matrix, int matrixSize, int* matrixColSize) {

    int **ptr = NULL;
    int temp = 0, max = 0;

    if (matrixSize > 1) {

        ptr = matrix_allocate(matrixSize, *matrixColSize);

        for (int i = 0; i < *matrixColSize; i++) {
            get_consecutive_by_col(matrix, ptr, i, matrixSize);
        }

        for (int i = 0; i < matrixSize; i++) {

            quick_sort(ptr[i], 0, matrixColSize[i]-1); 

            for (int j = 0; j < matrixColSize[i] && ptr[i][j]; j++) {
                temp = (ptr[i][j] * (j+1));
                max = MAX(temp, max);
            }
        }

        matrix_free(ptr, matrixSize);

    } else {
        for (int i = 0; i < *matrixColSize; i++) {
            if (matrix[0][i]) {
                max++;
            }
        }
    }

    return max;
}
