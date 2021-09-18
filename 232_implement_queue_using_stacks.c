/*
 * =====================================================================================
 *
 *       Filename:  232_implement_queue_using_stacks.c
 *
 *    Description:  Implement queue using stacks  
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
#include <limits.h>

#define STACK_MAX 1000

typedef unsigned int bool;
enum BOOL {false, true};

typedef struct Stack {

/* function pointers */   
    int (*push)(int, struct Stack *);

    int (*pop)(struct Stack *);

    int (*is_empty)(struct Stack *);

	int (*peek)(struct Stack *);

/* variables */
    int array[BUFSIZ];
	int top;
} MyStack;

typedef struct {
    MyStack *main;
    MyStack *sub;
} MyQueue;

int push(int val, MyStack *stack) {

    if (stack->top < STACK_MAX) {
        stack->array[stack->top++] = val;
		return val;
    }
	return INT_MIN;
}

int pop(MyStack *stack) {
    if (stack->top) {
        return stack->array[--stack->top];
	}
	return INT_MIN;
}

int is_empty(MyStack *stack) {
    if (!stack->top) {
       return 1; 
	}
	return 0;
}

int peek(MyStack *stack) {
    fprintf(stdout, "[%s] entered, top: %d\n", __func__, stack->top);
    if (!stack->top) {
        return INT_MIN;
	}
	return stack->array[stack->top - 1];
}

MyStack *stack_init(MyStack *stack) {
    if (stack == NULL) {
        stack = (MyStack *) malloc(sizeof(MyStack));
		stack->push = push;
        stack->pop = pop;
		stack->is_empty = is_empty;
		stack->peek = peek;
		stack->top = 0;
		memset(stack->array, 0, sizeof(int) * BUFSIZ);
	}
	return stack;
}

MyQueue* myQueueCreate(void) {

    MyQueue *queue = (MyQueue *) malloc(sizeof(MyQueue));

	queue->main = NULL;
	queue->sub = NULL;

	if (queue != NULL) {
        queue->main = stack_init(queue->main);
        queue->sub = stack_init(queue->sub);
	}	
    return queue; 
}

void myQueuePush(MyQueue* obj, int x) {

    while (!obj->main->is_empty(obj->main)) {
        obj->sub->push(obj->main->pop(obj->main), obj->sub);
	}

	obj->main->push(x, obj->main);

	while (!obj->sub->is_empty(obj->sub)) {
        obj->main->push(obj->sub->pop(obj->sub), obj->main);
	}
	return;
}

int myQueuePop(MyQueue* obj) {
    return obj->main->pop(obj->main);
}

int myQueuePeek(MyQueue* obj) {
    return obj->main->peek(obj->main);
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->main->is_empty(obj->main);
}

void myQueueFree(MyQueue* obj) {
    free(obj->main); 
    free(obj->sub); 
    free(obj); 
	return;
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/

int main(void) {

    MyQueue* obj = myQueueCreate();

	if (obj == NULL)
        exit(EXIT_FAILURE);

    myQueuePush(obj, 1);
    myQueuePush(obj, 2);

    int param_2 = myQueuePop(obj);
	printf("param_2: %d\n", param_2);

    int param_3 = myQueuePeek(obj);
	printf("param_3: %d\n", param_3);

    bool param_4 = myQueueEmpty(obj);
	printf("param_4: %d\n", param_4);

    myQueueFree(obj);

	return 0;
}
