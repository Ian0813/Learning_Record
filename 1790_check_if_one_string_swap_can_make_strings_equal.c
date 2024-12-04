/*
 * =====================================================================================
 *
 *       Filename:  1790_check_if_one_string_swap_can_make_strings_equal.c
 *
 *    Description:  check if one string swap can make strings equal
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

static int count_diff(char *s1, char *s2) {

    int count = 0;

    for (int i = 0; i < strlen(s1); i++) {
        if (s1[i] != s2[i])
            count++;
        if (count > 2) {
            break; 
        }
    }
    return count;
}

static void get_diff(char *s1, char *s2, int *diff_indices) {

    for (int i = 0; i < strlen(s1); i++) {
        if (s1[i] != s2[i]) {
            *diff_indices = i;
            diff_indices++;
        }
    }
    return;
}

static void swap(char *s1, int *diff_indices) {

    char ch = s1[diff_indices[0]];

    s1[diff_indices[0]] = s1[diff_indices[1]];
    s1[diff_indices[1]] = ch;

    return;
}

bool areAlmostEqual(char* s1, char* s2) {

    bool rc = true;
    int count = 0;
    int *diff_indices = NULL;

    count = count_diff(s1, s2);
    rc = count == 2 ? true : count == 0 ? true : false; 

    if (count && rc) {
        diff_indices = (int *) calloc(count, sizeof(int));
        get_diff(s1, s2, diff_indices);
        swap(s1, diff_indices);
        if (strcmp(s1, s2)) {
            rc = false;
        }
        free(diff_indices);
    }
    return rc;
}
