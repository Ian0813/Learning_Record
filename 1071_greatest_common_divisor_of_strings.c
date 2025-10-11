/*
 * =====================================================================================
 *
 *       Filename:  1071 greatest common divisor of strings.c
 *
 *    Description:  greatest common divisor of strings
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

typedef enum {false, true} bool;

#define PATTERN_COPY(s1, s2, slen, plen) ((slen == plen) ? s1 : s2)

static bool is_repeated(char *haystack, char *needle, int hlen, int nlen) {

    for (int i = 0; i < hlen; i += nlen) {
        if (memcmp(&haystack[i], needle, nlen)) {
            return false;
        }
    }
    return true;
}

char* gcdOfStrings(char* str1, char* str2) {

    int s1_len = 0, s2_len = 0, plen = 0;
    char *pattern = NULL;
    bool rc = false;

    s1_len = strlen(str1);
    s2_len = strlen(str2);

    plen = s1_len > s2_len ? s2_len : s1_len;
    pattern = (char *) calloc(plen + 1, sizeof(char));
    memcpy(pattern, PATTERN_COPY(str1, str2, s1_len, plen), plen);

    while (plen && !rc) {
        if (!(s1_len % plen) && !(s2_len % plen)) {
            rc = (is_repeated(str1, pattern, s1_len, plen) && is_repeated(str2, pattern, s2_len, plen));
        }

        if (rc) {
            break;
        }
        plen--;
    }

    pattern[plen] = '\0';
    return pattern ;
}
