/*
 * =====================================================================================
 *
 *       Filename:  2309_greatest_english_letter_in_upper_and_lower_case.c
 *
 *    Description:  greatest english letter in upper and lower case
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

typedef enum {false, true} bool;

#define TABLE_SIZE 26
#define CH_TO_INT(ch, start) ((ch)-start)

enum {
    LOWERCASE = 0,
    UPPERCASE = 1,
    NUMBER_OF_TYPES
};

static void check_alphabet(char *s, int (*table)[TABLE_SIZE]) {

    for (int i = 0; i < strlen(s); i++) {
        if (isupper(s[i])) {
            table[UPPERCASE][CH_TO_INT(s[i], 'A')] = true;
        } else if (islower(s[i])) {
            table[LOWERCASE][CH_TO_INT(s[i], 'a')] = true;
        }
    }
    return;
}

char* greatestLetter(char* s) {

    char *result = (char *) calloc(2, sizeof(char));
    int table[NUMBER_OF_TYPES][TABLE_SIZE] = {[LOWERCASE] = {0}, [UPPERCASE] = {0}};

    check_alphabet(s, table);

    for (int i = TABLE_SIZE-1; i >= 0; i--) {
        if (table[UPPERCASE][i] && table[LOWERCASE][i]) {
            result[0] = i + 'A';
            break;
        }
    }
    return result;
}
