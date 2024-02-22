/*
 * =====================================================================================
 *
 *       Filename:  766_toeplitz_matrix.c
 *
 *    Description:  Toeplitz matrix  
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

bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize) {

    int row1 = 0, column1 = 0, row2 = 0, column2 = 0;
    int rc = true;

    for (int i = 0; i < (matrixSize-1) && rc; i++) {
        row1 = i;
        row2 = i+1;

        for (int j = 0; j < (*matrixColSize)-1; j++) {
            if (matrix[row1][j] != matrix[row2][j+1]) {
                rc = false;
                break;
            }
        }
    }
    return rc;
}
