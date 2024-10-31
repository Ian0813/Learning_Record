/*
 * =====================================================================================
 *
 *       Filename:  1277_count_square_submatrices_with_all_ones.c
 *
 *    Description:  count square submatrices with all ones
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
#include <stdint.h>

typedef enum {false, true} bool;

static bool check_all_one(int **matrix, int row, int column, int r_size, int c_size) {

    bool ret = true;
    int8_t check = 1;

    for (int i = row; i < r_size+row; i++) {
        for (int j = column; j < c_size+column; j++) {
            if (!(matrix[i][j])) {
                check = false; 
                break;
            }
        }
        if (!check)
            break; 
    }
    return check;
}

int countSquares(int** matrix, int matrixSize, int* matrixColSize) {
    
    int units = 0; 
    int counter = true;

    units = matrixSize <= *matrixColSize ? matrixSize : *matrixColSize;

    while (units != 0) {

        if (units)
            units--;

        for (int x = 0; x < matrixSize-units; x++) {
            for (int y = 0; y < matrixColSize[x]-units; y++) {
                if (check_all_one(matrix, x, y, units+1, units+1)) {
                    counter++; 
                }
            }
        }
    }
    return counter;
}
