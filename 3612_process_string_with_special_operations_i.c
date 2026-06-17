/*
 * =====================================================================================
 *
 *       Filename:  3612_process_string_with_special_operations_i.c
 *
 *    Description:  process string with special operations i
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

#define MAX_ROUND 20

static unsigned int get_maximum_size(void) {

    unsigned int value = 1;

    for (int i = 0; i < MAX_ROUND; i++) {
        value *= 2U;
    }
    return value;
}    

static void reverse(char *s, int len) {

    char temp = '\0';

    for (int i = 0, j = len-1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }

    return;
}

static void str_process(char op, char *result, int *index) {

    int curlen = *index;

    if (isalpha(op)) {
        result[*index] = op;
        *index += 1;
    } else {
        if (*index) {
            switch (op) {

                case '*':    
                    result[*index-1] = '\0';
                    *index -= 1;
                break;
                case '#':
                    for (int i = 0; i < curlen; i++) {
                        result[*index] = result[i]; 
                        *index += 1;
                    }
                break;
                case '%':
                    reverse(result, *index); 
                break;
            }
        }
    }
    return;
}

char* processStr(char* s) {

    char *result = NULL;
    int slen = 0, index = 0;

    slen = strlen(s);
    result = (char *) calloc(get_maximum_size(), sizeof(char));

    for (int i = 0; i < slen; i++) {
        str_process(s[i], result, &index);
    }

    return result;
}
