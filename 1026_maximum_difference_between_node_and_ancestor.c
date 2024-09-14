/*
 * =====================================================================================
 *
 *       Filename:  1026_maximum_difference_between_node_and_ancestor.c
 *
 *    Description:  Maximum Difference Between Node And Ancestor
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
#include <sys/time.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define MAX(v1, v2) (v1 > v2 ? v1 : v2)
#define MIN(v1, v2) (v1 < v2 ? v1 : v2)

typedef struct TreeNode *NodePtr;

NodePtr create_node(NodePtr root, int value) {

    if (!root) {
        root = (NodePtr) malloc(sizeof(struct TreeNode));
        root->val = value;
        root->left = root->right = NULL;
    } else if (root->val >= value) {
        root->left = create_node(root->left, value);  
    } else {
        root->right = create_node(root->right, value);  
    }
    return root;
}

void preorder(NodePtr root) {

    if (root) {
        printf("%d ", root->val);
        preorder(root->left);
        preorder(root->right);
    }
    return;
}

void inorder(NodePtr root) {

    if (root) {
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
    return;
}

void postorder(NodePtr root) {

    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->val);
    }
    return;
}

void free_node(NodePtr root) {

    if (root) {
        free_node(root->left);
        free_node(root->right);
        free(root);
    }
    return;
}


static void get_max_min_value(NodePtr root, int *max, int *min) {

    if (root) {

        *max = MAX(root->val, *max);
        *min = MIN(root->val, *min);

        get_max_min_value(root->left, max, min);
        get_max_min_value(root->right, max, min);
    }
    return;
}

static void get_maxdifference(NodePtr root, int *max_difference, int *max, int *min) {

    if (root) {

        *max = *min = root->val;
        get_max_min_value(root, max, min);

        *max_difference = MAX(*max_difference, MAX(abs(root->val-*max), abs(root->val-*min)));

        get_maxdifference(root->left, max_difference, max, min);
        get_maxdifference(root->right, max_difference, max, min);
    }
    return;
}

int maxAncestorDiff(struct TreeNode* root) {

    int max = 0, min = 0, max_difference = 0;;

    if (root) {
        get_maxdifference(root, &max_difference, &max, &min);
    }
    return max_difference;
}

#define NODES_NUM 1000 

int main(void) {

    struct timeval tinfo = {0};
    NodePtr root = NULL;
    int max = 0, min = 0, max_difference = 0;

    gettimeofday(&tinfo, NULL);
    srand(tinfo.tv_sec + tinfo.tv_usec);

    for (int i = 0; i < NODES_NUM; i++) {
        root = create_node(root, rand()%1000000);
    }

    //preorder(root);
    //putchar('\n');

    inorder(root);
    putchar('\n');

    //postorder(root);
    //putchar('\n');

    max = min = root->val;
    get_maxdifference(root, &max_difference, &max, &min);
    printf("max: %d, min: %d, max difference: %d\n", max, min, max_difference);

    free_node(root);

    return EXIT_SUCCESS;
}
