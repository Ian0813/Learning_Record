/*
 * =====================================================================================
 *
 *       Filename: 3794_reverse_string_prefix.c
 *
 *    Description: reverse string prefix
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

static void swap(char *c1, char *c2) {

    char temp = *c1;

    *c1 = *c2;
    *c2 = temp;

    return;
}    

char* reversePrefix(char* s, int k) {

    int slen = strlen(s);

    slen = slen > k ? k : slen;

    for (int i = 0, j = slen-1; i < j; i++, j--) {
        swap(&s[i], &s[j]);
    }

    return s;
}
