/*
 * =====================================================================================
 *
 *       Filename:  3402_minimum_operations_to_make_columns_strictly_increasing.c
 *
 *    Description:  minimum operations to make columns strictly increasing
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

int minimumOperations(int** grid, int gridSize, int* gridColSize) {

    int count = 0, temp = 0;

    for (int i = 0; i < *gridColSize; i++) {
        for (int j = 1; j < gridSize; j++) {
            if (grid[j][i] <= grid[j-1][i]) {
                temp = grid[j][i] == grid[j-1][i] ? 1 : ((grid[j-1][i] - grid[j][i]) + 1);
                grid[j][i] += temp;
                count += temp;
            }
        }
    }
    return count;
}
