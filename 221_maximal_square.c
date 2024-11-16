/*
 * =====================================================================================
 *
 *       Filename:  221_maximal_square.c
 *
 *    Description:  maximal square
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

struct {
    char zero;
    char one;
} number_sign = {.zero = '0', .one = '1'};

static bool check_all_ones(char **matrix, int row, int column, int side_len) {

    bool check = true;

    for (int i = row; i < side_len+row; i++) {
        for (int j = column; j < side_len+column; j++) {
            if (matrix[i][j] == number_sign.zero) {
                check = false;
                break;
            }
        }
        if (!check)
            break;
    }
    return check;
}

int maximalSquare(char** matrix, int matrixSize, int* matrixColSize) {

    int boundary = matrixSize <= *matrixColSize ? matrixSize : *matrixColSize;
    int units = 0;
    int maximal = 0;
    bool check = true, previous = false;

    while (units < boundary) {

        for (int i = 0; i < matrixSize-units; i++) {
            for (int j = 0; j < matrixColSize[i]-units; j++) {
                if (matrix[i][j] == number_sign.zero) {
                    check = false; 
                    continue;
                }
                if ((check = check_all_ones(matrix, i, j, units+1))) {
                    maximal = (units+1) * (units+1);
                    previous = true;
                    break;
                }
            }

            if (check) {
                break;
            }
        }

        if (!check && previous)
            break; 

        units++;
        check = true;
    }
    return maximal;
}
