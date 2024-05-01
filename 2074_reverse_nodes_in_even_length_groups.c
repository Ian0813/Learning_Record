/*
 * =====================================================================================
 *
 *       Filename:  2074_reverse_nodes_in_even_length_groups.c
 *
 *    Description:  Reverse nodes in even length groups  
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
 * struct listnode {
 *     int val;
 *     struct listnode *next;
 * };
 */


struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode *NodePtr;

int get_listlen(NodePtr head) {

    int count = 0;

    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

NodePtr reverse(NodePtr start, NodePtr end) {

    NodePtr prev = NULL, cur = start, later = NULL;

    while (prev != end) {
        later = cur->next;
        cur->next = prev;
        prev = cur;
        cur = later;
    }
    start->next = cur;
    return end;
}    

struct ListNode* reverseEvenLengthGroups(struct ListNode* head) {

    int length = 0;
    NodePtr start, end, temp;  

    start = end = temp = NULL;

    if (head) {

        length = get_listlen(head);

        start = end = temp = head;

        for (int i = 1; length; i++) {

            if (length >= i && !(i%2)) {

                for (int j = 1; j < i; j++) {
                    end = end->next;
                }
                temp->next = reverse(start, end);
                temp = start;
                start = end = start->next; 

                length -= i;

            } else {

                if (length > i) {
                    for (int j = 1; start && j <= i; j++) {
                        temp = start;
                        start = start->next;
                    }
                    end = start;
                } else if (!(length%2)) {
                    for (int j = 1; j < length; j++) {
                        end = end->next;
                    }
                    temp->next = reverse(start, end);
                    temp = start;
                    start = end = start->next; 
                }

                if (length > i)
                    length -= i;
                else
                    length = 0; 
            }
        }
    }
    return head;
}

