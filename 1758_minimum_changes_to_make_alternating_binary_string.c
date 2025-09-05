/*
 * =====================================================================================
 *
 *       Filename:  1758_minimum_changes_to_make_alternating_binary_string.c
 *
 *    Description:  minimum changes to make alternating binary string
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

typedef enum {
    ZERO_ONE = 0,
    ONE_ZERO = 1
} pattern_type;

static int calculate_on_pattern(char *s, pattern_type ptype) {

    int change = 0, is_odd = 0;
    size_t len = strlen(s);

    is_odd = (len%2) ? 1 : 0;
    len = is_odd ? len-1 : len;

    for (int i = 0; i < len; i += 2) {
        if (ptype == ZERO_ONE) {
            change = s[i] != '0' ? change+1 : change;
            change = s[i+1] != '1' ? change+1 : change;
        } else if (ptype == ONE_ZERO) {
            change = s[i] != '1' ? change+1 : change;
            change = s[i+1] != '0' ? change+1 : change;
        }
    }

    if (is_odd) {
        if (ptype == ZERO_ONE) {
            change = (s[len] == '0') ? change : change+1;
        } else if (ptype == ONE_ZERO) {
            change = (s[len] == '1') ? change : change+1;
        }
    }

    return change;
}

int minOperations(char* s) {

    int diff1 = 0, diff2 = 0, rc = 0;

    diff1 = calculate_on_pattern(s, ZERO_ONE);
    diff2 = calculate_on_pattern(s, ONE_ZERO);

    rc = diff1 < diff2 ? diff1 : diff2;

    return rc;
}
