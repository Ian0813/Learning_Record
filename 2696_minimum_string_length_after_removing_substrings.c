/*
 * =====================================================================================
 *
 *       Filename:  2696_minimum_string_length_after_removing_substrings.c
 *
 *    Description:  minimum string length after removing substrings
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
#include <ctype.h>

typedef enum {false, true} bool; 

#define PATTERN_AB "AB"
#define PATTERN_CD "CD"
#define PATTERN_LEN 2 

typedef struct stack_op {
    char *buffer;
    int top;
    int bufsize;
} Stack;

static Stack *stack_create(int size) {

    Stack *obj = NULL;

    obj = (Stack *) malloc(sizeof(Stack));

    obj->buffer = (char *) calloc(size, sizeof(char)); 
    obj->top = 0;
    obj->bufsize = size;

    return obj;
}

static bool stack_push(Stack *obj, char ch) {

    if (!obj)
        return false;

    if (!isupper(ch))
        return false;

    if (obj->top >= obj->bufsize)
        return false;

    obj->buffer[obj->top++] = ch;

    return true;
}
        
static char stack_pop(Stack *obj) {

    char ch = -1;

    if (!obj)
        return ch;

    if (!obj->top)
        return ch;

    ch = obj->buffer[--obj->top];

    return ch;
}

static char stack_top(Stack *obj) {

    char ch = -1;

    if (!obj)
        return ch;

    if (!obj->top)
        return ch;

    ch = obj->buffer[obj->top];

    return ch;
}

static void stack_free(Stack *obj) {

    if (obj) {
        free(obj->buffer);
        free(obj);
    }

    return;
}

static bool check_pattern(char *ptr) {

    if (!memcmp(ptr, PATTERN_AB, PATTERN_LEN)) {
        return true;
    } else if (!memcmp(ptr, PATTERN_CD, PATTERN_LEN)) {
        return true;
    }

    return false;
}

static void reverse(char *str, int len) {

    char ch = '\0'; 

    for (int i = 0, j = len - 1; i < j; i++, j--) {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;    
    }

    return;
}

int minLength(char* s) {

    Stack *obj = NULL;     
    char buffer[BUFSIZ] = {0};
    int index = 0, len = 0;
    bool flag = true;

    len = strlen(s);
    obj = stack_create(BUFSIZ);

    memcpy(buffer, s, len);

    while (flag) {

        flag = false;

        while (index < len) {
            if (check_pattern(&buffer[index])) {
                index += 2;
                flag = true;
            } else {
                stack_push(obj, buffer[index]);
                index++; 
            }
        }

        memset(buffer, 0, sizeof(char) * len);
        index = 0;

        while ((buffer[index] = stack_pop(obj)) != (char) -1)
            index++;

        len = index;
        index = 0;
        reverse(buffer, len);
    }

    if (obj)
        stack_free(obj);

    return len; 
}
