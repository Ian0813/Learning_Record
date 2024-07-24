/*
 * =====================================================================================
 *
 *       Filename:  155_min_stack.c
 *
 *    Description:  Min Stack  
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

typedef struct stack Stack;

struct stack {
    int *buffer;
    int top;
};

Stack *create_stack(int size) {

    Stack *s = NULL;

    if (size) {
        s = (Stack *) malloc(sizeof(struct stack));
        s->buffer = (int *) calloc(size, sizeof(int));
        s->top = 0;
    }
    return s;
}

void push(Stack *s, int val) {
    if (s) {
        s->buffer[s->top++] = val; 
    }
    return;
}

void pop(Stack *s) {

    if (s && s->top) {
        s->top--;
    }
    return;
}

int gettop(Stack *s) {
    if (s && s->top) {
        return s->buffer[s->top-1]; 
    }
    return INT_MAX;
}

void delete_stack(Stack *s) {
    if (s) {
        free(s->buffer);
        free(s);
    }
    return;
}

typedef struct {
    Stack *s;
    Stack *ms;
} MinStack;

MinStack* minStackCreate(void) {

    MinStack *min_stack = NULL;    
    
    min_stack = (MinStack *) malloc(sizeof(MinStack));

    if (min_stack) {
        min_stack->s = create_stack(BUFSIZ);
        min_stack->ms = create_stack(BUFSIZ);
    }
    return min_stack;
}

void minStackPush(MinStack* obj, int val) {

    int minimum_val = INT_MAX;

    if (obj) {
        push(obj->s, val);

        minimum_val = gettop(obj->ms);

        if (minimum_val > val) {
           minimum_val = val;
        }
        push(obj->ms, minimum_val);
    }
    return;
}

void minStackPop(MinStack* obj) {

    if (obj) {
        pop(obj->s);
        pop(obj->ms);
    }
    return;
}

int minStackTop(MinStack* obj) {

    int val = 0;

    if (obj) {
        val = gettop(obj->s);
    }
    return val;
}

int minStackGetMin(MinStack* obj) {

    int val = 0;

    if (obj) {
        val = gettop(obj->ms);
    }
    return val;
}

void minStackFree(MinStack* obj) {

    if (obj) {
        delete_stack(obj->s);
        delete_stack(obj->ms);
        free(obj);
    }
    return;
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/

