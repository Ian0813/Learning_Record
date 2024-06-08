/*
 * =====================================================================================
 *
 *       Filename:  3121_count_the_number_of_special_characters_ii.c
 *
 *    Description:  Count the number of special character ii  
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
#define OCCURRENCE_FILEDS 2

int numberOfSpecialChars(char* word) {

    int table[ALPHABET_SIZE][OCCURRENCE_FILEDS] = {-1};
    int count[ALPHABET_SIZE] = {0}, total = 0;

	memset(table, -1, sizeof(int) * ALPHABET_SIZE * OCCURRENCE_FILEDS);

    for (int i = strlen(word)-1; i >= 0; i--) {

        if (islower(word[i])) {
            if (table[word[i]-'a'][0] == -1) {
                table[word[i]-'a'][0] = i;
                if (table[word[i]-'a'][0] < table[word[i]-'a'][1]) {
                    count[word[i]-'a'] = 1;
                }
            }
        }

        if (isupper(word[i])) {

            table[word[i]-'A'][1] = i;

            if (table[word[i]-'A'][0] != -1) {
                if (table[word[i]-'A'][1] > table[word[i]-'A'][0]) {
                    count[word[i]-'A'] = 1;
                } else {
                    count[word[i]-'A'] = 0;
                }
            }    
        }
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        total += count[i];
    }
    return total; 
}

