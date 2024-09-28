/*
 * =====================================================================================
 *
 *       Filename:  2352_equal_row_and_column_pairs.c
 *
 *    Description:  Equal row and column pairs  
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

#define COLUMN_HEAD_INDEX (0U)

typedef enum {false, true} bool;

static void compare(int *grid_row, int **compare_table, int row_size, int length, int *count) {

    int flag = 0;

    for (int row = 0; row < row_size; row++) {
 
        //*count = !memcmp(grid_row, compare_table[row], sizeof(length) * sizeof(int)) ? (*count+1) : *count;
        
        for (int len = 0; len < row_size; len++) {
            if (grid_row[len] != compare_table[row][len]) {
                flag = 1;
                break;
            }
        }
        *count = flag ? (*count) : (*count+1);
        flag = 0;
    }
    return;
}

static int ** get_compare_table(int **grid, int gridSize, int *gridColSize) {

    int **compare_table = NULL;
    int table_row = 0, table_column = 0; 

    if (gridSize) {
        compare_table = (int **) calloc(gridSize, sizeof(int *));

        for (int row = 0; row < gridSize; row++) {
            compare_table[row] = (int *) calloc(gridColSize[row], sizeof(int));
        }

        for (int column = 0, table_row = 0; column < gridColSize[COLUMN_HEAD_INDEX]; column++, table_row++) {
            for (int row = 0, table_column = 0; row < gridSize; row++, table_column++) {
                 compare_table[table_row][table_column] = grid[row][column];
            }
        }
    }
    return compare_table;
}

int equalPairs(int** grid, int gridSize, int* gridColSize) {

    int row = 0, column = 0;
    int **compare_table = NULL;
    int count = 0;

#if 1
    for (row; row < gridSize; row++) {

        for (column = 0; column < gridColSize[row]; column++) {
            printf("%d ", grid[row][column]);
        }
        putchar('\n');
    }
    putchar('\n');
#endif

    if (gridSize) {
        compare_table = get_compare_table(grid, gridSize, gridColSize);

        for (row = 0; row < gridSize; row++) {
            compare(grid[row], compare_table, gridSize, gridColSize[row], &count);
        }

        for (row = 0; row < gridSize; row++) {
            free(compare_table[row]);
        }
        free(compare_table);
    }

    return count;
}

int main(void) {

    int **arr = NULL; 
    int arr_size[] = {3, 3, 3};
    int count = 0;

    count = equalPairs(arr, 3, (int *) arr_size);
    printf("count: %d\n", count);

    return EXIT_SUCCESS;
}
