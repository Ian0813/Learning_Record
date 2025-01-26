/*
 * =====================================================================================
 *
 *       Filename:  1329_sort_the_matrix_diagonally.c
 *
 *    Description:  sort the matrix diagonally
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

static void swap(int *v1, int *v2) {

    int temp = *v1;
    *v1 = *v2;
    *v2 = temp;
    return;
}    

static void quick_sort(int *arr, int head, int end) {

    int front = head, last = head, tail = end-1;

    if (front < tail) {
        while (last < tail) {
            if (arr[head] > arr[tail]) {
                last++; 
                swap(&arr[last], &arr[tail]);
                continue;
            }
            tail--;
        }    
        swap(&arr[head], &arr[last]);
        quick_sort(arr, head, last);
        quick_sort(arr, last+1, end);
    }
    return;
}

void print_diagonal(int **mat, int row, int column, int rsize, int csize) {

    int *arr = NULL;
    int index = 0;
    int local_row = row, local_column = column; 

    arr = (int *) calloc(csize, sizeof(int)); 

    while (row < rsize && column < csize) {
        arr[index++] = mat[row++][column++];
    }

    row = local_row, column = local_column; 
    quick_sort(arr, 0, index);

    for (int i = 0; i < index; i++) {
        mat[row++][column++] = arr[i]; 
    }
    free(arr);
    return;
}

int** diagonalSort(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes) {

    if (matSize) {
        for (int i = 0; i < matSize; i++) {
            for (int j = 0; j < matColSize[i]; j++) {
                if (!i || !j) {
                    print_diagonal(mat, i, j, matSize, matColSize[i]);
                }
            }    
        }
        *returnSize = matSize;
        *returnColumnSizes = matColSize;
    }   
    return mat;
}
