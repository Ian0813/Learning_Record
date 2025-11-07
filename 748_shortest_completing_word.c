/*
 * =====================================================================================
 *
 *       Filename:  748 shortest completing word.c
 *
 *    Description:  shortest completing word
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
#include <ctype.h>
#include <limits.h>

#define ALPHABET_SIZE 26
#define CH_TO_VALUE(ch) ((ch) - 'a')

typedef enum {
    TABLE_KEEP = (1 << 0),
    TABLE_UPDATE = (1 << 1)
} table_type;

typedef struct complete_word {
    int keep_table[ALPHABET_SIZE];
    int update_table[ALPHABET_SIZE];
    int diff;
    int word_len;
    char *word;
} complete_word;

static void count_alphabet(complete_word *cp_word, char *ptr, table_type ttype) {

    int len = 0;

    if (!cp_word)
        return;

    len = strlen(ptr); 

    for (int i = 0; i < len; i++) {
        if (isalpha(ptr[i])) {
            if (ttype == TABLE_KEEP)
                cp_word->keep_table[CH_TO_VALUE(tolower(ptr[i]))]++; 
            else if (ttype == TABLE_UPDATE)
                cp_word->update_table[CH_TO_VALUE(tolower(ptr[i]))]++; 
        }
    }
    return;
}

static void check_complete_word(complete_word *cp_word, char *update_word) {

    int count_diff = 0, update_len = strlen(update_word);

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (cp_word->keep_table[i] > cp_word->update_table[i]) {
            count_diff += (abs(cp_word->keep_table[i] - cp_word->update_table[i]));
        }
    }

    if (count_diff < cp_word->diff) {
        cp_word->diff = count_diff;
        cp_word->word = update_word;
        cp_word->word_len = update_len;
    } else if (count_diff == cp_word->diff) {
        if (update_len < cp_word->word_len) {
            cp_word->word = update_word;
            cp_word->word_len = update_len;
        }    
    }

    memset(cp_word->update_table, 0, sizeof(cp_word->update_table));
    return;
}    

char* shortestCompletingWord(char* licensePlate, char** words, int wordsSize) {

    complete_word cp_word = {.word_len = INT_MAX, .word = NULL, .diff = INT_MAX};

    count_alphabet(&cp_word, licensePlate, TABLE_KEEP);    

    for (int i = 0; i < wordsSize; i++) {
        count_alphabet(&cp_word, words[i], TABLE_UPDATE);
        check_complete_word(&cp_word, words[i]);
    }

    return cp_word.word;
}
