/*
 * =====================================================================================
 *
 *       Filename:  203_remove_linked_list_elements.c
 *
 *    Description:  Remove linked list elements 
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
 *
 *       Source  :  https://leetcode.com/problems/remove-linked-list-elements/description/ 
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

/* 
 * Input: head = [1,2,6,3,4,5,6], val = 6
 * Output: [1,2,3,4,5]
 *
*/

typedef struct ListNode *NodePtr;

struct ListNode* removeElements(struct ListNode* head, int val) {

    NodePtr prev = NULL, node = NULL;

    if (head != NULL) {

        node = head;

        while (node != NULL) {
            if (node->val == val ) {
                if (node == head) {
                    head = node->next;
                } else {
                    prev->next = node->next;
                }
                free(node);
				node = prev == NULL ? head : prev->next;
    			continue;
			}
            prev = node;
		    node = node->next;
        }
    }
    return head;
}
