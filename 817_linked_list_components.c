/*
 * =====================================================================================
 *
 *       Filename:  817_linked_list_components.c
 *
 *    Description:  linked list components  
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

typedef enum {false, true} bool;
typedef struct ListNode *NodePtr;

bool node_finder(int *arr, int size, NodePtr node) {

    if (node) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == node->val) {
                arr[i] = -1;
                return true;
            }
        }
    }
    return false;
}    

int numComponents(struct ListNode* head, int* nums, int numsSize) {

    struct ListNode *lookup = NULL, *temp = NULL;
    int counter = 0, flag = 0; 
    bool found = true;

    while (head != NULL) {

        while (found = node_finder(nums, numsSize, head)) {
            flag = 1;
            head = head->next;
        }

        if (flag)
            counter++;

        if (head)
            head = head->next;
        flag = 0;
    }

    return counter;
}

int get_length(struct ListNode *node) {

    int len = 0;

    while (node) {
        len++;
        node = node->next;
    }
    return len;
}
