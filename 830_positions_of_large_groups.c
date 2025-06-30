/*
 * =====================================================================================
 *
 *       Filename:  830_positions_of_large_groups.c
 *
 *    Description:  positions of large groups  
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

#define MAX_ITEMS 26
#define PAIR_LEN 2
#define QUALIFY_LEN 3

enum {
    S_INDEX = 0,
    E_INDEX = 1
};

typedef struct stack {
    int top;
    char *buffer;
    int size;
} Stack;

Stack *stack_init(int size) {

    Stack *obj = NULL;

    if (size) {
        obj = (Stack *) malloc(sizeof(*obj));
        obj->size = size;
        obj->buffer = (char *) calloc(size, sizeof(char));
        obj->top = 0;
    }
    return obj;
}

bool stack_push(Stack *obj, char data) {

    if (!obj || obj->top >= obj->size)
        return false;

    obj->buffer[obj->top++] = data;

    return true;
}

bool stack_pop(Stack *obj) {

    if (!obj || !obj->top) {
        return false;
    }

    obj->top--;
    return true;
}

char *stack_peek(Stack *obj) {

    if (!obj || !obj->top)
        return NULL;

    return obj->buffer + (obj->top-1);
}

void stack_delete(Stack *obj) {

    if (obj) {
        free(obj->buffer);
        free(obj);
    }
    return;
}

static int **allocate_result(int rlen, int clen) {

    int **ptr = NULL;

    ptr = (int **) calloc(rlen, sizeof(int *));

    for (int i = 0; i < rlen; i++) {
        ptr[i] = (int *) calloc(clen, sizeof(int));
    }

    return ptr;
}

static int *allocate_column_size(int len) {

    int *ptr = NULL;

    if (len) {
        ptr = (int *) calloc(len, sizeof(int));

        for (int i = 0; i < len; i++) {
            ptr[i] = PAIR_LEN;
        }
    }

    return ptr;
}

int** largeGroupPositions(char* s, int* returnSize, int** returnColumnSizes) {

    int count = 0, findex = 0;
    int **group = NULL, glen = 0;
    Stack *obj = NULL;

    group = allocate_result(BUFSIZ, PAIR_LEN);
    obj = stack_init(BUFSIZ);

    stack_push(obj, s[0]);
    findex = 0;
    count++;

    for (int i = 1; i < strlen(s); i++) {

        if (s[i] == *stack_peek(obj)) {
            count++;
        } else {
            if (count >= QUALIFY_LEN) {
                group[glen][S_INDEX] = findex;
                group[glen][E_INDEX] = i-1;
                glen++;
            }
            stack_push(obj, s[i]);
            findex = i;
            count = 1;
        }
    }

    if (count >= QUALIFY_LEN) {
        group[glen][S_INDEX] = findex;
        group[glen][E_INDEX] = strlen(s)-1;
        glen++;
    }

    *returnSize = glen;
    *returnColumnSizes = allocate_column_size(glen);
    stack_delete(obj);

    return group;
}
