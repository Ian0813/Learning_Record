/*
 * =====================================================================================
 *
 *       Filename:  22_generate_parentheses.c
 *
 *    Description:  Generate parentheses  
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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct stack {
    int top;
    char buffer[BUFSIZ];
};

struct stack *create_stack(void) {

    struct stack *s = (struct stack *) malloc(sizeof(struct stack)); 

    if (s) {
        s->top = 0;
        memset(s->buffer, 0, sizeof(char) * BUFSIZ);
    }
    return s;
}

bool push(struct stack *s, char ch) {

    bool rc = true;

    if (s) {
        if (s->top < BUFSIZ) {
            s->buffer[s->top++] = ch;
        } else {
            rc = false;
        }
    }
    return rc;
}

bool pop(struct stack *s) {

    bool rc = true;

    if (s) {
        if (s->top > 0) {
            s->top--;
            s->buffer[s->top] = 0;
        } else {
            rc = false;
        }
    }
    return rc;
}

bool is_empty(struct stack *s) {

    bool rc = true;

    if (s->top > 0)
        rc = false;
    return rc;
}

char seeking(struct stack *s) {

    char ch = -1;

    if (s) {
        if (s->top > 0) {
            ch = s->buffer[s->top-1];
        }
    }
    return ch;
}

void delete_stack(struct stack *s) {
    if (s)
        free(s);
    return;
}

bool check_valid(char *str) {

    struct stack *s = create_stack();    
    bool rc = true;

    if (s) {

        for (int i = 0; i < strlen(str); i++) {
            if (str[i] == '(') {
                push(s, str[i]);
            } else if (str[i] == ')') {
                if (seeking(s) != '(') {
                    rc = false;
                    break;
                }
                pop(s);
            } else {
                rc = false;
                break;
            }
        }

        if (!is_empty(s)) {
            rc = false;
        }
    }

    delete_stack(s);
    return rc;
}

void combination_checker(char *str, int op_num, int cp_num, int pair_num, char **result, int *index) {

    if (strlen(str) == (pair_num*2)) {
        if (check_valid(str)) {
            result[*index] = strdup(str);
            *index += 1;
        }
        return;
    }

    if (op_num < pair_num) {
        str[strlen(str)] = '('; 
        combination_checker(str, op_num+1, cp_num, pair_num, result, index);
        str[strlen(str)-1] = '\0';
    }
    
    if (cp_num < op_num) {
        str[strlen(str)] = ')';
        combination_checker(str, op_num, cp_num+1, pair_num, result, index);
        str[strlen(str)-1] = '\0';
    }
}

char** generateParenthesis(int n, int* returnSize) {

    char **result = (char **) calloc(BUFSIZ, sizeof(char *)); 
    char str[BUFSIZ] = {0}, temp[BUFSIZ] = {0};
    int index = 0;

    if (n > 0) {
        combination_checker(str, 0, 0, n, result, &index);
    }

    *returnSize = index;
    return result;
}

