/*
 * =====================================================================================
 *
 *       Filename:  200_number_of_islands.c
 *
 *    Description:  number of islands
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

typedef struct {
    int rindex;
    int cindex;
} Point;

typedef enum {
    LAND_EMPTY = '0',
    LAND_ISLAND = '1'
} LandType;

static void set_island_state(char **grid, int maxrow, int maxcol, Point *p) {

    Point temp = {0};

    if (!p)
        return;

    grid[p->rindex][p->cindex] = LAND_EMPTY;

    for (int i = p->rindex-1; i >= 0; i--) {
        if (grid[i][p->cindex] == LAND_ISLAND) {
            temp = (Point) {i, p->cindex};
            set_island_state(grid, maxrow, maxcol, &temp); 
            continue;
        }
        break;
    }

    for (int i = p->rindex+1; i < maxrow; i++) {
        if (grid[i][p->cindex] == LAND_ISLAND) {
            temp = (Point) {i, p->cindex};
            set_island_state(grid, maxrow, maxcol, &temp); 
            continue;
        }
        break;
    }

    for (int i = p->cindex-1; i >= 0; i--) {
        if (grid[p->rindex][i] == LAND_ISLAND) {
            temp = (Point) {p->rindex, i};
            set_island_state(grid, maxrow, maxcol, &temp); 
            continue;
        }
        break;
    }

    for (int i = p->cindex+1; i < maxcol; i++) {
        if (grid[p->rindex][i] == LAND_ISLAND) {
            temp = (Point) {p->rindex, i};
            set_island_state(grid, maxrow, maxcol, &temp); 
            continue;
        }
        break;
    }
    return;
}

int numIslands(char** grid, int gridSize, int* gridColSize) {

    int island_count = 0;
    Point p = {0};

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < *gridColSize; j++) {
            if (grid[i][j] == LAND_ISLAND) {
                p = (Point) {i, j}; 
                set_island_state(grid, gridSize, *gridColSize, &p);
                island_count++;
            }
        }
    }
    return island_count;
}
