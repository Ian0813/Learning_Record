/*
 * =====================================================================================
 *
 *       Filename:  1544_make_the_string_great.c
 *
 *    Description:  make the string great
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

typedef enum {false, true} bool;

#define MAXSIZE BUFSIZ

typedef struct {
    char buffer[BUFSIZ];
    char top;
} Stack;

static Stack *stack_create(void) {

    Stack *obj = NULL;

    obj = (Stack *) calloc(1, sizeof(Stack));

    return obj; 
}

static bool stack_push(Stack *obj, char ch) {

    if (!obj)    
        return false;

    if (obj->top == MAXSIZE)
        return false;

    obj->buffer[obj->top++] = ch;

    return true;
}

static bool stack_pop(Stack *obj) {

    if (!obj || !obj->top)
        return false;

    obj->top--;

    return true;
}

static char stack_gettop(Stack *obj) {

    char ch = -1;

    if (!obj)
        return ch;

    if (obj->top)
        ch = obj->buffer[obj->top-1];
    return ch;
}

static bool stack_delete(Stack *obj) {

    if (!obj)
        return false;

    free(obj);

    return true;
}

#define IS_DELETE(a, b) ((a) > (b) ? ((a-32) == (b)) : ((b-32) == (a)))

char* makeGood(char* s) {

    Stack *obj = NULL;
    char *result = NULL, temp = '\0';
    int len = 0, rindex = 0;

    len = strlen(s);
    result = (char *) calloc(len + 1, sizeof(char));

    obj = stack_create();

    if (len) {

        stack_push(obj, s[0]);

        for (int i = 1; i < len; i++) {

            temp = stack_gettop(obj);

            if (IS_DELETE(temp, s[i])) {
                stack_pop(obj); 
            } else {
                stack_push(obj, s[i]);
            }
        }

        while ((temp = stack_gettop(obj)) != (char) -1) {
            result[rindex++] = temp;
            stack_pop(obj);
        }

        for (int i = 0, j = rindex-1; i < j; i++, j--) {
            temp = result[i];
            result[i] = result[j]; 
            result[j] = temp;
        }
    }

    stack_delete(obj);

    return result;
}
