/*
 * =====================================================================================
 *
 *       Filename:  1389_create_target_array_in_the_given_order.c
 *
 *    Description:  create target array in the given order
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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct node {
    int value;
    struct node *next; 
} node_t;

static node_t *llist_append(node_t *head, int value) {

    node_t *n = NULL;  

    if (!head) {
        head = n = (node_t *) malloc(sizeof(*n));
        n->value = value;
        n->next = NULL;
    } else {
        head->next = llist_append(head->next, value); 
    }
    return head;
}

static node_t *llist_insert(node_t *head, int pos, int value) {

    node_t *prev = NULL, *cur = head, *n = NULL;

    if (!head)
        return head;

    n = (node_t *) malloc(sizeof(*n));  
    n->value = value; 
    n->next = NULL; 

    while (pos--) {
        prev = cur;   
        cur = cur->next;
    }

    if (prev) {
        n->next = prev->next;            
        prev->next = n;
    } else {
        n->next = head;
        head = n;
    }
    return head;
}

static void llist_display(node_t *head) {

    if (head) {
        printf("%d ", head->value);
        llist_display(head->next);
    } else {
        putchar('\n'); 
    }
    return;
}

static void llist_to_result(node_t *node, int *arr, int size) {

    int index = 0;

    while (size && node) {
        arr[index++] = node->value;
        node = node->next;
        size--;
    }

    return;
}

static void llist_free(node_t *head) {

    if (head) {
        llist_free(head->next);
        free(head);
    }
    return;
}

int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize) {

    node_t *head = NULL;
    int *result = 0;

    result = (int *) calloc(numsSize, sizeof(int));
    *returnSize = numsSize;

    for (int i = 0; i < numsSize; i++) {
        head = llist_append(head, nums[i]);
    }

    for (int i = 0; i < numsSize; i++) {
        head = llist_insert(head, index[i], nums[i]);
    }

    llist_display(head);
    llist_to_result(head, result, numsSize);
    llist_free(head);

    return result;
}
