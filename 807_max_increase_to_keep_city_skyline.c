/*
 * =====================================================================================
 *
 *       Filename:  807_max_increase_to_keep_city_skyline.c
 *
 *    Description:  max increase to keep city skyline
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
#include <limits.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef enum {
    LOOP_ROW = 0,
    LOOP_COL = 1
} loop_type;

static void get_max_values(int **grid, int gsize, int *values, loop_type ltype) {

    int index = 0, max = INT_MIN;

    if (ltype != LOOP_ROW && ltype != LOOP_COL)
        return;

    if (ltype == LOOP_ROW) {
        for (int i = 0; i < gsize; i++) {
            for (int j = 0; j < gsize; j++) {
                if (grid[i][j] > max) {
                    max = grid[i][j]; 
                }
            }
            values[index++] = max;
            max = INT_MIN; 
        }
    } else {
        for (int i = 0; i < gsize; i++) {
            for (int j = 0; j < gsize; j++) {
                if (grid[j][i] > max) {
                    max = grid[j][i]; 
                }
            }
            values[index++] = max;
            max = INT_MIN; 
        }
    }
    return;
}


int maxIncreaseKeepingSkyline(int** grid, int gridSize, int* gridColSize) {

    int *max_rvalues = NULL, *max_cvalues = NULL;
    int increase_value = 0; 

    if (gridSize) {

        max_rvalues = (int *) calloc(gridSize, sizeof(int)); 
        max_cvalues = (int *) calloc(gridSize, sizeof(int)); 

        get_max_values(grid, gridSize, max_rvalues, LOOP_ROW);
        get_max_values(grid, gridSize, max_cvalues, LOOP_COL);

        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridSize; j++) {
                increase_value += (MIN(max_rvalues[i], max_cvalues[j]) - grid[i][j]);
            }    
        }

        free(max_rvalues);
        free(max_cvalues);
    }

    return increase_value;
}
