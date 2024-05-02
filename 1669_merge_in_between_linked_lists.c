/*
 * =====================================================================================
 *
 *       Filename:  1669_merge_in_between_linked_lists.c
 *
 *    Description:  merge in between linked lists  
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

NodePtr remove_nodes(NodePtr head, NodePtr *record, int start, int end) {

    NodePtr temp = head, remove = NULL;
    int count = 0;

    while (count <= end) {

        if (count >= start) {
            remove = temp;
            temp = temp->next;
            free(remove);
        } else {
            if (count == start-1) {
                *record = temp;    
            }
            temp = temp->next;
        }
        count++;
    }

    if (!start) {
        head = temp;
    } else {
        (*record)->next = temp;
    }
    return head;
}

struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){

    NodePtr record = NULL, temp = NULL;

    list1 = remove_nodes(list1, &record, a, b);

    temp = list2;
    while (temp->next)
        temp = temp->next;

    if (record) {
        temp->next = record->next;
        record->next = list2;
    } else {
        temp->next = list1;
        list1 = list2;
    }
    return list1;
}
