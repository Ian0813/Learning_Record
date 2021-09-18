/*
 * =====================================================================================
 *
 *       Filename:  225_implement_stack_using_queues.c
 *
 *    Description:  Implement stack using queues 
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
#include <unistd.h>
#include <stdint.h>
#include <limits.h>

typedef uint8_t bool; 
enum BOOL {false, true};

typedef struct Queue {

    void (*enqueue)(int val, struct Queue *);

    int (*dequeue)(struct Queue *);

    bool (*is_empty)(struct Queue *);

    int (*peek)(struct Queue *);

	int array[BUFSIZ];
	int rindex, windex;
} MyQueue;

typedef struct {
    MyQueue *main;
    MyQueue *sub;
} MyStack;

void enqueue(int val, MyQueue *queue) {
    if ((queue->windex+1) != queue->rindex) {
        queue->array[queue->windex++] = val;
	}
	return;
}

int dequeue(MyQueue *queue) {
    if (queue->rindex != queue->windex) {
        return queue->array[queue->rindex++];
	}
	return INT_MIN;
}

bool is_empty(MyQueue *queue) {
    if (queue->windex == queue->rindex) {
        return true;
	}
	return false;
}

int peek(MyQueue *queue) {
    if (queue->rindex != queue->windex) {
        return queue->array[queue->rindex];
	}
	return INT_MIN;
}

MyQueue *queue_init(void) {

    MyQueue *queue = (MyQueue *) malloc(sizeof(MyQueue)); 

	if (queue != NULL) {
        queue->enqueue = enqueue;
        queue->dequeue = dequeue;
        queue->peek = peek;
        queue->is_empty = is_empty;
		queue->rindex = queue->windex = 0;
		memset(queue->array, 0, sizeof(int) * BUFSIZ);
	}
	return queue;
}

MyStack* myStackCreate(void) {

    MyStack *stack = (MyStack *) malloc(sizeof(MyStack));

	if (stack != NULL) {
        stack->main = stack->sub = NULL; 
		stack->main = queue_init();
		stack->sub = queue_init();
	}
	return stack;
}

void myStackPush(MyStack* obj, int x) {

    while (!obj->main->is_empty(obj->main)) {
        obj->sub->enqueue(obj->main->dequeue(obj->main), obj->sub);
    }

    obj->main->enqueue(x, obj->main);

    while (!obj->sub->is_empty(obj->sub)) {
        obj->main->enqueue(obj->sub->dequeue(obj->sub), obj->main);
    }
	return;
}

int myStackPop(MyStack* obj) {

    if (!obj->main->is_empty(obj->main)) {
        return obj->main->dequeue(obj->main);  
	}
	return INT_MIN;
}

int myStackTop(MyStack* obj) {

    if (!obj->main->is_empty(obj->main)) {
        return obj->main->peek(obj->main); 
	}
    return INT_MIN;
}

bool myStackEmpty(MyStack* obj) {
    return obj->main->is_empty(obj->main);
}

void myStackFree(MyStack* obj) {
    free(obj->main);
	free(obj->sub);
	free(obj);
	return;
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/

int main(void) {

    MyStack* obj = myStackCreate();

    myStackPush(obj, 3);
    myStackPush(obj, 5);

    int param_3 = myStackTop(obj);
	fprintf(stdout, "param_3: %d\n", param_3);
 
    int param_2 = myStackPop(obj);
	fprintf(stdout, "param_2: %d\n", param_2);

    bool param_4 = myStackEmpty(obj);
	fprintf(stdout, "param_4: %d\n", param_4);

    myStackFree(obj);

	return 0;
}

