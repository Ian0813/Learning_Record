/*
 * =====================================================================================
 *
 *       Filename:  946_validate_stack_sequences.c
 *
 *    Description:  Validate stack sequences  
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

typedef enum {false, true} bool;

struct stack {
    int buffer[BUFSIZ];
    int top;
};

struct stack *create_stack(void) {

    struct stack *s = NULL;

    s = (struct stack *) calloc(1, sizeof(struct stack));
    return s;
}

bool push(struct stack *s, int val) {
 
    bool rc = false;

    if (s->top < BUFSIZ) {
        s->buffer[s->top++] = val;
    } else {
        rc = false;
    }
    return rc;
}

bool pop(struct stack *s) {
 
    bool rc = false;

    if (s->top > 0) {
        s->top--;
    } else {
        rc = false;
    }
    return rc;
}

int peek(struct stack *s) {

    if (s->top > 0) {
        return s->buffer[s->top-1];    
    }
    return -1;
}

void delete_stack(struct stack *s) {

    if (s)
        free(s);
    return;
}

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize) {

    int push_index = 0, pop_index = 0;
    struct stack *s = NULL;
    bool result = true;

    s = create_stack();

    while (pop_index < poppedSize) {

        if (peek(s) == popped[pop_index]) {
            pop(s);   
            pop_index++;
        } else if (push_index < pushedSize) {

            while (pushed[push_index] != popped[pop_index]) {
                push(s, pushed[push_index]);
                push_index++;

                if (push_index >= pushedSize) {
                    result = false;    
                    break;
                }
            }

            if (pushed[push_index] == popped[pop_index]) {
                push(s, pushed[push_index]); 
                pop(s); 
                push_index++;
                pop_index++;
            }
        } else {
            result = false;
        }

        if (!result) {
            break;
        }
    }

    delete_stack(s);
    return result;
}
