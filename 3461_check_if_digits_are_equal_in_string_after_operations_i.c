/*
 * =====================================================================================
 *
 *       Filename:  3461_check_if_digits_are_equal_in_string_after_operations_i.c
 *
 *    Description:  check if digits are equal in string after operations i
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

#define MODULO 10
#define CH_TO_VAL(ch) ((ch)-'0')
#define VAL_TO_CH(val) ((val)+'0')

static char digit_sum_modulo(char d1, char d2) {

    int val = 0; 

    if (!isdigit(d1) || !isdigit(d2)) {
        return (char) -1;
    }

    val = (CH_TO_VAL(d1) + CH_TO_VAL(d2)) % MODULO;
    return VAL_TO_CH(val);
}

bool hasSameDigits(char* s) {

    char *dup = NULL, digit = -1;
    int len = strlen(s), dlen = 0;
    bool rc = false;

    dup = (char *) calloc(len, sizeof(char));

    memcpy(dup, s, len);

    while (len > 2) {
        for (int i = 0; i < len-1; i++) {
            digit = digit_sum_modulo(dup[i], dup[i+1]);
            if (digit != (char) -1)
                dup[dlen++] = digit;  
        }
        len = dlen;
        dlen = 0;
    }

    rc = dup[0] == dup[1] ? true : false;
    free(dup);

    return rc;
}
