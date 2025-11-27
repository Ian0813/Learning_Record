/*
 * =====================================================================================
 *
 *       Filename:  59_spiral_matrix_ii.c
 *
 *    Description:  spiral matrix ii
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

typedef enum {false, true} bool;

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define COORDINATE_LEN 2

typedef enum {
   DIRECTION_R = 0,
   DIRECTION_D = 1,
   DIRECTION_L = 2,
   DIRECTION_U = 3,
   DIRECTION_SIZE
} direction_t;

typedef enum {
    INDEX_X = 0,
    INDEX_Y = 1,
} coordinate_t;

struct track_info {
    int cur_value;
    int boundary;
    int position[COORDINATE_LEN];
};

static int **matrix_allocate(int n, int *returnSize, int **returnColumnSizes) {

    int **matrix = NULL;

    if (returnColumnSizes) {

        *returnSize = n;
        (*returnColumnSizes) = (int *) calloc(n, sizeof(int));

        for (int i = 0; i < n; i++) {
            (*returnColumnSizes)[i] = n;
        }
    }

    if ((matrix = (int **) calloc(n, sizeof(int *)))) {
        for (int i = 0; i < n; i++) {
            matrix[i] = (int *) calloc(n, sizeof(int)); 
        }
    }
    return matrix;
}

static bool matrix_try_fill(int **matrix, direction_t direction, struct track_info *tracker) {

    bool rc = false;
    int x = 0, y = 0; 

    if (!tracker)
        return rc;

    if (tracker->position[INDEX_X] >= tracker->boundary || tracker->position[INDEX_Y] >= tracker->boundary)
        return rc;

    if (matrix[tracker->position[INDEX_X]][tracker->position[INDEX_Y]])
        return rc;

    rc = true;

    switch (direction) {
        case DIRECTION_R:

            x = tracker->position[INDEX_X];

            for (y = tracker->position[INDEX_Y]; y < tracker->boundary; y++) {
                if (matrix[x][y])
                    break;
                matrix[x][y] = tracker->cur_value;
                tracker->cur_value++;
            }
            tracker->position[INDEX_Y] = y-1;
            tracker->position[INDEX_X] = x+1;
        break; 
        case DIRECTION_D:

            y = tracker->position[INDEX_Y];

            for (x = tracker->position[INDEX_X]; x < tracker->boundary; x++) {
                if (matrix[x][y])
                    break;
                matrix[x][y] = tracker->cur_value;
                tracker->cur_value++;
            }    

            tracker->position[INDEX_Y] = y-1;
            tracker->position[INDEX_X] = x-1;
        break; 
        case DIRECTION_L:
            x = tracker->position[INDEX_X];

            for (y = tracker->position[INDEX_Y]; y >= 0; y--) {
                if (matrix[x][y])
                    break;
                matrix[x][y] = tracker->cur_value;
                tracker->cur_value++;
            }

            tracker->position[INDEX_Y] = y+1;
            tracker->position[INDEX_X] = x-1;
        break; 
        case DIRECTION_U:
            y = tracker->position[INDEX_Y];

            for (x = tracker->position[INDEX_X]; x >= 0; x--) {
                if (matrix[x][y])
                    break;
                matrix[x][y] = tracker->cur_value;
                tracker->cur_value++;
            }    
            tracker->position[INDEX_Y] = y+1;
            tracker->position[INDEX_X] = x+1;
        break; 
    }

    return rc;
}

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) {

    int **matrix = NULL;
    struct track_info tracker = {.boundary = n, .cur_value = 0, .position = {0}};

    matrix = matrix_allocate(n, returnSize, returnColumnSizes);

    if (matrix) {

        tracker.cur_value = 1;

        for (int i = 0; i < DIRECTION_SIZE; i = ((i+1) % DIRECTION_SIZE)) {
            if (!matrix_try_fill(matrix, i, &tracker)) {
                break;   
            }    
        }
#if 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", matrix[i][j]);
            }
            putchar('\n');
        }
        putchar('\n');
#endif
    }

    return matrix;    
}
