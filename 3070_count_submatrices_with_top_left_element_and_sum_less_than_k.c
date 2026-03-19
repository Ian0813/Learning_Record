/*
 * =====================================================================================
 *
 *       Filename:  3070_count_submatrices_with_top_left_element_and_sum_less_than_k.c
 *
 *    Description:  count submatrices with top left element and sum less than k
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

static int extend_count(int **grid, int max_depth, int target, int k, int *record) {

    int count = 0, value = 0;

    for (int i = 0; i < max_depth; i++) {

        record[i] += grid[i][target];  
        value += record[i];

        if (value <= k) {
            count++;
            continue;
        }
        break;
    }
    
    return count;
}

int countSubmatrices(int** grid, int gridSize, int* gridColSize, int k) {

    int count = 0, *record = NULL;

    record = (int *) calloc(gridSize, sizeof(int));

    for (int i = 0; i < *gridColSize; i++) {
        if (record[0] <= k) {
            count += extend_count(grid, gridSize, i, k, record);
        }
    }

    free(record);

    return count;
}
