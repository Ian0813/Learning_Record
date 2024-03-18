/*
 * =====================================================================================
 *
 *       Filename:  143_reorder_list.c
 *
 *    Description:  Reorder list  
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
int get_listlen(struct ListNode *head) {

    int len = 0;

    while (head) {
        len++; 
        head = head->next;
    }
    return len;
}

void reorderList(struct ListNode* head) {

    int list_len = 0;
    struct ListNode **nodes = NULL, *temp = NULL;
    int start = 0, end = 0;

    list_len = get_listlen(head);

    if (list_len > 0) {
        nodes = (struct ListNode **) calloc(list_len, sizeof(struct ListNode *));
        temp = head;
    }

    for (int i = 0; i < list_len; i++) {
        nodes[i] = temp;
        temp = temp->next;
    }

    for (start = 0, end = list_len - 1; start < end; start++, end--) {
        nodes[start]->next = nodes[end];
        if (nodes[start+1] != nodes[end])
            nodes[end]->next = nodes[start+1];
        else {
            nodes[end]->next = NULL;     
        }
    }

    if (start == end) {
        nodes[start]->next = NULL;
    }
    return;
}

