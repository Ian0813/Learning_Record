/*
 * =====================================================================================
 *
 *       Filename:  1261_find_elements_in_a_contaminated_binary_tree.c
 *
 *    Description:  find elements in a contaminated binary tree
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

typedef enum {false, true} bool;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define LEFT_NODE_VAL(val) (2*val+1)
#define RIGHT_NODE_VAL(val) (2*val+2)

typedef struct TreeNode *NodePtr;
typedef struct {
    NodePtr root;    
} FindElements;

static void fill_trees(struct TreeNode *node, int val) {

    if (node) {
        node->val = val;
        fill_trees(node->left, LEFT_NODE_VAL(val));
        fill_trees(node->right, RIGHT_NODE_VAL(val));
    }
    return;
}

static bool try_find(NodePtr node, int target) {

    bool rc = false;

    if (node) {

        if (node->val == target) {
            rc = true;
        }
        rc = rc == false ? try_find(node->left, target) : rc;
        rc = rc == false ? try_find(node->right, target) : rc;
    }
    return rc;
}    

FindElements* findElementsCreate(struct TreeNode* root) {

    FindElements *obj = NULL;

    if (root) {
        obj = (FindElements *) malloc(sizeof(FindElements));
        obj->root = root;
        fill_trees(obj->root, 0);
    }
    return obj;
}

bool findElementsFind(FindElements* obj, int target) {

    bool rc = false;

    if (obj) {
        rc = try_find(obj->root, target);
    }
    return rc;
}

void findElementsFree(FindElements* obj) {
    if (obj) {
        free(obj);
    }
    return;
}

/**
 * Your FindElements struct will be instantiated and called as such:
 * FindElements* obj = findElementsCreate(root);
 * bool param_1 = findElementsFind(obj, target);
 
 * findElementsFree(obj);
*/

