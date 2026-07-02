/*
 * =====================================================================================
 *
 *       Filename:  1805_number_of_different_integers_in_a_string.c
 *
 *    Description:  number of different integers in a string
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
#include <ctype.h>
#include <limits.h>

typedef enum {false, true} bool;

#define MAX_BUFLEN 1024

static char **nums_init(int size) {

    char **ptr = NULL;

    if (!size)
        return ptr;

    ptr = calloc(size, sizeof(char *));

    for (int i = 0; i < size; i++)
        ptr[i] = calloc(MAX_BUFLEN, sizeof(char));

    return ptr;
}

static bool nums_append(char **nums, int *numsSize, char *digits) {

    int index = 0, dlen = 0, flag = 0;

    if (!nums) 
        return false;

    dlen = strlen(digits);

    for (int i = 0; i < dlen; i++) {
        if (digits[i] != '0') {
            index = i;
            flag = 1;
            break;
        }
    }

    if (!flag)
        digits[index+1] = '\0';

    nums[*numsSize] = strdup(&digits[index]);
    *numsSize += 1;

    return true;
}

static int nums_count_diff(char **nums, int numsSize) {

    int count_diff = 0, flag = 0;
    char *last = NULL;

    if (!nums || !numsSize) 
        return count_diff;

    for (int i = 0; i < numsSize; i++) {
        for (int j = i+1; j < numsSize; j++) {
            if (!strcmp(nums[i], nums[j])) {
                flag = 1;
                break;
            }    
        }
        if (!flag)
            count_diff++;
        flag = 0;
    }    
    return count_diff;
}

static void nums_free(char **nums, int numsSize) {

    if (numsSize) {
        free(nums[numsSize-1]);
        nums_free(nums, numsSize-1);
    } else {
        free(nums);
    }
    return;
}

int numDifferentIntegers(char* word) {

    int numsSize = 0, dlen = 0, len = 0, count_diff = 0, flag = 0;
    char digits[MAX_BUFLEN] = {0}, **nums_ptr = NULL;

    len = strlen(word);
    nums_ptr = nums_init(len);

    for (int i = 0; i < len; i++) {
        if (isdigit(word[i])) {
            digits[dlen++] = word[i];
            flag = 1;
        } else {
            if (flag) 
                nums_append(nums_ptr, &numsSize, digits);
            dlen = flag = 0;
            memset(digits, 0, sizeof(digits));
        }
    }

    if (flag) 
        nums_append(nums_ptr, &numsSize, digits);

    count_diff = nums_count_diff(nums_ptr, numsSize);
    nums_free(nums_ptr, numsSize);
    return count_diff;
}
