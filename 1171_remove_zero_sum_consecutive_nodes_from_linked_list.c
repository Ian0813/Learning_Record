/*
 * =====================================================================================
 *
 *       Filename:  1171_remove_zero_sum_consecutive_nodes_from_linked_list.c
 *
 *    Description:  Remove zero sum consecutive nodes from linked list 
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

int *convert_toarray(NodePtr head, int size) {

    int *arr = (int *) malloc(sizeof(int) * size); 
    int index = 0;

    while (head) {
        arr[index++] = head->val;
        head = head->next;
    }
    return arr;
}

NodePtr remove_node(NodePtr head, NodePtr target) {

    NodePtr temp = NULL;
    NodePtr node = NULL;

    if (head == target) {
        temp = head;     
        head = head->next;
        free(temp);
    } else {
        node = head;
        while (node->next != target)
            node = node->next;
        temp = node->next;
        node->next = temp->next;
        free(temp);
    }
    return head;
}

struct ListNode* removeZeroSumSublists(struct ListNode* head) {

    int length = 0;
    int *arr = NULL;
    int sum = 0, loc = 0;
    NodePtr node = NULL, temp = NULL; 

    if (head) {

        node = head; 

        length = get_listlen(head);
        arr = convert_toarray(head, length);

        for (int i = 0; i < length; i++) {
            for (int j = i; j < length; j++) {

                sum += arr[j];

                if (!sum) {

                     while (loc < i) {
                         node = node->next;
                         loc++;
                     }

                     for (loc; loc <= j; loc++) {
                         temp = node;
                         node = node->next;
                         head = remove_node(head, temp);
                     }
                     i = j;
                     break;
                }
            }
            sum = 0;
        }
        free(arr);
    }
    return head;
}
