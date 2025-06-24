/*
 * =====================================================================================
 *
 *       Filename:  2351_first_letter_to_appear_twice.c
 *
 *    Description:  first letter to appear twice
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

#define ALPHABET_TABLE_SIZE 26
#define TWICE 2
#define CH_TO_INDEX(ch) ((ch)-'a')

typedef enum {false, true} bool;

static bool check_appear_twice(int *table, char ch) {

    table[CH_TO_INDEX(ch)]++;

    if (table[CH_TO_INDEX(ch)] == TWICE) {
        return true;
    }

    return false;
}

char repeatedCharacter(char* s) {

    int table[ALPHABET_TABLE_SIZE] = {0};
    int index = 0;

    for (index; index < strlen(s); index++) {
        if (check_appear_twice(table, s[index])) {
            break;
        }
    }

    return s[index];
}
