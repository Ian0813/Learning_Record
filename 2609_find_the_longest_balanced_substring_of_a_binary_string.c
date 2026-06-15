/*
 * =====================================================================================
 *
 *       Filename:  2609_find_the_longest_balanced_substring_of_a_binary_string.c
 *
 *    Description:  find the longest balanced substring of a binary string
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

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int findTheLongestBalancedSubstring(char* s) {

    int zero_count = 0, one_count = 0, len = 0;;
    int maxlen = 0;

    len = strlen(s);

    for (int i = 0; i < len; i++) {

        if (s[i] == '0') {
            if (one_count) {
                zero_count = 0; 
                one_count = 0; 
            }
            zero_count++;
        }

        if (s[i] == '1') {

            one_count++;
            if (zero_count >= one_count) {
                maxlen = maxlen > (MIN(zero_count, one_count) * 2) ? maxlen : (MIN(zero_count, one_count) * 2);
            }
        }
    }

    return maxlen;
}
