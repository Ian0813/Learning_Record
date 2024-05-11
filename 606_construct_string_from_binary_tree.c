/*
 * =====================================================================================
 *
 *       Filename:  606_construct_string_from_binary_tree.c
 *
 *    Description:  Construct string from binary tree  
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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#ifdef BUFSIZ
#undef BUFSIZ
#define BUFSIZ 30000
#endif

int get_height(struct TreeNode *node) {

    int lh = 0, rh = 0;

    if (node) {
        lh = get_height(node->left);
        rh = get_height(node->right);
        return 1 + (lh > rh ? lh : rh);
    }
    return 0;
}

void traversal_str(struct TreeNode *node, char *str, int *depth) {

    if (node) {

        sprintf(str+strlen(str), "(%d", node->val);

        if (node->left) {
            traversal_str(node->left, str, depth);
        } else if (node->right) {
            sprintf(str+strlen(str), "()");
        }

        if (node->right) {
            traversal_str(node->right, str, depth);
        }

        sprintf(str+strlen(str), ")");
    }
    return;
}

char* tree2str(struct TreeNode* root) {

    char lstr[BUFSIZ] = {0}, rstr[BUFSIZ] = {0};
    char *result = (char *) malloc(sizeof(char) * BUFSIZ);

    int ldiff = 0, rdiff = 0;

    memset(result, 0, sizeof(char) * BUFSIZ);

    if (root) {

        if (root->left) {
            traversal_str(root->left, lstr, &ldiff);
        } else if (root->right) {
            sprintf(lstr, "()");
        }

        if (root->right) {
            traversal_str(root->right, rstr, &rdiff);
        }
        sprintf(result, "%d%s%s", root->val, lstr, rstr);
    }
    return result;
}
