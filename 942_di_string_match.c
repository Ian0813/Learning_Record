/*
 * =====================================================================================
 *
 *       Filename:  942_di_string_match.c
 *
 *    Description:  di string match
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04.2) 11.4.0
 *
 *         Author:  Ian
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

enum {
    LETTER_I = 'I',
    LETTER_D = 'D'
};

int* diStringMatch(char* s, int* returnSize) {

    int *number_list = NULL, len = strlen(s), nindex = 0;
    int *result = NULL;

    number_list = (int *) malloc(sizeof(int) * (len+1));
    result = (int *) malloc(sizeof(int) * (len+1));

    memset(result, 0, sizeof(int) * (len+1));

    for (int i = 0; i <= len; i++) {
        number_list[i] = i;
    }

    for (int i = 0, nindex = 0; i < len; i++) {
        if (s[i] == LETTER_I) {
            result[i] = number_list[nindex++];
            number_list[nindex - 1] = -1;
        }
    }

    for (int i = 0, nindex = len; i < len; i++) {
        if (s[i] == LETTER_D) {
            result[i] = number_list[nindex--];
            number_list[nindex + 1] = -1;
        }    
    }

    for (int i = 0; i < len+1; i++) {
        if (number_list[i] != -1) {
            result[len] = i;
            break;
        }
    }

    *returnSize = len + 1;
    free(number_list);

    return result;
}
