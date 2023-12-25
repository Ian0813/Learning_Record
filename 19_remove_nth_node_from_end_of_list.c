/*
 * =====================================================================================
 *
 *       Filename:  19_remove_nth_node_from_end_of_list.c
 *
 *    Description:  Remove nth node from end of list
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

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {

    struct ListNode *anchor = NULL, *progress = head, *prev = NULL;
    int count = 0;

    if (head != NULL) {

        while (progress != NULL) {
            count++;
            if (count == n) {
                if (anchor == NULL) {
                    anchor = head;
                } else {
                    prev = anchor;
                    anchor = anchor->next;
                }
                count--;
            }
            progress = progress->next;
        }

        if (prev == NULL) {
            head = head->next;
            free(anchor);
        } else {
            prev->next = anchor->next;
            free(anchor);
        }
    }
    return head;
}

int main(void) {
    return 0;
}
