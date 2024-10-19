/*
 * =====================================================================================
 *
 *       Filename:  3195_find_the_minimum_area_to_cover_all_ones_i.c
 *
 *    Description:  find the minimum area to cover all ones i.c
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
 *
 *         Author:  Ian
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <limits.h>

struct boundaries {
    int min;
    int max;
};

struct boundaries get_one_bycolumn(int **grid, int row_size, int column_size) {

    struct boundaries boundary = {.min = INT_MAX, .max = INT_MIN};
    int flag = 0;

    for (int i = 0; i < column_size; i++) {

        for (int j = 0; j < row_size; j++) {
            if (grid[j][i]) {
                boundary.min = i;
                flag = 1;
                break;
            }
        }
        if (flag)
            break; 
    }

    flag = 0;

    for (int i = column_size-1; i >= 0; i--) {

        for (int j = row_size-1; j >= 0; j--) {
            if (grid[j][i]) {
                boundary.max = i;
                flag = 1;
                break;
            }
        }
        if (flag)
            break; 
    }
    return boundary;
}

struct boundaries get_one_byrow(int **grid, int row_size, int column_size) {

    struct boundaries boundary = {.min = INT_MAX, .max = INT_MIN};
    int flag = 0;

    for (int i = 0; i < row_size; i++) {

        for (int j = 0; j < column_size; j++) {
            if (grid[i][j]) {
                boundary.min = i;
                flag = 1;
                break;
            }
        }
        if (flag)
            break; 
    }

    flag = 0;

    for (int i = row_size-1; i >= 0; i--) {

        for (int j = column_size-1; j >= 0; j--) {
            if (grid[i][j]) {
                boundary.max = i;
                flag = 1;
                break;
            }
        }
        if (flag)
            break; 
    }
    return boundary;

}

int minimumArea(int **grid, int gridSize, int* gridColSize) {

    struct boundaries row = {.min = INT_MAX, .max = INT_MIN}, column = {.min = INT_MAX, .max = INT_MIN}, temp = {.min = INT_MAX, .max = INT_MIN};
    int length = 0, width = 0;


    for (int i = 0; i < gridSize; i++) {

        temp = get_one_byrow(grid, gridSize, gridColSize[i]);

        if (temp.min < row.min) {
            row.min = temp.min; 
        }

        if (temp.max > row.max) {
            row.max = temp.max; 
        }

        temp = (struct boundaries) {INT_MAX, INT_MIN};

        temp = get_one_bycolumn(grid, gridSize, gridColSize[i]);

        if (temp.min < column.min) {
            column.min = temp.min; 
        }

        if (temp.max > column.max) {
            column.max = temp.max; 
        }

        temp = (struct boundaries) {INT_MAX, INT_MIN};
    }

    width = (row.max-row.min)+1; 
    length = (column.max-column.min)+1; 

    return (width*length);
}

int main(void) {
#if 0
    int grid[][2] = {{1, 0}, {0, 0}};
    int grid_size = 2;
    int gridColumn[] = {2, 2}; 
    int area = 0;

    area = minimumArea(grid, grid_size, gridColumn);

    printf("area: %d\n", area);
#endif
    return EXIT_SUCCESS;
}

