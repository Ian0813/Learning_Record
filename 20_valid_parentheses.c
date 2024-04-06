/*
 * =====================================================================================
 *
 *       Filename:  20_valid_parentheses.c
 *
 *    Description:  Valid parentheses   
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
    int *buffer;
    int cur;
    int max; 
};

struct stack *create(int len) {

    struct stack *s = (struct stack *) malloc(sizeof(struct stack));

    if (s) {
        s->buffer = (int *) calloc(len, sizeof(int));
        s->cur = 0;
        s->max = len;
    }    
    return s;
}

bool push(struct stack *s, int val) {

    bool rc = true;

    if (s->cur < s->max) {
        s->buffer[s->cur++] = val;
    } else {
        rc = false;
    }
    return rc;
}

bool pop(struct stack *s) {

    bool rc = true;

    if (!s->cur) {
        rc = false;
    } else {
        s->cur--;
    }
    return rc;
}

int peek(struct stack *s) {

    if (!s->cur) {
        return -1;
    }
    return s->buffer[s->cur-1];
}

bool isempty(struct stack *s) {

    bool rc = true;

    if (s->cur) {
        rc = false;
    }
    return rc;
}

void release(struct stack *s) {

    if (s != NULL) {
        free(s->buffer);
        free(s);
    }
    return;
}

bool pair(struct stack *st, int ch) {

    bool rc = true;

    if (!isempty(st)) {
        switch (ch) {
            case ')': {
                if (peek(st) != '(') {
                    rc = false;
                } else {
                    pop(st); 
                }
            }
            break;
            case '}': {
                if (peek(st) != '{') {
                    rc = false;
                } else {
                    pop(st);
                }
            }
            break;
            case ']': {
                if (peek(st) != '[') {
                    rc = false;
                } else {
                    pop(st); 
                }

            }
            break;
            defeault:
                rc = false;
        }
    } else {
        rc = false;
    }
    return rc;
}

bool isValid(char* s) {

    struct stack *st = create(strlen(s));
    bool rc = true;

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            push(st, s[i]);  
        } else {
            if (!(rc = pair(st, s[i]))) {
                break;
            }
        }
    }

    if (!isempty(st)) {
        rc = false;
    }
    release(st);

    return rc;
}

int main(void) {

    struct stack *s = create(2);

    push(s, 10);
    push(s, 20);
    push(s, 30);

    printf("peek: %d\n", peek(s));
    pop(s);
    printf("isempty: %d\n", isempty(s));
    printf("peek: %d\n", peek(s));
    pop(s);
    printf("peek: %d\n", peek(s));
    pop(s);
    printf("isempty: %d\n", isempty(s));

    release(s);

    return EXIT_SUCCESS;

}
