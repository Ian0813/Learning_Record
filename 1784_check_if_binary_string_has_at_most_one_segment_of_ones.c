/*
 * =====================================================================================
 *
 *       Filename:  1784_check_if_binary_string_has_at_most_one_segment_of_ones.c
 *
 *    Description:  check if binary string has at most one segment of ones

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
#include <stdint.h>
#include <inttypes.h>

typedef enum {false, true} bool;

#define CHAR_TO_INT(ch) ((ch)-'0')

static int get_one_number(char *s) {

    int count = 0;

    for (int i = 0; i < strlen(s); i++) {
        if (CHAR_TO_INT(s[i]))
            count++;
    }
    return count;
}

bool checkOnesSegment(char* s) {

    bool rc = false;
    int8_t flag = 0, count = 0, one_number = 0;
    int *length_arr = NULL, index = 0;

    one_number = get_one_number(s);
    length_arr = (int *) calloc(strlen(s), sizeof(int)); 

    for (int i = 0; i < strlen(s); i++) {
        if (CHAR_TO_INT(s[i])) {
            count++;
        } else {
            length_arr[index++] = count;
            count = 0;    
        }
    }

    if (count) {
        length_arr[index++] = count;
    }

    for (int i = 0; i < index; i++) {
        if (length_arr[i] == one_number) {
            rc = true; 
            free(length_arr);
            break;
        }
    }
    return rc;
}

