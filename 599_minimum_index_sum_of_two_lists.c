/*
 * =====================================================================================
 *
 *       Filename:  599_minimum_index_sum_of_two_lists.c
 *
 *    Description:  minimum index sum of two lists
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
#include <limits.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_RESULT_SIZE 1000

typedef struct common_node {
    char *str; 
    int index;
    struct common_node *next;
} cnode_type;

static cnode_type *cnode_create(cnode_type *node, char *str, int value) {

    if (!node) {
        node = (cnode_type *) malloc(sizeof(*node));
        node->str = str; 
        node->index = value;
        node->next = NULL;
    } else {
        node->next = cnode_create(node->next, str, value);
    }

    return node;
}

static void cnode_free(cnode_type *node) {

    if (node) {
        cnode_free(node->next);
        free(node);
    }
    return;
}

static void cnode_display(cnode_type *node) {

    if (node) {
        printf("[%s] string : %s, index : %d\n", __func__, node->str, node->index);
        cnode_display(node->next);
    }

    return;
}

static cnode_type *get_common_str(char **list1, int list1Size, char **list2, int list2Size) {

    cnode_type *head = NULL;

    for (int i = 0; i < list1Size; i++) {
        for (int j = 0; j < list2Size; j++) {
            if (!strcmp(list1[i], list2[j])) {
                head = cnode_create(head, list1[i], i + j); 
            }    
        }
    }

    return head;
}

static int get_least_index(cnode_type *node) {

    int least = INT_MAX;      
    cnode_type *temp = node;

    while (temp) {
        if (temp->index < least) {
            least = temp->index;
        }
        temp = temp->next;
    }
    return least;
}

static void collect_common_strs(cnode_type *node, int least_index, char **result, int *returnSize) {

    cnode_type *temp = node;        

	*returnSize = 0;

    while (temp) {

        if (temp->index == least_index) {
            result[*returnSize] = temp->str;
            *returnSize += 1;
        }
        temp = temp->next;
    }
    return;
}

char** findRestaurant(char** list1, int list1Size, char** list2, int list2Size, int* returnSize) {

    char **result = NULL;
    cnode_type *head = NULL;
    int least_index = 0; 

    result = (char **) calloc(MAX_RESULT_SIZE, sizeof(char *));

    head = get_common_str(list1, list1Size, list2, list2Size);
    //cnode_display(head);

    least_index = get_least_index(head);

    collect_common_strs(head, least_index, result, returnSize);
    cnode_free(head);

    return result;
}
