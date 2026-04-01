/*
 * =====================================================================================
 *
 *       Filename:  1417_reformat_the_string.c
 *
 *    Description:  reformat the string
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
#include <ctype.h>

#define MAXLEN 500

typedef struct {
    char *alphabets;
    int size;
} alphabet_set;

typedef struct {
    char *digits;
    int size;
} digit_set;

char* reformat(char* s) {

    alphabet_set alpha_info = {0};
    digit_set digit_info = {0};
    char *result = NULL;
    int slen = 0, rindex = 0, i, j;

    if (s) {

        slen = strlen(s);
        result = (char *) calloc(MAXLEN+1, sizeof(char));
        alpha_info.alphabets = (char *) calloc(MAXLEN+1, sizeof(char));
        digit_info.digits = (char *) calloc(MAXLEN+1, sizeof(char));

        for (int i = 0; i < slen; i++) {
            if (isalpha(s[i])) {
                alpha_info.alphabets[alpha_info.size++] = s[i];
            } else if (isdigit(s[i])) {
                digit_info.digits[digit_info.size++] = s[i];
            }
        }

        if (abs(alpha_info.size - digit_info.size) <= 1) {
            for (i = 0, j = 0; i < alpha_info.size && j < digit_info.size; i++, j++) {
                if (alpha_info.size > digit_info.size) {
                    result[rindex++] = alpha_info.alphabets[i];
                    result[rindex++] = digit_info.digits[i];
                } else {
                    result[rindex++] = digit_info.digits[i];
                    result[rindex++] = alpha_info.alphabets[i];
                }
            }

            if (rindex) {
                if (i < alpha_info.size && isdigit(result[rindex-1])) {
                    result[rindex++] = alpha_info.alphabets[i];
                }

                if (j < digit_info.size && isalpha(result[rindex-1])) {
                    result[rindex++] = digit_info.digits[i];
                }
            } else if (digit_info.size == 1 && !alpha_info.size) {
                result[rindex++] = digit_info.digits[0];
            } else if (!digit_info.size && alpha_info.size == 1) {
                result[rindex++] = alpha_info.alphabets[0];
            }
        }

        free(alpha_info.alphabets);
        free(digit_info.digits);
    }

    return result;
}
