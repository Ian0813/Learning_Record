/*
 * =====================================================================================
 *
 *       Filename:  394 decode string.c
 *
 *    Description:  decode string
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

#define MAXLEN 100001

typedef struct {
    char *array;
    int index;
    int size;
} Stack;

typedef enum {
    BRACKET_L = '[',
    BRACKET_R = ']'
} bracket_t;

static Stack *Stack_init(int size) {

    Stack *obj = NULL;

    obj = (Stack *) malloc(sizeof(Stack));

    if (obj) {
        obj->array = (char *) calloc(size, sizeof(char));
        obj->index = 0;
        obj->size = size;
    }
    return obj;
}

static bool Stack_push(Stack *obj, char ch) {

    if (!obj)
        return false;

    if (obj->index < obj->size) {
        obj->array[obj->index++] = ch;
        return true;
    }
    return false;
}

static bool Stack_pop(Stack *obj) {

    if (!obj)
        return false;

    if (obj->index) {
        obj->index--;
        return true;
    }
    return false;
}

static char Stack_peak(Stack *obj) {

    if (!obj) 
        return (char) -1;

    if (obj->index) {
        return obj->array[obj->index-1];
    }
    return (char) -1;
}

static void Stack_deinit(Stack *obj) {

    if (obj) {
        free(obj->array);
        free(obj);
    }
    return;
}

static void reverse(char *str, int len) {

    char ch = '\0';

    for (int i = 0, j = len-1; i < j; i++, j--) {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
    }
    return;
}

static bool get_assemble_string(Stack *data, Stack *brackets, char *temp, int *tindex) {

    int times = 0, len = 0, temp_value = 0, step = 1;
    char ch = '\0';

    if (!data || !brackets || !temp)
        return false;

    if (Stack_peak(brackets) != BRACKET_L)
        return false;

    Stack_pop(brackets);

    while (((ch = Stack_peak(data)) != (char) -1) && ch != BRACKET_L) {
        temp[*tindex] = ch;
        *tindex += 1; 
        Stack_pop(data);
    }

    if (ch == BRACKET_L)
        Stack_pop(data);

    ch = Stack_peak(data);

    while (isdigit(ch)) {
        temp_value = ch - '0';
        Stack_pop(data);
        ch = Stack_peak(data);
        times += (temp_value * step);
        step *= 10;
    }

    reverse(temp, *tindex);

    for (int i = 0, len = *tindex; i < (times-1); i++) {
        memcpy(&temp[*tindex], &temp[0], len * sizeof(char));
        *tindex += len;
    }

    return true;
}

char* decodeString(char* s) {

    Stack *data_set = NULL, *brackets = NULL;    
    int slen = 0, pindex = 0;
    char *ptr = NULL, ch = '\0';

    if (s) {

        slen = strlen(s);
        ptr = (char *) calloc(MAXLEN, sizeof(char));
        data_set = Stack_init(MAXLEN);
        brackets = Stack_init(MAXLEN);

        for (int i = 0; i < slen; i++) {
            if (isalnum(s[i])) {
                Stack_push(data_set, s[i]);
            } else if (s[i] == BRACKET_L) {
                Stack_push(brackets, s[i]);
                Stack_push(data_set, s[i]);
            } else if (s[i] == BRACKET_R) {
                get_assemble_string(data_set, brackets, ptr, &pindex);
                for (int i = 0; i < pindex; i++) {
                    Stack_push(data_set, ptr[i]); 
                }
                memset(ptr, 0, sizeof(char) * pindex);
                pindex = 0;
            }
        }

        while ((ch = Stack_peak(data_set)) != (char) -1) {
            ptr[pindex++] = ch;
            Stack_pop(data_set);
        }

        reverse(ptr, pindex);

        Stack_deinit(data_set);
        Stack_deinit(brackets);
    }
    return ptr;
}
