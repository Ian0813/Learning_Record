/*
 * =====================================================================================
 *
 *       Filename:  498_diagonal_traverse.c
 *
 *    Description:  diagonal traverse
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

typedef enum {false, true} bool; 

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct array_group {
    int **array;
    int *arr_length;
    int *diag_count;
    int arr_size;
} arrgrp;

static void mat_to_arrgrp(int **mat, int matSize, int matColSize, arrgrp *ag) {

    int offset = 0;

    for (int i = 0; i < matSize; i++) {

        for (int j = 0; j < matColSize; j++) {
            ag->array[j+offset][ag->arr_length[j+offset]] = mat[i][j];   
            ag->arr_length[j+offset]++;
        }
        offset++;
    }

    return;
}

static void get_diag_count(arrgrp *ag, int **mat, int row, int cols) {

    int offset = 0;

    if (!ag)
        return;

    ag->diag_count = (int *) calloc(ag->arr_size, sizeof(int));

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < cols; j++) {
            ag->diag_count[j+offset]++;
        }
        offset++;
    }

    return;
}

static bool arrgrp_allocate(arrgrp *ag, int len) {

    if (!ag)
        return false;

    if (!ag->arr_size || !len)
        return false;

    ag->array = (int **) calloc(ag->arr_size, sizeof(int *)); 

    for (int i = 0; i < ag->arr_size; i++) {
        ag->array[i] = (int *) calloc(ag->diag_count[i], sizeof(int));
    }

    ag->arr_length = (int *) calloc(ag->arr_size, sizeof(int));
    
    return true;
}

static void arrgrp_free(arrgrp *ag) {

    if (!ag)
        return;

    free(ag->arr_length);

    for (int i = 0; i < ag->arr_size; i++) {
        free(ag->array[i]);
    }

    free(ag->array);
    return;
}

int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize) {

    arrgrp ag = {.arr_size = (*matColSize + (matSize-1)), .array = NULL, .arr_length = NULL};
    int *result = NULL, index = 0, start = 0; 

    result = (int *) calloc(matSize * (*matColSize), sizeof(int));

    get_diag_count(&ag, mat, matSize, *matColSize);
    arrgrp_allocate(&ag, *matColSize);
    mat_to_arrgrp(mat, matSize, *matColSize, &ag);

    for (int i = 0; i < ag.arr_size; i++) {
        if (!(i%2)) {
            for (int j = ag.arr_length[i]-1; j >= 0; j--) {
                result[index++] = ag.array[i][j];
            }
        } else {
            for (int j = 0; j < ag.arr_length[i]; j++) {
                result[index++] = ag.array[i][j];
            }
        }
    }

    *returnSize = index;
    arrgrp_free(&ag);

    return result;
}
