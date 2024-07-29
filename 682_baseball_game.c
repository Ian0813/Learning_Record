/*
 * =====================================================================================
 *
 *       Filename:  682_baseball_game.c
 *
 *    Description:  Baseball game  
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

typedef enum {
    INTEGER_CMD = 0,    
    PLUS_CMD = 1,
    DOUBLE_CND = 2,
    INVALID_CMD = 3,
} command_type;

/* Instructions 
 *
 * An integer x.
 * Record a new score of x.
 *
 * '+'.
 * Record a new score that is the sum of the previous two scores.
 * 
 * 'D'.
 * Record a new score that is the double of the previous score.
 * 
 * 'C'.
 * Invalidate the previous score, removing it from the record.
 *
 * */

struct stack {
    int *buffer;
    int top;
    int size;
};

typedef struct stack *Stack;

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

int gettop(Stack s) {

    if (s && s->top) {
        return s->buffer[s->top-1];
    }
    return INT_MIN;
}

void delete_stack(Stack s) {
    if (s) {
        free(s->buffer);
        free(s);
    }
    return;
}

void dispatch(char *op, Stack s) {

    int val1 = 0, val2 = 0;

    switch (*op) {

        case '+': {
            val1 = gettop(s);
            pop(s);
            val2 = gettop(s);
            pop(s);
            push(s, val2);
            push(s, val1);
            push(s, val1+val2);
        }
        break;
        case 'D': {
            val1 = gettop(s);
            push(s, val1*2);
        }
        break;
        case 'C': {
            pop(s);
        }
        break;
        default: {
            push(s, atoi(op)); 
        }
    }
    return;
}


int calPoints(char** operations, int operationsSize) {

    Stack s = create_stack(BUFSIZ);
    int final = 0, val = 0;

    if (operationsSize) {
        for (int i = 0; i < operationsSize; i++) {
            dispatch(operations[i], s);        
        }

        while ((val = gettop(s)) != INT_MIN) {
            final += val;
            pop(s);
        }
    }
    delete_stack(s);
    return final;
}
