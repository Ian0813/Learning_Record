/*
 * =====================================================================================
 *
 *       Filename:  3507_minimum_pair_removal_to_sort_array_i.c
 *
 *    Description:  minimum pair removal to sort array i
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

typedef enum {false, true} bool;

typedef struct node {
    int value;
    struct node *next;
} *node_ptr_t;

static bool is_sorted(node_ptr_t node) {

    bool rc = true;

    while (node->next) {
        if (node->value > node->next->value) {
            rc = false;
            break;
        }
        node = node->next;
    }
    return rc;
}

static node_ptr_t create_node(node_ptr_t node, int value) {
    if (!node) {
        node = (node_ptr_t) malloc(sizeof(*node));
        node->value = value; 
        node->next = NULL;
    } else {
        node->next = create_node(node->next, value);
    }
    return node;
}

static node_ptr_t get_minimum_pair(node_ptr_t head) {

    node_ptr_t temp = head, mini_node = head;
    int minimum_val = INT_MAX, value = 0;

    while (temp->next) {
        value = temp->value + temp->next->value;        
        if (value < minimum_val) {
            mini_node = temp; 
            minimum_val = value;
        }
        temp = temp->next;
    }
    return mini_node;
}

static node_ptr_t reform_list(node_ptr_t head, node_ptr_t mini_ptr) {

    node_ptr_t temp = head;

    if (mini_ptr == head) {
        head = head->next;
        head->value = mini_ptr->value + head->value;
    } else {

        while (temp->next != mini_ptr) {
            temp = temp->next;
        }
        temp->next = mini_ptr->next;
        temp->next->value += mini_ptr->value;     
    }
    free(mini_ptr);

    return head;
}

static void free_node(node_ptr_t head) {

    if (head) {
        free_node(head->next);
        free(head);
    }
    return;
}

int minimumPairRemoval(int* nums, int numsSize) {

    int count = 0, tindex = 0;
    node_ptr_t head = NULL, node = NULL; 

    if (numsSize) {

        for (int i = 0; i < numsSize; i++) {
            head = create_node(head, nums[i]);
        }

        while (!is_sorted(head)) {
            node = get_minimum_pair(head);    
            head = reform_list(head, node);
            count++;
        }
        free_node(head);
    }
    return count;
}
