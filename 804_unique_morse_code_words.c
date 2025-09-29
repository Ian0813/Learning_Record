/*
 * =====================================================================================
 *
 *       Filename:  804 unique morse code words.c
 *
 *    Description:  unique morse code words
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04.2) 11.4.0
 *
 *         Author:  Ian
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define CH_TO_INDEX(ch) ((ch)-'a')

#define TABLE_LEN 26

static void morse_decode(char **morse_code, int index, char *word, const char table[][TABLE_LEN]) {

    char buf[BUFSIZ] = {0};    
    int len = strlen(word);

    for (int i = 0; i < len; i++) {
       strcat(buf, table[CH_TO_INDEX(word[i])]); 
    }

    morse_code[index] = strdup(buf);
    return;
}

int uniqueMorseRepresentations(char** words, int wordsSize) {

    const char morse_code_table[TABLE_LEN][TABLE_LEN] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

    char **morse_code = NULL;
    int count_diff = 0;

    if (words) {

        morse_code = (char **) calloc(wordsSize, sizeof(char *));

        for (int i = 0; i < wordsSize; i++) {
            morse_decode(morse_code, i, words[i], morse_code_table); 
        }

        for (int i = 0; i < wordsSize; i++) {

            if (morse_code[i]) {

                count_diff++;

                for (int j = i+1; j < wordsSize; j++) {

                    if (!morse_code[j])
                        continue;

                    if (!strcmp(morse_code[i], morse_code[j])) {
                        free(morse_code[j]); 
                        morse_code[j] = NULL;
                    }
                }    
            }    
            free(morse_code[i]);
            morse_code[i] = NULL;
        }
        free(morse_code);
    }    

    return count_diff;
}
