/*
 * =====================================================================================
 *
 *       Filename:  541_reverse_string_ii.c
 *
 *    Description:  Reverse string ii  
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

static void reverse(char *s, int f, int t) {

    char temp = '\0';

    for (; f < t; f++, t--) {
        temp = s[f];
        s[f] = s[t];
        s[t] = temp;
    }
    return;
}

char* reverseStr(char* s, int k) {

    int loc = 0;
    int size = 0;

    if (strlen(s)) {
        if (strlen(s) > k) {
            for (; loc < strlen(s); loc += (2*k)) {
                if ((loc+k-1) > strlen(s)-1) {
                    reverse(s, loc, strlen(s)-1); 
                } else {
                    reverse(s, loc, loc+k-1); 
                }
            }

        } else {
            reverse(s, 0, strlen(s)-1);
        }
    }
    return s;
}
