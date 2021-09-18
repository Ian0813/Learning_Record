/*
 * =====================================================================================
 *
 *       Filename:  101_symmetric_tree.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2023年10月28日 04時56分23秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct TreeNode {
    int val;
	struct TreeNode *left;
    struct TreeNode *right;
};

#if 0
void depth_first_search(struct TreeNode *node, int *array, int *index) {
    if (node != NULL) {
        array[(*index)++] = node->val;
		depth_first_search(node->left);
		depth_first_search(node->right);
	}
	array[(*index)++] = 0;
	return;
}
#endif

struct TreeNode *create(struct TreeNode *node, int val) {
    if (node == NULL) {
        node = (struct TreeNode *) malloc(sizeof(struct TreeNode));
		node->val = val;
		node->left = node->right = NULL;
    } else if (node->val < val) {
        node->right = create(node->right, val);
    } else if (node->val >= val) {
        node->left = create(node->left, val);
	}
	return node;
}

void traversal(struct TreeNode *node) {
    if (node != NULL) {
        printf("%d ", node->val);
		traversal(node->left);
		traversal(node->right);
	}
	return;
}

void release(struct TreeNode *node) {
    if (node != NULL) {
		release(node->left);
		release(node->right);
		free(node);
	}
	return;
}

int main(void) {

    struct TreeNode *node = NULL;

    int arr[5] = {-10, -3, 0, 5, 9};

    int root_num = 5/2;

	node = create(node, arr[root_num]);

	for (int i = 0; i < root_num; i++) {
        node = create(node, arr[i]);
	}

	for (int i = root_num + 1; i < 5; i++) {
        node = create(node, arr[i]);
	}

	traversal(node);
    printf("\n");

	release(node);

    return 0;
}
