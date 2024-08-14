/*
 * =====================================================================================
 *
 *       Filename:  2024_08_14_reverse_linked_list.c
 *
 *    Description:  Reverse linked list  
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

#ifdef TEST_FUNC

NodePtr create_node(NodePtr node, int val) {

    if (node) {
        node->next = create_node(node->next, val);
    } else {
        node = (NodePtr) malloc(sizeof(struct ListNode));
        node->val = val;
        node->next = NULL;
    }
    return node;
}

void freelist(NodePtr node) {

    NodePtr temp = NULL;

    while (node) {
        temp = node;
        node = node->next;
        free(temp);
    }
    return;
}

void showlist(NodePtr node) {

    while (node) {
        printf("%3d ", node->val);
        node = node->next;
    }
    putchar('\n');
    return;
}
#endif


int main(void) {

#ifdef TEST_FUNC  
#define TEST_AMOUNT 10

    NodePtr reverseList(NodePtr);

    NodePtr node = NULL;
    srand(time(NULL));

    for (int i = 0; i < TEST_AMOUNT; i++) {
        node = create_node(node, rand()%1000); 
    }

    showlist(node);

    node = reverseList(node);

    showlist(node);

    freelist(node);
#endif
    return EXIT_SUCCESS;
}

struct ListNode* reverseList(struct ListNode* head) {

    NodePtr prev = NULL, later = NULL, cur = head;

    if (head) {
        while (cur) {
            later = cur->next;
            cur->next = prev;
            prev = cur;
            cur = later;
        }
    }
    return prev;
}
