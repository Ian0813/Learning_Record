/*
 * =====================================================================================
 *
 *       Filename:  3120_count_the_number_of_special_characters_i.c
 *
 *    Description:  count the number of special characters i
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
    UPPERCASE = 0,
    LOWERCASE = 1,
    NUMBER_OFCASE
};

static void check_alphabet(char *word, int (*table)[TABLE_SIZE]) {

    for (int i = 0; i < strlen(word); i++) {
        if (isupper(word[i])) {
            table[UPPERCASE][CH_TO_INT(word[i], 'A')] = true;  
        } else if (islower(word[i])) {
            table[LOWERCASE][CH_TO_INT(word[i], 'a')] = true;  
        }
    }
    return;
}

int numberOfSpecialChars(char* word) {

    int table[NUMBER_OFCASE][TABLE_SIZE] = {[UPPERCASE] = {0}, [LOWERCASE] = {0}};
    int count = 0;

    check_alphabet(word, table);   

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[UPPERCASE][i] && table[LOWERCASE][i]) {
            count++;
        }
    }
    return count; 
}
