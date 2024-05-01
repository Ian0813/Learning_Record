/*
 * =====================================================================================
 *
 *       Filename:  2816_double_a_number_represented_as_a_linked_list.c
 *
 *    Description:  Double a number represented as a linked list 
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

NodePtr reverse(NodePtr head) {

    NodePtr prev = NULL, cur = head, later = NULL;

    while (cur) {
        later = cur->next; 
        cur->next = prev;
        prev = cur;
        cur = later;
    }
    return prev;
}

NodePtr create_node(NodePtr head, int val) {

    if (head == NULL) {
        head = (NodePtr) malloc(sizeof(struct ListNode));
        head->val = val; 
        head->next = NULL;
    } else {
        head->next = create_node(head->next, val);
    }
    return head;
}

struct ListNode* doubleIt(struct ListNode* head){

    int carryin = 0;
    int val = 0; 
    NodePtr temp = NULL;

    if (head) {

        temp = head = reverse(head);

        while (temp) {
            val = temp->val * 2;
            val += carryin;
            carryin = (val/10) ? (val/10) : 0;
            temp->val = (val%10); 
			temp = temp->next;
        }
        
        if (carryin) {
            head = create_node(head, carryin);
        }    
        head = reverse(head);
    }

    return head;
}

