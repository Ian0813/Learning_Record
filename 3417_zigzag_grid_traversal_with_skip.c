/*
 * =====================================================================================
 *
 *       Filename:  3417_zigzag_grid_traversal_with_skip.c
 *
 *    Description:  zigzag grid traversal with skip
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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define GET_ROW_TYPE(i) (((i)%2) ? ROW_ODD : ROW_EVEN)
#define GET_START(ploc, size) ((ploc+1) == size ? (size-2) : (size-1))

typedef enum {
   ROW_ODD = 0,
   ROW_EVEN = 1
} row_type; 

int* zigzagTraversal(int** grid, int gridSize, int* gridColSize, int* returnSize) {

    int *result = NULL, rlen = 0, ploc = 0;
    row_type rtype;

    result = (int *) calloc(gridSize * (*gridColSize), sizeof(int)); 

    for (int i = 0; i < gridSize; i++) {

        rtype = GET_ROW_TYPE(i);

        if (rtype == ROW_ODD) {
            for (int j = GET_START(ploc, gridColSize[i]); j >= 0; j -= 2) {
                result[rlen++] = grid[i][j];
            }
        } else if (rtype == ROW_EVEN) {
            for (int j = 0; j < gridColSize[i]; j += 2) {
                ploc = j; 
                result[rlen++] = grid[i][j];
            }
        }
    }    

    *returnSize = rlen;
    return result;
}

