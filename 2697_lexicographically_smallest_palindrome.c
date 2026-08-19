/*
 * =====================================================================================
 *
 *       Filename:  2697_lexicographically_smallest_palindrome.c
 *
 *    Description:  lexicographically smallest palindrome
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
#include <sys/param.h>

static void convert_to_palindrome(char *s, int slen) {

    char temp = '\0';

    if (!s) {
        fprintf(stderr, "[%s] Invalid argument.\n", __func__);
        return;
    }

    for (int i = 0, j = slen-1; i < j; i++, j--) {
        temp = MIN(s[i], s[j]);
        s[i] = s[j] = temp;
    }
    return;
}

char* makeSmallestPalindrome(char* s) {
    if (s) {
        convert_to_palindrome(s, strlen(s));
    }
    return s;
}
