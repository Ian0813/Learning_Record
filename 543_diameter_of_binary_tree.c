/*
 * =====================================================================================
 *
 *       Filename:  543_diameter_of_binary_tree.c
 *
 *    Description:  Diameter of binary tree  
 *
 *         Author:  Ian
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define MAX(a, b) (a > b ? a : b); 

/* Definition for a binary tree node. */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

typedef struct TreeNode *TreePtr;

int get_height(TreePtr node) {

    int left = 0, right = 0;

	if (node != NULL) {
        left = get_height(node->left);
        right = get_height(node->right);
        return 1 + MAX(left, right);
	}
	return 0;
}

int longest_path(TreePtr node) {

    int longest = 0, counter = 0;

	if (node != NULL) {
        longest = get_height(node->left) + get_height(node->right);
        longest = longest < (counter = longest_path(node->left)) ? counter : longest;
        longest = longest < (counter = longest_path(node->right)) ? counter : longest;
		return longest;
	}
	return 0;
}

int diameterOfBinaryTree(struct TreeNode* root) {
    return longest_path(root);
}

int main(void) {
    return 0;
}
