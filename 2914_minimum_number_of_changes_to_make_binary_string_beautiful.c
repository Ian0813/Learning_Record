/*
 * =====================================================================================
 *
 *       Filename:  2914_minimum_number_of_changes_to_make_binary_string_beautiful.c
 *
 *    Description:  minimum number of changes to make binary string beautiful
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
#include <sys/param.h>

typedef enum {
    DIGIT_ZERO = 0,
    DIGIT_ONE = 1,
} digit_mark;

typedef struct {
    int one_count;
    int zero_count;
    int most_count;
    digit_mark most_flag;
} d_counter;

static void count_digit_from_str(char *str, int start, int end, d_counter *ptr) {

    if (!str || !ptr)
        return;

    for (int i = start; i < end; i++) {
        switch (str[i]) {
            case '1':
                ptr->one_count++;
            break;
            case '0':
                ptr->zero_count++;
            break;
            default:
                fprintf(stderr, "Unknown digit.\n");
            break;
        }
    }
    return;
}

int minChanges(char* s) {

    int slen = 0, changes_count = 0;

    if (s) {
        slen = strlen(s);

        for (int i = 0; i < slen; i += 2) {
            if (s[i] != s[i+1])
                changes_count++;
        }
    }
    return changes_count;
}
