/*
 * =====================================================================================
 *
 *       Filename:  655 print binary tree.c
 *
 *    Description:  print binary tree
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
#include <limits.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define MAX_DIGIT_LEN (CHAR_BIT)
#define MAX(a, b) ((a) > (b) ? a : b)
#define VAL_TO_CH(val) ((val)+'0')

typedef enum {
    PRE_ORDER = 0,
    IN_ORDER = 1,
    POST_ORDER = 2
} order_t;

typedef enum {
    NODE_ROOT = 0,
    NODE_LEFT = 1,
    NODE_RIGHT = 2,
} node_type;

static int get_tree_height(struct TreeNode *node) {

    int lcount = 0, rcount = 0;

    if (node) {
        lcount += get_tree_height(node->left);
        rcount += get_tree_height(node->right);
        return 1 + MAX(lcount, rcount);
    }

    return 0;
}

static void print_tree(struct TreeNode *node) {

    if (node) {
        print_tree(node->left);
        printf("%d ", node->val);
        print_tree(node->right);
    }
    return;
}

static char ***matrix_allocate(int row_size, int column_size) {

    char ***result = NULL;

    result = (char ***) calloc(row_size, sizeof(char **));

    for (int i = 0; i < row_size; i++) {

        result[i] = (char **) calloc(column_size, sizeof(char *)); 

        for (int j = 0; j < column_size; j++) {
            result[i][j] = (char *) calloc(MAX_DIGIT_LEN, sizeof(char)); 
        }
    }
    return result;
}

static char *numeric_to_str(int val) {

    char c = '\0', temp[MAX_DIGIT_LEN] = {0}, *ptr = NULL;
    int index = 0, negative = 0, pindex = 0;

    ptr = (char *) calloc(MAX_DIGIT_LEN, sizeof(char));

    if (!ptr)
        return NULL;

    negative = val < 0 ? 1 : 0;
    val = negative ? -val : val;

    do {
        temp[index++] = VAL_TO_CH((val%10));
        val /= 10;
    } while (val);

    for (int i = 0, j = index-1; i < j; i++, j--) {
        c = temp[i];
        temp[i] = temp[j];
        temp[j] = c;
    }

    if (negative)
        ptr[pindex++] = '-';

    memcpy(&ptr[pindex], temp, index);
    return ptr;
}

static int get_power_of_two(int exp) {

    int value = 1;

    while (exp) {
        value *= 2;
        exp--;
    }
    return value;
}

static void put_to_matrix(struct TreeNode *node, char ***matrix, int height, int column_size, int prev_pos, int depth, node_type type) {

    int pos = 0;

    if (node) {

        if (type == NODE_ROOT) {
            pos = (column_size-1) / 2;
            matrix[depth][pos] = numeric_to_str(node->val);
        } else {
            if (type == NODE_LEFT) {
                pos = prev_pos - get_power_of_two((height-1) - (depth-1) - 1);
                matrix[depth][pos] = numeric_to_str(node->val); 
            } else if (type == NODE_RIGHT) {
                pos = prev_pos + get_power_of_two((height-1) - (depth-1) - 1);
                matrix[depth][pos] = numeric_to_str(node->val); 
            }
        }

        put_to_matrix(node->left, matrix, height, column_size, pos, depth+1, NODE_LEFT);
        put_to_matrix(node->right, matrix, height, column_size, pos, depth+1, NODE_RIGHT);
    }

    return;
}    

char*** printTree(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {

    int height = 0, row_size = 0, column_size = 0;
    char ***result = NULL;

    if (root) {

        row_size = height = get_tree_height(root);
        column_size = get_power_of_two(height) - 1;
        result = matrix_allocate(row_size, column_size);
        put_to_matrix(root, result, height, column_size, 0, 0, NODE_ROOT);

        *returnSize = row_size;
        *returnColumnSizes = (int *) calloc(column_size, sizeof(int)); 

        for (int i = 0; i < column_size; i++) {
            (*returnColumnSizes)[i] = column_size;    
        }
    }
    return result;
}
