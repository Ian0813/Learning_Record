/*
 * =====================================================================================
 *
 *       Filename:  32_longest_valid_parentheses.c
 *
 *    Description:  Longest valid parentheses   
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

struct data {
    int index; 
    char ch;
};

struct stack {
    int top;
    struct data buffer[BUFSIZ];
};

typedef struct stack *stackptr;

stackptr create_stack(void) {

    stackptr s = NULL;
s = (stackptr) malloc(sizeof(struct stack));

    if (s) {
        s->top = 0;      
        memset(s->buffer, 0, sizeof(s->buffer));
    }
    return s;
}

bool push(stackptr s, char ch, int index) {

    bool rc = true;

    if (s) {
        if (s->top < BUFSIZ) {
            s->buffer[s->top].ch = ch;
            s->buffer[s->top].index = index;
            s->top++;
        } else {
            rc = false;
        }
    } else {
        rc = false;
    }

    return rc;
}

bool pop(stackptr s) {

    bool rc = true;

    if (s) {
        if (s->top > 0) {
            s->top--;    
        } else {
            rc = false;
        }
    } else {
        rc = false;
    }
    return rc;
}

bool isempty(stackptr s) {

    bool rc = true; 

    if (s) {
        if (s->top)
            rc = false; 
    } else {
        rc = false;      
    }
    return rc;
}

struct data *seeking(stackptr s) {

    if (s) {
        if (s->top) {
            return &s->buffer[s->top-1];
        }
    }
    return NULL;
}

void delete_stack(stackptr s) {

    if (s)
        free(s);
    return;
}

int longestValidParentheses(char* s) {

    stackptr stk = NULL;
    int *recorder = (int *) calloc(strlen(s), sizeof(int));
    int count = 0, max = 0; 
    struct data *node = NULL;

    if (strlen(s)) {

        stk = create_stack();

        for (int i = 0; i < strlen(s); i++) {
            if (s[i] == '(') {
                push(stk, s[i], i);
            } else if (s[i] == ')') {
                node = seeking(stk);
                pop(stk);
                if (node) {
                    if (node->ch == '(') {
                        recorder[i] = 1; 
                        recorder[node->index] = 1;
                    }
                }
            }
        }

        for (int i = 0; i < strlen(s); i++) {
            if (recorder[i]) 
                count++;
            else
                count = 0;
			if (count > max) {
                max = count;
			}
        }
    }    
    free(recorder);
    return max; 
}
