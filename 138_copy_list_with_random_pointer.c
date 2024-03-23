/*
 * =====================================================================================
 *
 *       Filename:  138_copy_list_with_random_pointer.c
 *
 *    Description:  Copy list with random pointer  
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
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

typedef struct Node *NodePtr;

struct Node *create(struct Node *node, int val, struct Node *random) {

    if (node == NULL) {
        node = (struct Node *) malloc(sizeof(struct Node));
        node->val = val;
        node->random = random;
        node->next = NULL;
    } else {
        node->next = create(node->next, val, random);
    }
    return node;
}

struct Node *duplicate(struct Node *head, int *len) {

    struct Node *dup = NULL;

    while (head) {
        dup = create(dup, head->val, head->random);
        *len = *len + 1;
        head = head->next;
    }
    return dup;
}

int find_randaddr_index(struct Node *head, NodePtr randaddr) {

    int count = 0;

    if (randaddr == NULL)
        return -1;

    while (head) {
        if (head == randaddr) {
            break;
        }
        count++;
        head = head->next;
    }
    return count;
}

void fill_randaddr_indices(struct Node *head, int *random_indices, int *index) {

    NodePtr temp = head;

    while (temp) {
        random_indices[*index] = find_randaddr_index(head, temp->random);
        *index = *index + 1;
        temp = temp->next;
    }
    return;
}

NodePtr find_randaddr(NodePtr dup, int index) {

    if (index == -1) {
        return NULL;
    }

    while (index--) {
        dup = dup->next;
    }
    return dup;
}

void dup_random(NodePtr dup, int *random_indices) {

    int index = 0;
    NodePtr temp = dup;

    while (dup) {
        dup->random = find_randaddr(temp, random_indices[index++]);
        dup = dup->next;
    }
    return;
}

struct Node* copyRandomList(struct Node* head) {

    int len = 0, index = 0;
    struct Node *dup = NULL;
    int *random_indices = NULL;

    dup = duplicate(head, &len);

    if (dup != NULL) {

        random_indices = (int *) calloc(len, sizeof(int));

        fill_randaddr_indices(head, random_indices, &index);

        dup_random(dup, random_indices);
    }
    return dup;
}

