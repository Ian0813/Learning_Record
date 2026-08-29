/*
 * =====================================================================================
 *
 *       Filename:  921_minimum_add_to_make_parentheses_valid.c
 *
 *    Description:  minimum add to make parentheses valid
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04.3) 11.4.0
 *
 *         Author:  Ian
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

typedef struct {
    char *data;  
    int curpos;
    int stack_size;
} Stack;

static Stack *stack_init(int size) {

    Stack *obj = NULL;

    if (!size)
        return NULL;

    obj = calloc(1, sizeof(Stack));

    if (obj) {
        obj->data = calloc(size, sizeof(char));

        if (!obj->data) {
            free(obj);    
            return NULL;
        }
        obj->curpos = 0;
        obj->stack_size = size;
    }
    return obj;
}

static bool stack_push(Stack *obj, char ch) {

    if (!obj)
        return false;

    if (obj->curpos >= obj->stack_size) {
        return false;
    }

    obj->data[obj->curpos++] = ch;
    return true;
}

static bool stack_pop(Stack *obj) {

    if (!obj)
        return false;

    if (!obj->curpos) {
        return false;
    }

    obj->curpos--;
    return true;
}

static bool stack_isempty(Stack *obj) {

    if (!obj)
        return false;

    if (!obj->curpos)
        return true;

    return false;
}

static char stack_gettop(Stack *obj) {

    if (stack_isempty(obj))
        return (char) -1;

    return obj->data[obj->curpos-1];
}

static bool stack_free(Stack *obj) {

    if (!obj)
        return false;

    if (obj->data)
        free(obj->data); 

    free(obj);
    return true;
}

int minAddToMakeValid(char* s) {

    Stack *open_obj = NULL, *close_obj = NULL;    
    int add_count = 0, slen = 0;

    open_obj = stack_init(BUFSIZ);
    close_obj = stack_init(BUFSIZ);

    if (open_obj && close_obj) {

        slen = strlen(s); 

        for (int i = 0; i < slen; i++) {
            if (s[i] == '(') {
                stack_push(open_obj, s[i]); 
            } else if (s[i] == ')') {
                if (stack_gettop(open_obj) == '(') {
                    stack_pop(open_obj); 
                } else {
                    stack_push(close_obj, s[i]);
                }
            }
        }

        while (!stack_isempty(open_obj)) {
            stack_pop(open_obj);
            add_count++;
        }

        while (!stack_isempty(close_obj)) {
            stack_pop(close_obj);
            add_count++;
        }
    }
           
    stack_free(open_obj);
    stack_free(close_obj);
    return add_count; 
}
