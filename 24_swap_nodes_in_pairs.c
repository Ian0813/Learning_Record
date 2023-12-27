/*
 * =====================================================================================
 *
 *       Filename:  24_swap_nodes_in_pairs.c
 *
 *    Description:  Swap nodes in pairs
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
 *
 *         Author:  Ian
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode *NodePtr;
struct ListNode* swapPairs(struct ListNode* head) {

    NodePtr node = head, after = NULL, prev = NULL;

    if (head != NULL) {

        if (head->next != NULL) {
            after = head->next;
            head = after;
        }

        while (node != NULL && after != NULL) {
            if (prev != NULL) {
                prev->next = after;
            }
            node->next = after->next;
            after->next = node;
            prev = node;
            node = node != NULL ? node->next : NULL;
            after = node != NULL ? node->next : NULL;
        }
    }
    return head;
}

int main(void) {
    return 0;
}
