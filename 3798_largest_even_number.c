/*
 * =====================================================================================
 *
 *       Filename:  3798_largest_even_number.c
 *
 *    Description:  largest even number
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

char* largestEven(char* s) {

    int slen = strlen(s);
    int i = slen;

    for (i = slen; i > 0; i--) {
        if (s[i-1] == '2') {
            break;
        }
    }
    s[i] = '\0';
    return s;
}
