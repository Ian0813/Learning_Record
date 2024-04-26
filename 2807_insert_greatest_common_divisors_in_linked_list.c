/*
 * =====================================================================================
 *
 *       Filename:  2807_insert_greatest_common_divisors_in_linked_list.c
 *
 *    Description:  Insert greatest common divisiors in linked list  
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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#define MAX_VALUE(v1, v2) (v1 >= v2 ? v1 : v2)
#define MINI_VALUE(v1, v2) (v1 <= v2 ? v1 : v2)

typedef struct ListNode *NodePtr;

int gcp(int v1, int v2) {

    int result = v2;

    if (v1%v2) {
        result = gcp(v2, v1%v2);
    }
    return result;
}

NodePtr create_node(int val) {

    NodePtr new = NULL;

    new = (NodePtr) malloc(sizeof(struct ListNode));

    if (new != NULL) {
        new->val = val;
        new->next = NULL;
    }
    return new;
}

void insert(NodePtr node, int val) {

    NodePtr new = NULL;

    new = create_node(val);
    if (new != NULL) {
        new->next = node->next;
        node->next = new;
    }
    return;
}

struct ListNode* insertGreatestCommonDivisors(struct ListNode* head) {

    NodePtr node = head;
    int factor = 0;

    if (node != NULL) {
        while (node != NULL && node->next != NULL) {
            factor = gcp(MAX_VALUE(node->val, node->next->val), MINI_VALUE(node->val, node->next->val)); 
            insert(node, factor);
            node = node->next->next;
        }
    }
    return head;
}
