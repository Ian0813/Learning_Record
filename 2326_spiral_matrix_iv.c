/*
 * =====================================================================================
 *
 *       Filename:  2326_spiral_matrix_iv.c
 *
 *    Description:  Spiral matrix 
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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


static int **get_dimension_arr(int m, int n) {

    int **arr = NULL;

    arr = (int **) calloc(m, sizeof(int *));

    for (int i = 0; i < m; i++) {

        arr[i] = (int *) calloc(n, sizeof(int));

        for (int j = 0; j < n; j++) {
            arr[i][j] = -1;
        }
    }
    return arr;
}

static int *get_column_sizes(int m, int n) {

    int *column_sizes = NULL;

    column_sizes = (int *) calloc(m, sizeof(int));

    for (int i = 0; i < m; i++) {
        column_sizes[i] = n;
    }
    return column_sizes;
}

static int get_list_len(struct ListNode *head) {

    int len = 0;

    while (head) {
        len++; 
        head = head->next;
    }
    return len;
}


int** spiralMatrix(int m, int n, struct ListNode* head, int* returnSize, int** returnColumnSizes) {

    int **result = NULL;
    int top = 0, bottom = m-1, left = 0, right = n-1;

    result = get_dimension_arr(m, n);

    *returnSize = m;
    *returnColumnSizes = get_column_sizes(m, n);

    if (head) {

        while (head) {

            for (int i = left; head && i <= right; i++) {
                result[top][i] = head->val;
                head = head->next;
            }

            for (int i = top+1; head && i <= bottom; i++) {
                result[i][right] = head->val;
                head = head->next;
            }

            for (int i = right-1; head && i >= left; i--) {
                result[bottom][i] = head->val;
                head = head->next;
            }

            for (int i = bottom-1; head && i >= top+1; i--) {
                result[i][left] = head->val;
                head = head->next;
            }

            left += 1; 
            top += 1;
            right -= 1;
            bottom -= 1; 
        }
    }
    return result;
}
