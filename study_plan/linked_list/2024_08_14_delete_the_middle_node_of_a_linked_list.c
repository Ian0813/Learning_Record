/*
 * =====================================================================================
 *
 *       Filename:  2024_08_14_delete_the_middle_node_of_a_linked_list.c
 *
 *    Description:  Delete the middle node of a linked list 
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

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode *NodePtr;

int counter(NodePtr head) {

    int length = 0;

    while (head) {
        length++; 
        head = head->next;
    }
    return length;
}

NodePtr delete_node(NodePtr head, int middle) {

    NodePtr prev = NULL, temp = head;
    int index = 0;

    if (head) {
        if (index == middle) {
            head = head->next;
            temp->next = NULL;
            free(temp);
        } else {
            while (index < middle) {
                prev = temp;
                temp = temp->next;
                index++;
            }
            prev->next = temp->next;
            temp->next = NULL; 
            free(temp);
        }
    }
    return head;
}

struct ListNode* deleteMiddle(struct ListNode* head) {

    int middle = 0, length = 0, index = 0;
    NodePtr mnode = head;

    if (head) {

        length = counter(head);
        middle = length/2; 

        head = delete_node(head, middle);
    }
    return head; 
}
