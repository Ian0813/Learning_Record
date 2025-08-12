/*
 * =====================================================================================
 *
 *       Filename:  3163_string_compression_iii.c
 *
 *    Description:  string compression iii
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
#include <stdint.h>

#define MAX_NUMBER 9
#define MAX_SIZE (200000)
#define UNIT 10000

#define IS_REALLOC(length, boundary, ptr) \
        if ((length) >= boundary) {\
            boundary += UNIT;\
            ptr = (char *) reallocarray(ptr, boundary, sizeof(char));\
        }

static void compress_append(char *str, int number, char ch) {
    sprintf(str, "%d%c", number, ch);
    return;
}

char* compressedString(char* word) {

    uint8_t previous = 0, flag = 0;
    char *str = NULL;
    long int wordlen = strlen(word);
    int count = 0, length = 0, boundary = MAX_SIZE;

    str = (char *) calloc(MAX_SIZE, sizeof(char));

    previous = word[0];
    count = 1;

    for (int i = 1; i < wordlen; i++) {

        if (word[i] == previous && count < MAX_NUMBER) {
            count++;
        } else {

            IS_REALLOC(length + 2, boundary, str);
            compress_append(str + length, count, previous);
            length += 2;
            previous = word[i];
            count = 1;
        }
    }

    IS_REALLOC(length + 2, boundary, str);
    compress_append(str, count, previous);

    return str;
}
