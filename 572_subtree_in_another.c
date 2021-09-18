/*
 * =====================================================================================
 *
 *       Filename:  572_subtree_in_another.c
 *
 *    Description:  Subtree of another tree 
 *
 *         Author:  Ian
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

struct TreeNode {

    int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

typedef struct TreeNode *TreePtr;

int comparison(TreePtr root, TreePtr sub) {

    if (sub == NULL && root == NULL) {
        return 1;
	}
    if (sub != NULL && root != NULL) {
       printf("[%s] root: %d, sub: %d\n", __func__, root->val, sub->val);
       return (root->val == sub->val) && comparison(root->left, sub->left) && comparison(root->right, sub->right); 
	}
	return 0;
}

int traversal(TreePtr root, TreePtr sub) {

    int rc = 0;

    if (root != NULL) {
        printf("root: %d, sub: %d\n", root->val, sub->val);
        rc = comparison(root, sub);
        rc = rc == 1 ? rc : traversal(root->left, sub);	
	    rc = rc == 1 ? rc : traversal(root->right, sub);	
	}
	return rc;
}


bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {

    if (subRoot == NULL) {
        return true;
	}

	return traversal(root, subRoot);
}

TreePtr create(TreePtr node, int val) {

    if (node == NULL) {
        node = (TreePtr) malloc(sizeof(struct TreeNode));
		node->val = val;
		node->left = NULL;
		node->right = NULL;
	} else if (node->val > val) {
        node->left = create(node->left, val);
	} else if (node->val <= val) {
        node->right = create(node->right, val);
	}
	return node;
}

void release(TreePtr node) {

    if (node != NULL) {

        release(node->left);
        release(node->right);
		free(node);
	}
	return;
}

void walk(TreePtr node) {

    if (node != NULL) {
        printf("%d ", node->val);
        walk(node->left);
        walk(node->right);
    }
	return;
}

#define MAIN 30 
#define SUB 5

int main(void) {

    TreePtr root = NULL, sub = NULL;  

    srand(time(NULL));

	for (int i = 0; i < MAIN; i++) {
        root = create(root, 1);
	}
	root = create(root, 2);

	for (int i = 0; i < SUB; i++) {
        sub = create(sub, 1);
    }
	sub = create(sub, 2);

	walk(root);
    printf("\n");
	walk(sub);
    printf("\n");

	printf("isSubtree: %d\n", isSubtree(root, sub));

	release(root);
	release(sub);

	return 0;
}

