/*
 * =====================================================================================
 *
 *       Filename:  2937_make_three_strings_equal.c
 *
 *    Description:  make three strings equal
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

typedef enum {false, true} bool;

enum {
    STR1_INDEX = 0,
    STR2_INDEX = 1,
    STR3_INDEX = 2,
    STR_NUMBER
};

static void setlen_by_index(int *lens, char *s1, int index) {
    if (s1)
        lens[index] = strlen(s1);    
    else
        lens[index] = 0;
    return;
}

static bool check_range(int *lens, int index) {

    bool rc = true;

    for (int i = 0; i < STR_NUMBER; i++) {
        if (index >= lens[i]) {
            rc = false;
            break;
        }
    }
    return rc;
}    

int findMinimumOperations(char* s1, char* s2, char* s3) {

    int lens[STR_NUMBER] = {0};
    int count = 0, result = 0;
    bool flag = false; 

    setlen_by_index(lens, s1, STR1_INDEX);
    setlen_by_index(lens, s2, STR2_INDEX);
    setlen_by_index(lens, s3, STR3_INDEX);

    for (int i = 0; check_range(lens, i); i++) {
        if (s1[i] == s2[i] && s1[i] == s3[i]) {
            count++;
            flag = true;
            continue;
        }
        break;
    }

    for (int i = 0; flag && i < STR_NUMBER; i++) {
        if (lens[i] > count)
            result += (lens[i] - count);
    }

    return !result ? !flag ? -1 : result : result;
}
