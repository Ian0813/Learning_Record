/*
 * =====================================================================================
 *
 *       Filename:  2096_step_by_step_directions_from_a_binary_tree_node_to_another.c
 *
 *    Description:  Step by step directions from a binary tree node to another  
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
#include <limits.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode *NodePtr;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#ifdef BUFSIZ
#undef BUFSIZ
#define BUFSIZ 100000
#endif

NodePtr bst_append(NodePtr node, int val) {

    if (!node) {
        node = (NodePtr) malloc(sizeof(struct TreeNode));
        node->val = val;
        node->left = node->right = NULL;
    } else if (node->val >= val) {
        node->left = bst_append(node->left, val); 
    } else if (node->val < val) {
        node->right = bst_append(node->right, val); 
    }
    return node;
}

void inorder(NodePtr node) {

    if (node) {
        inorder(node->left);
        printf("%d ", node->val);
        inorder(node->right);
    }
    return;
}

NodePtr find_node(NodePtr node, int val, int *collect, int *path, int *index) {

    NodePtr rc = NULL;
    if (node) {

        if (!rc) {
            rc = find_node(node->left, val, collect, path, index);
        }

        if (!rc) {
            rc = find_node(node->right, val, collect, path, index);
        }

        if (node->val == val) {
            rc = node;
            *collect = 1;
        }

        if (*collect && path) {
            path[*index] = node->val;
            *index += 1;
            //printf("[%s] %d\n", __func__, node->val);
        }

    }
    return rc;
}

void upward(NodePtr node, NodePtr target, char *direction, int *find) {

    if (node) {

        if (!(*find)) {
            upward(node->left, target, direction, find);
        }

        if (!(*find)) {
            upward(node->right, target, direction, find);
        }

        if (*find) {
            strcat(direction, "U");
        }

        if (node == target) {
            *find = 1;
        }
    }
    return;
}

void downward(NodePtr node, NodePtr target, NodePtr *last, char *direction, int *find) {

    if (node) {

        if (!(*find)) {
            downward(node->left, target, last, direction, find); 
        }

        if (!(*find)) {
            downward(node->right, target, last, direction, find); 
        }

        if (*find) {
            if (node->left == *last) {
                strcat(direction, "L");     
                *last = node;
            } else if (node->right == *last) {
                strcat(direction, "R"); 
                *last = node;
            }
        }

        if (node == target) {
            *find = 1;
            *last = node;
        }

    }
    return;
}

void release(NodePtr node) {

    if (node) {
        release(node->left);
        release(node->right);
        free(node);
    }
    return;
}

void reverse(char *str) {

    char temp = '\0';

    for (int i = 0, j = strlen(str)-1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    return;
}

NodePtr getlca(NodePtr root, int *path1, int *path2, int p1_size, int p2_size) {

    NodePtr lca = NULL;
    int collect = 0;

    if (root) {
        for (int i = 0; i < p1_size; i++) {
            for (int j = 0; j < p2_size; j++) {
                if (path1[i] == path2[j]) {
                    lca = find_node(root, path1[i], &collect, NULL, 0); 
                    break;
                }
            }
            if (lca)
                break;
        }
    }
    return lca;
}

char* getDirections(struct TreeNode* root, int startValue, int destValue) {

    NodePtr start_node = NULL, dst_node = NULL, lca = NULL, last = NULL;
    char up_direction[BUFSIZ] = {0}, down_direction[BUFSIZ] = {0}, *result = NULL;
    int start_path[BUFSIZ] = {0}, dst_path[BUFSIZ] = {0}, s_index = 0, d_index = 0, collect = 0, find = 0;

    if (root) {
        start_node = find_node(root, startValue, &collect, start_path, &s_index);
        collect = 0;
        dst_node = find_node(root, destValue, &collect, dst_path, &d_index);

        lca = getlca(root, start_path, dst_path, s_index, d_index);

        upward(lca, start_node, up_direction, &find);
        find = 0;
        downward(lca, dst_node, &last, down_direction, &find);
        result = strdup(strcat(up_direction, down_direction));
    }    
    return result;
}

#define TEST_NODES 30 

int main(void) {

    NodePtr root = NULL, temp = NULL, temp2 = NULL, last = NULL;
    srand(time(NULL)); int arrs[TEST_NODES] = {0}; int print = 0, p1 = 0, p2 = 0, find = 0;
    int path1[BUFSIZ] = {0}, path2[BUFSIZ] = {0};
    char up_direction[NAME_MAX] = {0}, down_direction[NAME_MAX] = {0};
    char *result = NULL;
    NodePtr lca = NULL;

    for (int i = 0; i < TEST_NODES; i++) {
        arrs[i] = rand()%1000000;
        root = bst_append(root, arrs[i]);
    }

    inorder(root);
    putchar(10);

    printf("root: %d\n", root->val);
    if (root->left)
        printf("root left: %d\n", root->left->val);
    if (root->right)
        printf("root right: %d\n", root->right->val);
#if 0
    root->left->left->val = 3;
    root->right->left->val = 6;
#else
    root->val = 2; 
    root->left->val = 1;
#endif

    temp = find_node(root, 2, &print, path1, &p1);
    print = 0;
    temp2 = find_node(root, 1, &print, path2, &p2);

    printf("find: %d, %p\n", temp->val, temp);
    for (int i = 0; i < p1; i++) {
        printf("%d ", path1[i]);
    }
    putchar(10);

    printf("find: %d, %p\n", temp2->val, temp2);
    for (int i = 0; i < p2; i++) {
        printf("%d ", path2[i]);
    }
    putchar(10);
    print = 0;

    for (int i = 0; i < p1; i++) {
        for (int j = 0; j < p2; j++) {
            if (path1[i] == path2[j]) {
                printf("path1[%d] %d\n", i, path1[i]);
                lca = find_node(root, path1[i], &print, NULL, 0); 
                break;
            }    
        }
        if (lca)
            break;
    }
    printf("lca: %d\n", lca->val);

    upward(lca, temp, up_direction, &find);
    if (strlen(up_direction)) {
        printf("direction: %s\n", up_direction);
    }

    find = 0;

    downward(lca, temp2, &last, down_direction, &find);
    if (strlen(down_direction)) {
        reverse(down_direction);
        printf("direction: %s\n", down_direction);
    }

    result = strdup(strcat(up_direction, down_direction));
    printf("result: %s\n", result);

    release(root);
    free(result);
    return EXIT_SUCCESS;
}
