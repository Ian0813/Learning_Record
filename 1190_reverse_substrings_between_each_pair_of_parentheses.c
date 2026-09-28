/*
 * =====================================================================================
 *
 *       Filename:  1190_reverse_substrings_between_each_pair_of_parentheses.c
 *
 *    Description:  Reverse substrings between each pair of parentheses  
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

static void recursive_reverse(char *s, int index, int len, char token) {

    int end_index = index + 1;
    char temp = '\0';

    if (end_index < len) {
        for (; s[end_index] != '\0' && s[end_index] != ')'; end_index++) {
            if (s[end_index] == '(') {
                recursive_reverse(s, end_index, len, token);
            }
        }

        if (s[end_index] == '\0') {
            return;
        }

        s[index] = token;
        s[end_index] = token;

        while (index < end_index) {
            temp = s[index]; 
            s[index++] = s[end_index];
            s[end_index--] = temp;
        }
    }
    return;
}

static void remove_token(char *s, int len, char token) {

    int index = 0;

    for (int i = 0; i < len ; i++) {
        if (s[i] == token)
            continue;
        s[index++] = s[i];
    }
    s[index] = '\0';

    return;
}

char* reverseParentheses(char* s) {

    int len = 0;

    if (s) {

        len = strlen(s);

        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] == '(') {
                recursive_reverse(s, i, len, '#');
            }
        }
        remove_token(s, len, '#');
    }
    return s;
}
