/*
 * =====================================================================================
 *
 *       Filename:  797 all paths from source to target.c
 *
 *    Description:  all paths from source to target
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

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

typedef enum {false, true} bool;

#define GET BOUNDARY(graphSize) (graphSize-1)

struct array_pointer {
    int **array;
    int temp[BUFSIZ];
    int column_size[BUFSIZ];
    int row_index;
    int temp_index; 
};

#define MAX_LINK_SIZE 15

static void dfs_graph(int **graph, int row, int *columns, int boundary, struct array_pointer *result) {

    if (row < boundary-1) {
        for (int i = 0; i < columns[row]; i++) {
            result->temp[result->temp_index++] = row;
            dfs_graph(graph, graph[row][i], columns, boundary, result);
            result->temp_index--;
        }     
    } else if (row == boundary-1) {
        result->temp[result->temp_index++] = row;
        result->array[result->row_index] = (int *) calloc(result->temp_index, sizeof(int));
        result->column_size[result->row_index] = result->temp_index;
        memcpy(result->array[result->row_index], result->temp, sizeof(int)*result->temp_index);
        result->row_index++;
        result->temp_index--;
    }
    return;
}
      
int** allPathsSourceTarget(int** graph, int graphSize, int* graphColSize, int* returnSize, int** returnColumnSizes) {

    struct array_pointer result;

    memset(&result, 0, sizeof(struct array_pointer));
    result.array = (int **) calloc(BUFSIZ, sizeof(int *));

    if (graphColSize) {
        dfs_graph(graph, 0, graphColSize, graphSize, &result);
    }
    *returnSize = result.row_index;
    *returnColumnSizes = (int *) calloc(result.row_index, sizeof(int));
    memcpy(*returnColumnSizes, result.column_size, result.row_index*sizeof(int));
    return result.array;
}

int main(void) {
    return EXIT_SUCCESS;
}
