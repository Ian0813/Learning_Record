/*
 * =====================================================================================
 *
 *       Filename:  2375_construct_smallest_number_from_di_string.c
 *
 *    Description:  construct smallest number from di string
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

#define MAXIMUM_ROW 1024
#define DIGIT_TO_CHAR(digit) ((digit) + '0')

enum {
    LETTER_I = 'I',
    LETTER_D = 'D'
};

static void swap(char *c1, char *c2) {

    char temp = *c1;

    *c1 = *c2;
    *c2 = temp;
    return;
}

static bool check_is_legal(char letter, char *nums, int pos) {

    bool rc = true; 

    switch (letter) {
        case LETTER_I:
            rc = (nums[pos] < nums[pos+1]) ? true : false;  
        break;
        case LETTER_D:
            rc = (nums[pos] > nums[pos+1]) ? true : false;
        break;
    }
    return rc;
}

static bool nums_confirmation(char *nums, char *pattern, int plen) {

    bool rc = true;

    for (int i = 0; i < plen; i++) {
        if (!check_is_legal(pattern[i], nums, i)) {
            rc = false;
            break;
        }
    }
    return rc;
}

static char *get_number_list(int boundary) {

    char *list = NULL; 

    list = (char *) malloc((boundary + 1) * sizeof(char));
    memset(list, 0, sizeof(char) * (boundary + 1));

    for (int i = 0; i < boundary; i++) {
        list[i] = DIGIT_TO_CHAR(i + 1);
    }
    return list;
}

static char **allocate_list(int row, int col) {

    char **list = NULL;

    list = (char **) calloc(row, sizeof(char *));

    if (list) {
        for (int i = 0; i < row; i++) {
            list[i] = (char *) calloc(col, sizeof(char)); 
        }
    }
    return list;
}

static void free_list(char **list, int row) {

    if (list) {
        for (int i = 0; i < row; i++) {
            free(list[i]);
        }
        free(list);
    }
    return;
}

static void shift_generator(char *nums, int index, int boundary, char **list, char *pattern, int plen, bool *is_find) {

    if (nums && list) {

        if (index == boundary) {
            if (nums_confirmation(nums, pattern, plen)) {
                *list = strdup(nums);
                *is_find = true;
            }
            return;
        }

        for (int i = index; i < boundary && !(*is_find); i++) {
            swap(&nums[i], &nums[index]);
            shift_generator(nums, index + 1, boundary, list, pattern, plen, is_find);
            swap(&nums[i], &nums[index]);
        }
    }
    return;
}    

char* smallestNumber(char* pattern) {

    char *number_list = NULL;
    int plen = 0, lindex = 0;
    char *result = NULL;
    bool is_find = false;

    if (pattern) {
        plen = strlen(pattern);
        number_list = get_number_list(plen + 1);
        shift_generator(number_list, 0, (plen+1), &result, pattern, plen, &is_find);
    }
    return result; 
}

