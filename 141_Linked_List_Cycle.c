/*
 * =====================================================================================
 *
 *       Filename:  141_Linked_List_Cycle.c
 *
 *    Description:  Linked List Cycle  
 *
 *         Author:  Ian
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LIST 10000

#define STRINGIZE(s) (#s)

#define true 1
#define false 0


/* Definition for singly-linked list. */
struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode *ListPtr;

int hasCycle(struct ListNode *head) {

    int index = 0;
	ListPtr alist[MAX_LIST] = {NULL};

	alist[index] = head;

	while (head != NULL) {
        for (int i = 0; i < index; i++) {
            if (alist[i] == head->next) {
                return true;  
			}
		}
		head = head->next;
		index++;
		alist[index] = head;
	}
    return false;
}

ListPtr create_list(ListPtr head, int val) {
    if (head == NULL) {
        head = (ListPtr) malloc(sizeof(struct ListNode));
        head->val = val;
		head->next = NULL;
	} else {
        head->next = create_list(head->next, val);
	}
	return head;
}

int main(void) {

    int arr[] = {3, 2, 0, 4};

    ListPtr head = NULL, tail = NULL, node = NULL;

    for (int i = 0; i < sizeof(arr)/sizeof(int); i++) {
        head = create_list(head, arr[i]);
    }
    node = head;

    while (node->next != NULL) {
        node = node->next;
    }

    tail = node;
    tail->next = head->next;
    
    if (hasCycle(head)) {
        printf("has Cycle: %s\n", STRINGIZE(true));
	} else {
        printf("has Cycle: %s\n", STRINGIZE(false));
	}

	return 0;
}

