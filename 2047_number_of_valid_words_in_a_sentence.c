/*
 * =====================================================================================
 *
 *       Filename:  2047_number_of_valid_words_in_a_sentence.c
 *
 *    Description:  number of valid words in a sentence
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
#include <unistd.h>
#include <ctype.h>

typedef enum {false, true} bool;

#define CHECK_FRONT(word, ch) (*word == ch) 
#define CHECK_TAIL(word, len, ch) (word[len-1] == ch) 

static bool is_valid(char *word) {

    int wlen = strlen(word);
    int hyphen_count = 0;

    if (CHECK_FRONT(word, '-') || CHECK_TAIL(word, wlen, '-'))
        return false;

        for (int i = 0; i < wlen; i++) {
        if (isdigit(word[i]))
            return false;

        if (word[i] == '-')
            hyphen_count++;

        if (word[i] == '-' && (!isalpha(word[i+1]) || !isalpha(word[i-1])))
            return false;

        if ((word[i] == '!' || word[i] == ',' || word[i] == '.') && i != (wlen-1)) {
            return false;
        }
    }

    if (hyphen_count > 1)
        return false;
    return true;
}    

int countValidWords(char* sentence) {

    char *ptr = NULL;    
    int valid_count = 0;

    ptr = strtok(sentence, " ");

    while (ptr) {
        if (is_valid(ptr)) {
            valid_count++;
        }
        ptr = strtok(NULL, " ");
    }

    return valid_count;
}
