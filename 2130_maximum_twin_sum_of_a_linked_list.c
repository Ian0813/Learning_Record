/*
 * =====================================================================================
 *
 *       Filename:  2130_maximum_twin_sum_of_a_linked_list.c
 *
 *    Description:  Maximum twin sim of a linked list   
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

#define MAX_LISTNUM 100001
#define MAX_NUMBER(num1, num2) ((num1) > (num2) ? (num1) : (num2))

typedef struct ListNode *NodePtr; 

int place_to_arr(NodePtr head, NodePtr *arr) {

    int index = 0;

    while (head) {
        arr[index++] = head;
        head = head->next;
    }
    return index;
}

int pairSum(struct ListNode* head) {

    struct ListNode *list_arr[MAX_LISTNUM] = {NULL};
    int amount = 0, max = 0;

    amount = place_to_arr(head, list_arr); 

    for (int i = 0; i < (amount/2); i++) {
        max = MAX_NUMBER(max, (list_arr[i]->val + list_arr[amount-i-1]->val));
    }
    return max;
}

