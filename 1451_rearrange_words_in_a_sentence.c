/*
 * =====================================================================================
 *
 *       Filename:  1451_rearrange_words_in_a_sentence.c
 *
 *    Description:  rearrange words in a sentence
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04.3) 11.4.0
 *
 *         Author:  Ian
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include <ctype.h>

#define DELIMITER " "

typedef struct {
    char *str;    
    size_t len;
} word_t;

static void swap_word_array(word_t *w1, word_t *w2) {

    word_t word = {0};

    memcpy(&word, w1, sizeof(word_t));
    memcpy(w1, w2, sizeof(word_t));
    memcpy(w2, &word, sizeof(word_t));

    return;
}

static word_t *allocate_word_array(int size) {

    word_t *arr = NULL; 

    if (size > 0) {
        arr = calloc(size, sizeof(*arr));
    }
    return arr;
}

static void free_word_array(word_t *array) {
    return free(array);
}

static void append_word_array(word_t *array, int *arrlen, char *word) {

    if (!array || !arrlen || !word)
        return;

    array[*arrlen].str = word;
    array[*arrlen].len = strlen(word);
    *arrlen += 1;

    for (int i = *arrlen-1; i; i--) {
        if (array[i].len < array[i-1].len) {
            swap_word_array(&array[i], &array[i-1]);     
        }    
    }
    return; 
}

static void show_word_array(word_t *array, int arrlen) {

    for (int i = 0; i < arrlen; i++) {
        fprintf(stdout, "[%s] word : %s, wordlen : %lu\n", __func__, array[i].str, array[i].len);
    }
    return;
}

static void form_string_word_array(word_t *array, int arrlen, char *result) {

    int rlen = 0;    

    for (int i = 0; i < arrlen; i++) {

        if (!i)
            array[i].str[0] = toupper(array[i].str[0]);
        else
            array[i].str[0] = tolower(array[i].str[0]);

        memcpy(&result[rlen], array[i].str, array[i].len); 
        rlen += array[i].len;

        if (i < (arrlen-1)) {
            result[rlen] = ' ';
            rlen++;
        }
    }

    result[rlen] = '\0';
    return;
}

char* arrangeWords(char* text) {

    word_t *arr = NULL;
    char *result = NULL, *ptr = NULL;
    int tlen = 0, arrlen = 0;

    if (text) {

        tlen = strlen(text);
        result = calloc(tlen+1, sizeof(char));
        arr = allocate_word_array(tlen); 

        ptr = strtok(text, DELIMITER);

        while (ptr) {
            append_word_array(arr, &arrlen, ptr);
            ptr = strtok(NULL, DELIMITER);
        }
        form_string_word_array(arr, arrlen, result);
        free_word_array(arr);
    }
    return result;
}
