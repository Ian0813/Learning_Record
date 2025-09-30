/*
 * =====================================================================================
 *
 *       Filename:  3242 design neighbor sum service.c
 *
 *    Description:  design neighbor sum service
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

#define PAIR_LEN 2
#define GET_VALUE(obj, row, col) (obj->boundaries[BOUNDARY_ROW] > row && obj->boundaries[BOUNDARY_COL] > col\
                                 && row >= 0 && col >= 0) ? obj->grid[row][col] : 0;

typedef enum {
    BOUNDARY_ROW = 0,
    BOUNDARY_COL = 1,
    BOUNDARY_LEN,
} boundary_type;

enum {
    INDEX_ROW = 0,
    INDEX_COL = 1,
};

struct coordinate {
    int row;
    int column;
};

typedef struct {
    int **grid;
    boundary_type boundaries[BOUNDARY_LEN];
    struct coordinate *pos;
} NeighborSum;

static void coordinate_init(NeighborSum *obj) {

    if (obj) {

        for (int i = 0; i < obj->boundaries[BOUNDARY_ROW]; i++) {
            for (int j = 0; j < obj->boundaries[BOUNDARY_COL]; j++) {
                obj->pos[obj->grid[i][j]].row = i;
                obj->pos[obj->grid[i][j]].column = j;
            }
        }
    }

    return;
}

NeighborSum* neighborSumCreate(int** grid, int gridSize, int* gridColSize) {

    NeighborSum *obj = NULL;

    obj = (NeighborSum *) malloc(sizeof(*obj));

    if (obj) {
        obj->grid = grid;
        obj->boundaries[BOUNDARY_ROW] = gridSize;
        obj->boundaries[BOUNDARY_COL] = *gridColSize;
        obj->pos = (struct coordinate *) calloc((gridSize*gridSize), sizeof(struct coordinate));
        coordinate_init(obj);
    }

    return obj;
}

int neighborSumAdjacentSum(NeighborSum* obj, int value) {

    int sum = 0;

    if (obj) {
        sum += GET_VALUE(obj, obj->pos[value].row-1, obj->pos[value].column);
        sum += GET_VALUE(obj, obj->pos[value].row+1, obj->pos[value].column);
        sum += GET_VALUE(obj, obj->pos[value].row, obj->pos[value].column-1);
        sum += GET_VALUE(obj, obj->pos[value].row, obj->pos[value].column+1);
    }

    return sum;
}

int neighborSumDiagonalSum(NeighborSum* obj, int value) {

    int sum = 0;

    if (obj) {
        sum += GET_VALUE(obj, obj->pos[value].row-1, obj->pos[value].column-1);
        sum += GET_VALUE(obj, obj->pos[value].row-1, obj->pos[value].column+1);
        sum += GET_VALUE(obj, obj->pos[value].row+1, obj->pos[value].column-1);
        sum += GET_VALUE(obj, obj->pos[value].row+1, obj->pos[value].column+1);
    }

    return sum;
}

void neighborSumFree(NeighborSum* obj) {

    if (obj) {
        free(obj->pos);  
        free(obj);    
    }
    return;
}

/**
 * Your NeighborSum struct will be instantiated and called as such:
 * NeighborSum* obj = neighborSumCreate(grid, gridSize, gridColSize);
 * int param_1 = neighborSumAdjacentSum(obj, value);

 * int param_2 = neighborSumDiagonalSum(obj, value);

 * neighborSumFree(obj);
*/
