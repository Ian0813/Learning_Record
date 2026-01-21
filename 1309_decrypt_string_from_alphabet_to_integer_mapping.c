/*
 * =====================================================================================
 *
 *       Filename:  1309_decrypt_string_from_alphabet_to_integer_mapping.c
 *
 *    Description:  decrypt string from alphabet to integer mapping
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

#define ALPHABET_SIZE 26
#define INT_TO_LOWERCASE(val) ((val)+'a')
#define CH_TO_VAL(ch) ((ch)-'0')
#define POUND_SIGN '#'

static void table_init(char *table) {

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        table[i] = INT_TO_LOWERCASE(i);
    }
    return;
}

static char table_translate(char *table, int index) {
    return table ? table[index] : (char) -1; 
}

static char *decrypt(char *cipher, char *table) {

    char *plaintext = NULL;
    int len = 0, unit = 1, value = 0, pindex = 0;

    if (cipher && table) {

        len = strlen(cipher);
        plaintext = (char *) calloc(len+1, sizeof(char));

        for (int i = len-1; i >= 0; i -= unit) {
            if (isdigit(cipher[i])) {
                unit = 1;
                plaintext[pindex++] = table_translate(table, CH_TO_VAL(cipher[i])-1);
            } else if (cipher[i] == POUND_SIGN) {
                i--;
                unit = 2;
                for (int j = 0; j < unit; j++) {
                    value += (CH_TO_VAL(cipher[i-j]) * (j ? 10 : 1)); 
                }
                plaintext[pindex++] = table_translate(table, value-1);
                value = 0;
            }
        }
    }
    return plaintext;
}

static void reverse(char *str) {

    char temp = '\0';

    if (str) {
        for (int i = 0, j = strlen(str)-1; i < j; i++, j--) {
            temp = str[i];  
            str[i] = str[j];
            str[j] = temp;
        }
    }
    return;
}

char* freqAlphabets(char* s) {

    char alphabet_table[ALPHABET_SIZE] = {0};
    char *result = NULL;

    table_init(alphabet_table);

    result = decrypt(s, alphabet_table);
    reverse(result);

    return result;
}
