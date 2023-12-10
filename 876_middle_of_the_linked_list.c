/*
 * =====================================================================================
 *
 *       Filename:  876_middle_of_the_linked_list.c
 *
 *    Description:  Middle of the linked list
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
 *
 *         Author:  Ian
 *
 *       Source  :  https://leetcode.com/problems/middle-of-the-linked-list/
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#define LISTLEN 10

typedef struct ListNode *NodePtr;

struct ListNode {
    int val;
    struct ListNode *next;
};

NodePtr create(NodePtr node, int val) {
    if (node == NULL) {
        node = (NodePtr) malloc(sizeof(struct ListNode));
        node->val = val;
        node->next = NULL;
    } else {
        node->next = create(node->next, val);
    }
    return node;
}

unsigned int get_count(NodePtr head) {

    unsigned int counter = 0;

    while (head != NULL) {
        counter++;
        head = head->next;
    }
    return counter;
}

struct ListNode* middleNode(struct ListNode* head) {

    NodePtr array[BUFSIZ] = {NULL};
    int index = 0, count = 0;

    count = get_count(head);

    while (head != NULL) {
        array[index++] = head;
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");

    return array[count/2];
}

void release(NodePtr head) {

    NodePtr prev = NULL;

    prev = head;

    while (head != NULL) {
        head = head->next;
        free(prev);
        prev = head;
    }
    return;
}

int main(void) {

    NodePtr head = NULL, middle = NULL;

    srand(time(NULL));

    for (int i = 0; i < LISTLEN; i++) {
        head = create(head, rand()%100);
    }

    middle = middleNode(head);
    printf("middle: %d\n", middle->val);
    release(head);

    return 0;
}
