/*
 * =====================================================================================
 *
 *       Filename:  1903_largest_odd_number_in_string.c
 *
 *    Description:  largest odd number in string
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

typedef enum {false, true} bool;

#define CHAR_TO_INT(ch) ((ch) - '0')
#define CHECK_IS_ODD(value) (isdigit((value)) ? (!(CHAR_TO_INT(value)%2) ? false : true) : false)

char* largestOddNumber(char* num) {

    int length = strlen(num), index = -1;
    char *result = NULL;

    if (length) {

        result = (char *) calloc(length + 1, sizeof(char));

        for (int i = length - 1; i >= 0; i--) {
            if (CHECK_IS_ODD(num[i])) {
                index = i;
                break;
            }        
        }    

        memcpy(result, num, (index+1) * sizeof(char));
    }
    return result;
}
