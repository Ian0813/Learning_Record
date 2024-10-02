/*
 * =====================================================================================
 *
 *       Filename:  735_asteroid_collision.c
 *
 *    Description:  Asteroid collision  
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
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define CHECK_NUMERIC_SIGN(val) (val >= 0 ? POSITIVE : NEGATIVE)

enum {
    NEGATIVE = 0,
    POSITIVE = 1
};

typedef enum {false, true} bool;

struct node {
    int val;
    struct node *prev;
    struct node *next;
};
typedef struct node *NodePtr;

typedef struct dlist {
    NodePtr head;
    NodePtr tail;
} *DoubleList;

static NodePtr create_node(int val) {

    NodePtr node = NULL;

    node = (NodePtr) malloc(sizeof(struct node));

    node->val = val;
    node->next = node->prev = NULL;
    return node; 
}

static DoubleList dlist_init(void) {

    DoubleList dolist = NULL;

    dolist = (DoubleList) malloc(sizeof(struct dlist));
    dolist->head = dolist->tail = NULL;

    return dolist;
}

static bool dlist_tail_insert(DoubleList dolist, int val) {

    bool rc = true;

    if (dolist) {
        if (!dolist->head) {
            dolist->head = dolist->tail = create_node(val);       
        } else {
            dolist->tail->next = create_node(val);
            dolist->tail->next->prev = dolist->tail;
            dolist->tail = dolist->tail->next;
        }
    } else {
        rc = false;
    }
    return rc;
}

static void dlist_release(DoubleList dolist) {

    NodePtr temp = NULL;

    if (dolist) {
        while ((temp = dolist->head)) {
            dolist->head = dolist->head->next;
            free(temp);
        }
        dolist->tail = NULL;
        free(dolist);
    }
    return;    
}

static void print_list(NodePtr head) {

    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    putchar('\n');
    return;
}


void check_collision(DoubleList dolist, int val) {

    NodePtr temp = NULL;
    bool equal_sign = false;

    switch(CHECK_NUMERIC_SIGN(val)) {
        case NEGATIVE: {
            if (dolist->tail) {
                if (dolist->tail->val >= 0) {
                    if (dolist->tail->val <= (-val)) {
                        equal_sign = dolist->tail->val == (-val); 
                        temp = dolist->tail;            
                        dolist->tail = dolist->tail->prev;
                        if (dolist->tail) {
                            dolist->tail->next = NULL;
                        } else {
                            dolist->tail = dolist->head = NULL; 
                        }
                        free(temp);
                        equal_sign ? NULL : check_collision(dolist, val);
                    }
                } else {
                    dlist_tail_insert(dolist, val); 
                }
            } else {
                dlist_tail_insert(dolist, val); 
            }
        }
        break; 
        case POSITIVE: {
            dlist_tail_insert(dolist, val); 
        }
        break;  
    }
    return;
}

static int *get_result(DoubleList dolist, int *index) {

    NodePtr node = dolist->head;
    int *result = NULL; 
    int size = 1;

    while (node) {

        if (!result) {
            result = (int *) calloc(size, sizeof(int)); 
            result[*index] = node->val;
            *index += 1;
        } else {
            size += 1;
            result = (int *) realloc(result, sizeof(int)*size);
            result[*index]= node->val;
            *index += 1;
        }
        node = node->next;
    }
    return result;
}

#ifdef LEETCODE_735
int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {

    DoubleList dolist = NULL;
    int *result = 0;
    int index = 0;

    *returnSize = 0;    

    if (asteroidsSize) {

        dolist = dlist_init();
        dlist_tail_insert(dolist, asteroids[0]);

        for (int i = 1; i < asteroidsSize; i++) {
            check_collision(dolist, asteroids[i]);
        }
        print_list(dolist->head);
        result = get_result(dolist, &index);
        *returnSize = index;
        dlist_release(dolist);
    }
    return result;
}
#endif

int main(void) {

    int arr[] = {-2,-1,1,2};
    int size = 0;

#ifdef LEETCODE_735
    asteroidCollision(arr, sizeof(arr)/sizeof(*arr), &size);
#endif

    return EXIT_SUCCESS;
}
