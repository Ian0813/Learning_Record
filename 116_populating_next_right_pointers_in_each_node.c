/*
 * =====================================================================================
 *
 *       Filename:  116_populating_next_right_pointers_in_each_node.c
 *
 *    Description:  POPULATING-NEXT-RIGHT-POINTERS-IN-EACH-NODE  
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

#define MAX_NODE 10000

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */
typedef enum {false, true} bool;

struct queue {
    void *buf[MAX_NODE];
    int windex;
    int rindex;
};

struct queue *create_queue(void) {

    struct queue *q = NULL;

    q = (struct queue *) malloc(sizeof(struct queue));
    q->windex = 0;
    q->rindex = 0;
    memset(q->buf, NULL, MAX_NODE * sizeof(void *));

    return q;
}

bool enqueue(struct queue *q, struct Node *node) {

    if (q->windex == MAX_NODE) {
        return false;
	}
    q->buf[q->windex++] = node;
    return true;
}

bool dequeue(struct queue *q) {

    if (q->rindex == q->windex)
        return false;
    q->rindex++;
    return true;
}

struct Node *peeking(struct queue *q) {
    return q->buf[q->rindex];
}

struct Node* connect(struct Node* root) {

    struct queue *q = NULL;
    struct Node *temp = root, *sibling = NULL;

    q = create_queue();

    enqueue(q, temp);

    while (peeking(q) != NULL) {

        enqueue(q, NULL);

        if ((temp = peeking(q)) != NULL) {
            dequeue(q);
            enqueue(q, temp->left);
            enqueue(q, temp->right);
            while ((sibling = peeking(q)) != NULL) {
                temp->next = sibling;                
                temp = temp->next;
                enqueue(q, temp->left);
                enqueue(q, temp->right);
                dequeue(q);
            }
            temp->next = NULL;
        }
        dequeue(q);
    }

    free(q);

    return root;
}

