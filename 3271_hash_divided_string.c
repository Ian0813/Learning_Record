/*
 * =====================================================================================
 *
 *       Filename:  3271_hash_divided_string.c
 *
 *    Description:  hash divided string
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

#define CH_TO_INT(ch) ((ch)-'a')
#define ROUND_SIZE 26
#define INT_TO_CHAR(val) ((val)+'a')

char get_hashchar(char *str, int len) {

    int sum = 0;    

    for (int i = 0; i < len; i++) {
        sum += CH_TO_INT(str[i]);
    }

    sum %= ROUND_SIZE;
    return INT_TO_CHAR(sum);
}

char* stringHash(char* s, int k) {

    char *result = NULL;     
    int length = strlen(s)/k, index = 0;

    if (length) {
        result = (char *) calloc(length+1, sizeof(char));
        for (int i = 0; i < strlen(s); i += k) {
            result[index++] = get_hashchar(&s[i], k);
        }
    }
    result[index] = '\0';
    return result;
}
