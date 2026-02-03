/*
 * =====================================================================================
 *
 *       Filename:  1895_largest_magic_square.c
 *
 *    Description:  largest magic square
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
//#include <sys/param.h>

typedef enum {false, true} bool;

#define DIAGONAL_LEN 2
#define DIRECTION_LEN DIAGONAL_LEN

typedef enum {
    ROW_INDEX = 0,
    COL_INDEX = 1
} direction_t;

typedef enum {
    LEFT_INDEX = 0,
    RIGHT_INDEX = 1
} diagonal_t;

#define MAX(a, b) ((a) > (b) ? (a) : (b))

static bool check_matrix(int **grid, int row_index, int col_index, int len, int row_boundary, int col_boundary, int **sums) {

    int diag[DIAGONAL_LEN] = {0}, base = 0;
    bool rc = false;

    if ((row_index + (len-1)) < row_boundary && (col_index + (len-1)) < col_boundary) {

        memset(sums[ROW_INDEX], 0, sizeof(int) * len);
        memset(sums[COL_INDEX], 0, sizeof(int) * len);

        for (int i = row_index; i < (row_index + len); i++) {
            for (int j = col_index; j < (col_index + len); j++) {
                sums[ROW_INDEX][i - row_index] += grid[i][j];
                sums[COL_INDEX][j - col_index] += grid[i][j];
            }
        }

        base = sums[ROW_INDEX][0];

        for (int i = 0; i < len; i++) {
            if (sums[ROW_INDEX][i] != base)
                return rc; 
        }
        
        for (int i = 0; i < len; i++) {
            if (sums[COL_INDEX][i] != base)
                return rc; 
        }

        for (int i = col_index, j = row_index; i < (len + col_index); i++, j++) {
            diag[LEFT_INDEX] += grid[j][i];
        }

        for (int i = col_index + (len-1), j = row_index; i >= col_index; i--, j++) {
            diag[RIGHT_INDEX] += grid[j][i];
        }

        if (diag[LEFT_INDEX] != base || base != diag[RIGHT_INDEX])
            return rc;

        rc = true;
    }

    return rc;
}

static int **allocate_spaces(int len) {

    int **ptr = NULL;

    ptr = (int **) calloc(DIRECTION_LEN, sizeof(int *));

    ptr[ROW_INDEX] = (int *) calloc(len, sizeof(int));
    ptr[COL_INDEX] = (int *) calloc(len, sizeof(int));

    return ptr;
}

int largestMagicSquare(int** grid, int gridSize, int* gridColSize) {

    int square_len = MAX(gridSize, *gridColSize), area = 1;
    int **sums = NULL;

    if (square_len > 1 && gridSize != *gridColSize)
        square_len -= (square_len % 2);

    while (square_len > 1) {

        sums = allocate_spaces(square_len);

        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridColSize[i]; j++) {
                if (check_matrix(grid, i, j, square_len, gridSize, gridColSize[i], sums)) {
                    area = square_len;
                    square_len = 1;
                    break; 
                }
            }

            if (square_len == 1)
                break; 
        }
        free(sums);
        square_len--;
    }

    return area;
}
