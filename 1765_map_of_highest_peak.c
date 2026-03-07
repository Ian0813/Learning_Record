/*
 * =====================================================================================
 *
 *       Filename:  1765_map_of_highest_peak.c
 *
 *    Description:  map of highest peak
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

typedef enum {false, true} bool;
typedef enum { COLOR_B = 'B', COLOR_W = 'W'} color;

#define MAX_SIZE 3
#define SQUARE_SIZE 2
#define IS_CORRECT(bc, wc) ((bc > 1) && (wc > 1) ? false : true)

static bool check_square(char **grid, int col) {

    int black_count = 0, white_count = 0;

    for (int i = 0; i < SQUARE_SIZE; i++) {
        for (int j = col; j < (SQUARE_SIZE + col); j++) {
            grid[i][j] == COLOR_B ? (black_count++) : (white_count++);
        }
    }

    return IS_CORRECT(black_count, white_count);
}

bool canMakeSquare(char** grid, int gridSize, int* gridColSize) {

    bool rc = false;

    for (int i = 0; i < (MAX_SIZE - 1) && !rc; i++) {
        for (int j = 0; j < (MAX_SIZE - 1) && !rc; j++) {
            rc = check_square(&grid[i], j);
        }
    }

    return rc;
}
