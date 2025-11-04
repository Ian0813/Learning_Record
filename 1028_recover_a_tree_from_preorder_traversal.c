/*
 * =====================================================================================
 *
 *       Filename:  1028_recover_a_tree_from_preorder_traversal.c
 *
 *    Description:  recover a tree from preorder traversal
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04.2) 11.4.0
 *
 *         Author:  Ian
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <limits.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define CH_TO_INT(ch) ((ch)-'0')
#define MAX_LIST_LEN BUFSIZ

typedef struct TreeNode *TreeNodePtr;

struct node {
    TreeNodePtr node_ptr;
    struct node *next;
};

typedef struct llist {
    struct node *tnode_list[MAX_LIST_LEN];
} llist;

static struct node *create_node(int value) {

    struct node *data = NULL;

    data = (struct node *) malloc(sizeof(*data));

    if (data) {
        data->node_ptr = (TreeNodePtr) malloc(sizeof(*data->node_ptr));
        data->node_ptr->left = data->node_ptr->right = NULL;
        data->node_ptr->val = value;
        data->next = NULL;
    }

    return data;
}

static void tlist_append(llist *tlist, int value, int height) {

    struct node *ptr = NULL, *parent = NULL; 

    if (!tlist)
        return;

    ptr = tlist->tnode_list[height];

    if (!ptr) {
        ptr = tlist->tnode_list[height] = create_node(value);  
    } else {
        while (ptr->next) {
            ptr = ptr->next; 
        }
        ptr->next = create_node(value);
        ptr = ptr->next;
    }

    if (height) {

        parent = tlist->tnode_list[height-1];

        while (parent->next) {
            parent = parent->next;
        }

        if (!parent->node_ptr->left) {
            parent->node_ptr->left = ptr->node_ptr;
        } else if (!parent->node_ptr->right) {
            parent->node_ptr->right = ptr->node_ptr;
        }    
    }
    return; 
}

static void free_tnode(struct node *head) {

    if (head) {
        free_tnode(head->next);
        free(head);
    }
    return;
}

static void free_allocated(llist *tlist) {

    if (!tlist)
        return;

    for (int i = 0; i < MAX_LIST_LEN; i++) {
        if (tlist->tnode_list[i]) {
            free_tnode(tlist->tnode_list[i]); 
        }
    }

    return;
}

static void preorder_traversal(TreeNodePtr root) {

    if (root) {
        printf("%d ", root->val);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
    return;
}

struct TreeNode* recoverFromPreorder(char* traversal) {

    int height = 0, value = 0, len = 0; 
    llist tlist = {NULL};
    TreeNodePtr root = NULL;

    len = strlen(traversal);   

    for (int i = 0; i < len; i++) {

        if (isdigit(traversal[i])) {
            value *= 10;
            value += CH_TO_INT(traversal[i]); 
        } else {
            if (value) {
                tlist_append(&tlist, value, height);
                height = 0;
            }    
            height++;
            value = 0;
        }
    }

    if (value) {
        tlist_append(&tlist, value, height);
    }

    if (tlist.tnode_list[0]) {
        root = tlist.tnode_list[0]->node_ptr; 
        free_allocated(&tlist);
    }

    return root; 
}
