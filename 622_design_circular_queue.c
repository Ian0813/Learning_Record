/*
 * =====================================================================================
 *
 *       Filename:  622_design_circular_queue.c
 *
 *    Description:  Design circular queue  
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

struct data {
    int val;
    struct data *next;
};

typedef struct {
    struct data *head;
    struct data *wnode;
    struct data *rnode;
    int amount;
    int size;
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k) {

    MyCircularQueue *queue = NULL;

    queue = (MyCircularQueue *) malloc(sizeof(MyCircularQueue));     

    queue->head = queue->wnode = queue->rnode = NULL;
    queue->amount = 0;
    queue->size = k;

    return queue;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {

    if (obj->amount == obj->size) {
        return false;
    }

    if (obj->head == NULL) {
        obj->head = (struct data *) malloc(sizeof(struct data));
        obj->head->val = value; 
        obj->head->next = NULL;
        obj->wnode = obj->head;
    } else {
        obj->wnode->next = (struct data *) malloc(sizeof(struct data));
        obj->wnode->next->val = value;
        obj->wnode->next->next = NULL; 
        obj->wnode = obj->wnode->next;
    }
    obj->amount++;

    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {

    if (!obj->amount) {
        return false;
    }

    obj->rnode = obj->head;
    obj->head = obj->head->next;
    free(obj->rnode);
    obj->amount--;

    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {

    if (!obj->amount) {
        return -1;
    }
    return obj->head->val;
}

int myCircularQueueRear(MyCircularQueue* obj) {

    if (!obj->amount) {
        return -1;
    }
    return obj->wnode->val;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {

    if (!obj->amount) {
        return true;
    }
    return false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {

    if (obj->amount == obj->size) {
        return true;
    }
    return false;
}

void myCircularQueueFree(MyCircularQueue* obj) {

    struct data *temp = NULL;

    while (obj->head != NULL) {
        temp = obj->head;
        obj->head = obj->head->next; 
        free(temp);
    }
    free(obj);

    return;
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);

 * bool param_2 = myCircularQueueDeQueue(obj);

 * int param_3 = myCircularQueueFront(obj);

 * int param_4 = myCircularQueueRear(obj);

 * bool param_5 = myCircularQueueIsEmpty(obj);

 * bool param_6 = myCircularQueueIsFull(obj);

 * myCircularQueueFree(obj);
*/

