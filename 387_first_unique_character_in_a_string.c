/*
 * =====================================================================================
 *
 *       Filename:  387_first_unique_character_in_a_string.c
 *
 *    Description:  First unique character in a string
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

#define ALPHABET_LEN 26

int firstUniqChar(char* s) {

    int table[ALPHABET_LEN] = {0};
    int rc = -1;

    for (int i = 0; i < strlen(s); i++) {
        table[s[i]-'a']++;
    }

    for (int i = 0; i < strlen(s); i++) {
        if (table[s[i] - 'a'] == 1) {
            rc = i;
            break;
        }
    }
    return rc;
}
