/*
 * =====================================================================================
 *
 *       Filename:  2658_maximum_number_of_fish_in_a_grid.c
 *
 *    Description:  maximum number of fish in a grid
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

#define MAX(a, b) ((a) < (b) ? (b) : (a))

typedef struct {
    int rindex;
    int cindex;
} Point;

static int get_fish_number(int **grid, int maxrow, int maxcol, Point *p) {

    int value = 0;
    Point temp = {0};

    if (!p)
        return value;    

    value += grid[p->rindex][p->cindex];
    grid[p->rindex][p->cindex] = 0;

    for (int i = p->cindex-1; i >= 0; i--) {
        if (grid[p->rindex][i]) {
            temp = (Point) {p->rindex, i};  
            value += get_fish_number(grid, maxrow, maxcol, &temp);
            continue;
        }
        break;
    }    

    for (int i = p->cindex+1; i < maxcol; i++) {
        if (grid[p->rindex][i]) {
            temp = (Point) {p->rindex, i};  
            value += get_fish_number(grid, maxrow, maxcol, &temp);
            continue;
        }
        break;
    }    

    for (int i = p->rindex-1; i >= 0; i--) {
        if (grid[i][p->cindex]) {
            temp = (Point) {i, p->cindex};  
            value += get_fish_number(grid, maxrow, maxcol, &temp);
            continue;
        }
        break;
    }

    for (int i = p->rindex+1; i < maxrow; i++) {
        if (grid[i][p->cindex]) {
            temp = (Point) {i, p->cindex};  
            value += get_fish_number(grid, maxrow, maxcol, &temp);
            continue;
        }
        break;
    }    

    return value;
}

int findMaxFish(int** grid, int gridSize, int* gridColSize) {

    int max = 0, value = 0;
    Point p = {0};

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < *gridColSize; j++) {
            if (grid[i][j]) {
                p = (Point) {i, j};
                value = get_fish_number(grid, gridSize, *gridColSize, &p);
                max = MAX(max, value);
            }    
        }
    }

    return max;
}
