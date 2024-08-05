/*
 * =====================================================================================
 *
 *       Filename:  1381_design_a_stack_with_increment_operation.c
 *
 *    Description:  Design a stack with increment operation  
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

typedef enum {false, true} bool;

typedef struct stack *Stack;

struct stack {
    int *buffer;
    int top;
    int size;
};

Stack create_stack(int size) {

    Stack s = NULL;

    if (size) {
        s = (Stack) malloc(sizeof(struct stack));
        s->buffer = (int *) calloc(size, sizeof(int));
        s->size = size;
        s->top = 0;
    }
    return s;
}

bool push(Stack s, int val) {

    bool rc = true;

    if (s) {
        if (s->top < s->size) {
            s->buffer[s->top++] = val;
        } else {
            rc = false; 
        }
    } else {
        rc = false;
    }
    return rc;
}

bool pop(Stack s) {

    bool rc = true;

    if (s) {
        if (s->top) {
            s->top--;
        } else {
            rc = false; 
        }
    } else {
        rc = false;
    }
    return rc;
}

int seek(Stack s) {

    int val = -1;

    if (s) {
        if (s->top) {
            val = s->buffer[s->top-1];
        }    
    }
    return val;
}

void delete_stack(Stack s) {

    if (s) {
        free(s->buffer);
        free(s);
    }
    return;
}

typedef struct {
    Stack s;
} CustomStack;


CustomStack* customStackCreate(int maxSize) {

    CustomStack *obj = NULL; 

    if (maxSize) {
        obj = (CustomStack *) malloc(sizeof(CustomStack));
        obj->s = create_stack(maxSize);
    }
    return obj;
}

void customStackPush(CustomStack* obj, int x) {

    if (obj) {
        push(obj->s, x);
    }
    return;
}

int customStackPop(CustomStack* obj) {

    int val = 0;

    if (obj) {
        if ((val = seek(obj->s)) != -1) {
            pop(obj->s);     
        }
    }
    return val;
}

void customStackIncrement(CustomStack* obj, int k, int val) {

    if (obj) {
        for (int i = 0; i < k; i++) {
            if (i < obj->s->size) {
                obj->s->buffer[i] += val;
            }
        }
    }
    return;
}

void customStackFree(CustomStack* obj) {

    if (obj) {
        delete_stack(obj->s);
        free(obj);
    }
    return;
}

/**
 * Your CustomStack struct will be instantiated and called as such:
 * CustomStack* obj = customStackCreate(maxSize);
 * customStackPush(obj, x);

 * int param_2 = customStackPop(obj);

 * customStackIncrement(obj, k, val);

 * customStackFree(obj);
*/

