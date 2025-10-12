/*
 * =====================================================================================
 *
 *       Filename:  709 to lower case.c
 *
 *    Description:  to lower case
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

#define TO_LOWERCASE(str) \
    int len = strlen(str);\
    for (int i = 0; i < len; i++)\
        str[i] = isupper(str[i]) ? tolower(str[i]) : str[i];

char* toLowerCase(char* s) {

    TO_LOWERCASE(s);
    return s;
}

