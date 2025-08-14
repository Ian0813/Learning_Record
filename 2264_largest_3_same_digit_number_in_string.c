/*
 * =====================================================================================
 *
 *       Filename:  2264_largest_3_same_digit_number_in_string.c
 *
 *    Description:  2264 largest 3 same digit number in string
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

typedef enum {false, true} bool;

#define CONSECUTIVE 3
#define MAX_DIGIT '9'

static bool check_consecutive(char *num, char last) {

    if (last != -1 && last > *num) {
        return false;
    }

    return num[0] == num[1] ? num[0] == num[2] : false;
}

char* largestGoodInteger(char* num) {

    char *result = NULL, last = -1;
    size_t len = 0L;
    int index = -1;

    len = strlen(num);

    for (int i = 0; i <= (len-CONSECUTIVE); i++) {
        if (check_consecutive(num + i, last)) {
            index = i;
            last = num[i];

            if (last == MAX_DIGIT)
                break;
        }
    }

    if (index != -1) {
        result = strndup(num + index, CONSECUTIVE);
    } else {
        result = strdup("");
    }

    return result;
}
