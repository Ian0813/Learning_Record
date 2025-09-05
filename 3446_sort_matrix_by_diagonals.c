/*
 * =====================================================================================
 *
 *       Filename:  3446_sort_matrix_by_diagonals.c
 *
 *    Description:  sort matrix by diagonals
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
#include <stdint.h>
#include <unistd.h>
#include <limits.h>
#include <stddef.h>
#include <stdbool.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

typedef enum {
    LEFT_BOTTOM = 0,
    RIGHT_ABOVE = 1
} diagonal_type_t;

typedef enum {
    SORT_INCREASE = 0,
    SORT_DECREASE = 1
} sort_type_t;

struct matrix_square {
    void **matrix;
};

struct ptrarr {
    ptrdiff_t *arr;
    int arrlen;
    int size;
};

static void swap(int *v1, int *v2) {

    int temp = *v1;

    *v1 = *v2;
    *v2 = temp;

    return;
}

static void quick_sort(ptrdiff_t *arr, int head, int end, sort_type_t type) {

    int last = head, tail = end-1; 
    bool rc = true;

    if (head < end) {

        while (tail > last) {

            if (type == SORT_INCREASE) {
                rc = *((int *) arr[head]) > *((int *) arr[tail]);
            } else if (type == SORT_DECREASE) {
                rc = *((int *) arr[head]) < *((int *) arr[tail]);
            }

            printf("[%s] %d, %d\n", __func__, *((int *) arr[head]), *((int *) arr[tail]));

            if (rc) {
                last++;
                swap((int *) arr[last], (int *) arr[tail]);
                continue;
            }
            tail--;
        }

        swap((int *) arr[head], (int *) arr[tail]);
        quick_sort(arr, head, last, type);
        quick_sort(arr, last+1, end, type);
    }

    return;
}

static int **alloc_matrix(int row, int column) {

    int **ptr = NULL;

    if (row && column) {
        ptr = (int **) calloc(row, sizeof(int *));  

        for (int i = 0; i < row; i++) {
            ptr[i] = (int *) calloc(column, sizeof(int)); 
        } }
    return ptr;
}

static void ptrarr_init(struct ptrarr *pinfo, int size) {

    if (!pinfo)    
        return;

    pinfo->arr = (ptrdiff_t *) calloc(size, sizeof(ptrdiff_t));
    pinfo->size = size;
    pinfo->arrlen = 0;

    return;
}

static void ptrarr_free(struct ptrarr *pinfo) {

    if (!pinfo)    
        return;

    if (pinfo->arr)
        free(pinfo->arr);

    return;
}

static void traverse_diagonal(int **matrix, int row, int column, diagonal_type_t diagonal, struct ptrarr *pinfo) {

    if (diagonal == LEFT_BOTTOM) {
        for (int i = 0; i < row; i++) {
            for (int offset = 0; offset < column; offset++) {

                if (!((i+offset) < row))
                    break;

                pinfo->arr[pinfo->arrlen++] = (ptrdiff_t) &matrix[i+offset][offset];
            }

            quick_sort(pinfo->arr, 0, pinfo->arrlen-1, SORT_DECREASE);
            for (int k = 0; k < pinfo->arrlen; k++) {
                printf("%d ", *(int *) pinfo->arr[k]);
            }    
            putchar('\n');
        }
    } else if (diagonal == RIGHT_ABOVE) {

        for (int i = 0; i < row; i++) {
            for (int j = i+1, offset = 0; j < column; offset++) {

                if ((j+offset) < column)
                    break;

                pinfo->arr[pinfo->arrlen++] = (ptrdiff_t) &matrix[offset][j+offset];
            }

            quick_sort(pinfo->arr, 0, pinfo->arrlen-1, SORT_INCREASE);
            for (int k = 0; k < pinfo->arrlen; k++) {
                printf("%d ", *(int *) pinfo->arr[k]);
            }    
            putchar('\n');
        }
    }

    return;
}

int** sortMatrix(int** grid, int gridSize, int* gridColSize, int* returnSize, int** returnColumnSizes) {

    int **result = NULL;
    struct ptrarr pinfo = {0};

    //result = alloc_matrix(gridSize, *gridColSize);

    ptrarr_init(&pinfo, gridSize);

    traverse_diagonal(grid, gridSize, *gridColSize, LEFT_BOTTOM, &pinfo);
    traverse_diagonal(grid, gridSize, *gridColSize, RIGHT_ABOVE, &pinfo);

    ptrarr_free(&pinfo);

    return result;
}
