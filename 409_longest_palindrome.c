/*
 * =====================================================================================
 *
 *       Filename:  409_longest_palindrome.c
 *
 *    Description:  Longest palindrome  
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
#include <ctype.h>

#define ALPHABET_SIZE 26

int is_palindrome(char *s) {

    for (int i = 0, j = strlen(s)-1; i < j; i++, j--) {
        if (s[i] != s[j])
            return 0; 
    }
    return strlen(s);
}

int longestPalindrome(char* s) {

    int lower_table[ALPHABET_SIZE] = {0};
    int upper_table[ALPHABET_SIZE] = {0};
    int length = 0;
    int flag = 0;

    if (!(length = is_palindrome(s))) {

        for (int i = 0; i < strlen(s); i++) {

            if (islower(s[i])) {
                lower_table[s[i]-'a']++; 
                
            }

            if (isupper(s[i])) {
                upper_table[s[i]-'A']++;
            }
        }

        for (int i = 0; i < ALPHABET_SIZE; i++) {
            if (upper_table[i]) {
                length += (upper_table[i]/2)*2;
            }

            if (lower_table[i]) {
                length += (lower_table[i]/2)*2;
            }

            if ((upper_table[i] == 1 || lower_table[i] == 1) && !flag) {
                flag = 1;
            }
        }

        if (flag)
            length += 1;

        if (!(length%2) && (length < strlen(s)))
            length += 1;

    }
    return length;
}
