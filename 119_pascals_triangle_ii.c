/*
 * =====================================================================================
 *
 *       Filename:  119_pascals_triangle_ii.c
 *
 *    Description:  pascals triangle ii
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
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define FILL_ARRAY(parr, psize, arr, index) { for (int i = 0; i < (psize-1); i++) arr[index++] = (parr[i] + parr[i+1]);}

static int *get_layer_row(int layer, int *size) {

    int *arr = NULL, *parr = NULL;
    int psize = 0, index = 1;

    arr = (int *) calloc(layer+1, sizeof(int));
    *size = layer+1;

    arr[0] = arr[layer] = 1;

    if (layer > 1) {
        parr = get_layer_row(layer-1, &psize);
        FILL_ARRAY(parr, psize, arr, index);
        free(parr);
    }
    return arr;
}

int* getRow(int rowIndex, int* returnSize) {

    int *result = NULL;
    int size = 0;

    if (rowIndex >= 0) {
        result = get_layer_row(rowIndex, &size);
        *returnSize = size;
    }
    return result;
}
