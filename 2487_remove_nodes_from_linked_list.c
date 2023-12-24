/*
 * =====================================================================================
 *
 *       Filename:  2487_remove_nodes_from_linked_list.c
 *
 *    Description:  Remove nodes from linked list  
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

typedef struct ListNode *NodePtr;

struct ListNode {
    int val;
    struct ListNode *next;
};

NodePtr create_list(NodePtr node, int val) {

    if (node == NULL) {
	    node = (struct ListNode *) malloc(sizeof(struct ListNode));
		node->val = val; 
		node->next = NULL;
    } else {
        node->next = create_list(node->next, val);
    }
	return node;
}

NodePtr reverse_list(NodePtr head) {

    NodePtr prev = NULL, cur = head, after = NULL;

    while (cur != NULL) {
        after = cur->next;
	    cur->next = prev;	
		prev = cur;
		cur = after;
	}
	return prev;
}

struct ListNode* removeNodes(struct ListNode* head) {

    NodePtr node = NULL, prev = NULL, temp = NULL;
	int maximum = 0;

	if (head != NULL) {

        node = head = reverse_list(head);

		while (node != NULL) {
            if (node->val > maximum) {
                maximum = node->val;
			}

			if (maximum > node->val) {
                prev->next = node->next; 
                temp = node; 
			} else {
                prev = node;
			}
			node = node->next;
			free(temp);
			temp = NULL;
		}

		head = reverse_list(head);
	}
	return head;
}

int main(void) {

    NodePtr head = NULL, temp = NULL;

	int nums[] = {5, 2, 13, 3, 8};

    for (int i = 0; i < (sizeof(nums)/sizeof(int)); i++) {
        head = create_list(head, nums[i]);
		printf("%d ", nums[i]);
    }
	putchar('\n');

    head = removeNodes(head);

	while (head != NULL) {
        temp = head; 
		printf("%d ", temp->val);
		head = head->next;
		free(temp);
	}
	putchar('\n');

	return 0;
}
