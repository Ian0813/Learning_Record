/*
 * =====================================================================================
 *
 *       Filename:  3_longest_substring_without_repeating_characters.c
 *
 *    Description:  longest substring without repeating characters
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
#include <limits.h>

typedef enum {false, true} bool;

#define TABLE_SIZE (CHAR_MAX+1)

static int get_longest_substring(char *s, int slen) {

    int temp = 0, max_length = 0;
    char tracker[TABLE_SIZE] = {0};

    for (int right = 0, left = 0; right < slen; right++) {

        if (tracker[s[right]]) {

            if (temp > max_length) {
                max_length = temp;
            }

            for (left; s[left] != s[right]; left++) {
                temp--;
                tracker[s[left]] = false;
            }
            left++;

        } else {
            temp++;
            tracker[s[right]] = true;
        }
    }

    if (temp > max_length) {
        max_length = temp;
    }

    return max_length;
}

int lengthOfLongestSubstring(char* s) {

    int result = 0;

    result = get_longest_substring(s, strlen(s));

    return result;
}
