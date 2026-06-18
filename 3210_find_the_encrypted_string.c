/*
 * =====================================================================================
 *
 *       Filename:  3210_find_the_encrypted_string.c
 *
 *    Description:  find the encrypted string
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

char* getEncryptedString(char* s, int k) {

    int len = 0;
    char *result = NULL;

    if (s) {
        len = strlen(s);
        result = (char *) calloc(len + 1, sizeof(char)); 

        for (int i = 0; i < len; i++) {
            result[i] = s[(i+k)%len];
        }
    }
    return result;
}
