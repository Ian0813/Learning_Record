/*
 * =====================================================================================
 *
 *       Filename:  1832_check_if_the_sentence_is_pangram.c
 *
 *    Description:  Check if the sentence is pangram  
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

#define TABLE_SIZE 26

bool checkIfPangram(char* sentence) {

    char table[TABLE_SIZE] = {0};
    bool rc = true;

    for (int i = 0; i < strlen(sentence); i++) {
        table[sentence[i]-'a']++;
    }

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (!table[i]) {
            rc = false; 
            break;
        }
    }
    return rc;
}

