/*
 * =====================================================================================
 *
 *       Filename:  2133_check_if_every_row_and_column_contains_all_numbers.c
 *
 *    Description:  check if every row and column contains all numbers
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

typedef enum {false, true} bool;

enum {
    TYPE_ROW = 0, 
    TYPE_COL = 1
};

#define ZERO_OUT_ARR(arr, size) for (int i = 0; i < size; i++) arr[i] = 0;

static bool check_row_column(int **matrix, int type_index, int type, int size, int *check_set) { 

    bool rc = true;

    if (type == TYPE_ROW) {
        for (int i = 0; i < size; i++) {
            if (!check_set[matrix[type_index][i]]) {
                check_set[matrix[type_index][i]] = 1;
            } else {
                rc = false;
                break;
            }
        }
    } else if (type == TYPE_COL) {
        for (int i = 0; i < size; i++) {
            if (!check_set[matrix[i][type_index]]) {
                check_set[matrix[i][type_index]] = 1;
            } else {
                rc = false;
                break;
            }
        }
    }
    return rc;
}    

bool checkValid(int** matrix, int matrixSize, int* matrixColSize) {

    bool rc = true, check = true;
    int *check_set = NULL;

    if (matrixSize) {

       check_set = (int *) calloc(matrixSize+1, sizeof(int));

       for (int i = 0; i < matrixSize; i++) {
           check = check_row_column(matrix, i, TYPE_ROW, matrixColSize[i], check_set);

            if (check == false) {
               rc = check;
               goto EXIT_POINT;
           }
           ZERO_OUT_ARR(check_set, matrixSize+1);
       }

       for (int i = 0; i < *matrixColSize; i++) {
           check = check_row_column(matrix, i, TYPE_COL, matrixSize, check_set);

           if (check == false) {
               rc = check;
               goto EXIT_POINT;
           }
           ZERO_OUT_ARR(check_set, matrixSize+1);
       }
    }
EXIT_POINT:;
    free(check_set); 
    return rc;
}
