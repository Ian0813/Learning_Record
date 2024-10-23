/*
 * =====================================================================================
 *
 *       Filename:  2641_cousins_in_binary_tree_ii.c
 *
 *    Description:  Cousins in binary tree ii  
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

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef enum {false, true} bool;

typedef struct TreeNode *NodePtr;

struct NodeHouseHold {
    int val;
    struct TreeNode *parent;
    struct TreeNode *left;
    struct TreeNode *right;
};

static int get_node_amount(struct TreeNode *root) {

    int number = 0;

    if (root) {
        number += get_node_amount(root->left);
        number += get_node_amount(root->right);
        return number + 1;
    }
    return number;
}

static int get_height(NodePtr root) {

    int lh = 0, rh = 0;

    if (root) {
        lh = get_height(root->left);
        rh = get_height(root->right);
        return 1 + (lh > rh ? lh : rh);
    }
    return 0;
}

static int get_arrsize(int n) {

    int base = 1;

    while (n--) {
        base *= 2; 
    }
    return base;
}

typedef struct queue {
    NodePtr *buffer;
    int windex;
    int rindex;
    int size;
} Queue;

struct node_record {
    struct TreeNode *node;
    int sum;
};

static Queue *create_queue(int size) {

    Queue *q = NULL;
    
    if (size) {
        q = (Queue *) malloc(sizeof(Queue));
        q->buffer = (NodePtr *) calloc(size, sizeof(NodePtr));
        q->windex = q->rindex = 0;
    }
    return q;
}

static bool enqueue(Queue *q, NodePtr node) {

    bool rc = true;

    if (q) {
        if ((q->windex+1)%q->size != q->rindex) {
            q->buffer[q->windex++] = node; 
            q->windex %= q->size;
        } else {
            rc = false;
        }
    } else {
         rc = false; 
    }
    return rc;
}

static bool dequeue(Queue *q) {

    bool rc = true;

    if (q) {
        if (q->windex != q->rindex) {
            q->rindex++;
            q->rindex %= q->size;
        } else {
            rc = false;
        }
    } else {
         rc = false; 
    }
    return rc;
}

static NodePtr peek(Queue *q) {

    NodePtr node = NULL;

    if (q) {
        if (q->windex != q->rindex) {
            node = q->buffer[q->rindex];
        }
    }
    return node;
}

static void delete_queue(Queue *q) {

    if (q) {
        free(q->buffer);
        free(q);
    }
    return;
}    

#define CHECK_IS_PARENT(parent, ndoe) (parent->left == node || parent->right == node)

static void traversal_substitute(NodePtr root, struct node_record *records, struct node_record *retrieve) {

    int index = 0, rtindex = 0;
    NodePtr node = NULL;
    Queue *q = NULL;

    q = create_queue(BUFSIZ);
    enqueue(q, root);

    while ((node = peek(q)) != NULL) {

        enqueue(q, NULL);

        while ((node = peek(q)) != NULL) {

            dequeue(q);
            node->val = 0;

            if (rtindex) {
                for (int i = 0; i < rtindex; i++) {
                    if (!CHECK_IS_PARENT(retrieve[i].node, node)) {
                        node->val += retrieve[i].sum;
                    }
                }
            }

            if (node->left || node->right) {

                records[index].node = node;
                records[index].sum = records[index].sum + (node->left ? node->left->val : 0);
                records[index].sum = records[index].sum + (node->right ? node->right->val : 0);
                index++;

                node->left != NULL ? enqueue(q, node->left) : 0;
                node->right != NULL ? enqueue(q, node->right) : 0;
            }
        }

        dequeue(q);
        memset(retrieve, 0, sizeof(struct node_record) * rtindex);
        rtindex = 0;

        if (index) {

            rtindex = index;
            memcpy(retrieve, records, sizeof(struct node_record) * index);
            memset(records, 0, sizeof(struct node_record) * index);
            index = 0;
        }
    }
    delete_queue(q);
    return;
}

static void sumup_nodes(struct TreeNode *root, int height, int *node_sum) {

    if (root) {
        if (root->left)
            node_sum[height+1] += root->left->val; 

        if (root->right)
            node_sum[height+1] += root->right->val; 
        sumup_nodes(root->left, height+1, node_sum);
        sumup_nodes(root->right, height+1, node_sum);
    }
    return;
}

static void update_values(struct TreeNode *root, int height, int *node_sum) {

    int value = 0;

    if (root) {

        value += root->left == NULL ? 0 : root->left->val; 
        value += root->right == NULL ? 0 : root->right->val;

        if (root->left) {
            root->left->val = node_sum[height+1] - value;
        }

        if (root->right) {
            root->right->val = node_sum[height+1] - value;
        }
        update_values(root->left, height+1, node_sum);
        update_values(root->right, height+1, node_sum);
    }
    return;
}

static void swap_sum(struct TreeNode *root, int height, int *node_sum) {

    if (root) {
        if (height)
            root->val += node_sum[height];
        else
            root->val = node_sum[height];
        swap_sum(root->left, height+1, node_sum);
        swap_sum(root->right, height+1, node_sum);
    }
    return;
}

struct TreeNode* replaceValueInTree(struct TreeNode* root) {

    int height = 0;
    int *lnode_sum = NULL, *rnode_sum = NULL;

    if (root) {
        root->val = 0;
        height = get_height(root);
        lnode_sum = (int *) calloc(height, sizeof(int));
        rnode_sum = (int *) calloc(height, sizeof(int));

        sumup_nodes(root->left, 0, lnode_sum);
        sumup_nodes(root->right, 0, rnode_sum);
        update_values(root->left, 0, lnode_sum);
        update_values(root->right, 0, rnode_sum);
        swap_sum(root->left, 0, rnode_sum);
        swap_sum(root->right, 0, lnode_sum);

        free(lnode_sum);
        free(rnode_sum);
    }
    return root;
}
