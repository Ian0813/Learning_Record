/*
 * =====================================================================================
 *
 *       Filename:  328_odd_even_linked_list.c
 *
 *    Description:  Odd even linked list
 *
 *       Compiler:  gcc (Ubuntu 12.3.0-1ubuntu1~22.04) 12.3.0
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
 *
 * Input: head = [1,2,3,4,5]
 * Output: [1,3,5,2,4]
 */

typedef struct ListNode *NodePtr;

int count_list(NodePtr ptr) {

    int counter = 0;

    while (ptr != NULL) {
        counter++;
        ptr = ptr->next;
    }
    return counter;
}

NodePtr find_end(NodePtr ptr) {

    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    return ptr;
}

struct ListNode* oddEvenList(struct ListNode* head) {

    NodePtr even_ptr = NULL, odd_ptr = NULL, end_ptr = NULL, odd_temp = NULL, even_temp = NULL, end_node = NULL;
    int counter = 0, number_of_node = 0;

    if (head != NULL) {

        number_of_node = count_list(head);
        end_node = find_end(head);

        while (head != NULL) {

            counter++;

            if (counter%2) {
                if (odd_ptr == NULL) {
                    odd_temp = odd_ptr = head;
                } else {
                    odd_temp->next = head;
                    odd_temp = odd_temp->next;
                }
            } else {
                if (even_ptr == NULL) {
                    even_temp = even_ptr = head;
                } else {
                    even_temp->next = head;
                    even_temp = even_temp->next;
                }
            }
            head = head->next;
        }

        if (number_of_node > 0) {
            if (!(number_of_node%2)) {
                odd_temp->next = even_ptr;
            } else if (number_of_node > 1) {
                end_node->next = even_ptr;
                even_temp->next = NULL;
            }
        }
    }
    return odd_ptr;
}
