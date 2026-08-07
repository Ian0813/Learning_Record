/*
 * =====================================================================================
 *
 *       Filename:  3731_find_missing_elements.c
 *
 *    Description:  find missing elements
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
#include <stdbool.h>
#include <limits.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define BITSET_BYTE_NUM (16)
#define BITSET_LEN (CHAR_BIT * BITSET_BYTE_NUM)
#define MAX_SIZE 101

typedef struct {
    char *bits;
    int bits_len;
    int bytes_num;
    int start;
    int end;
} bits_table;

static bits_table *bits_table_alloc(int nbytes) {

    bits_table *t = NULL;

    t = calloc(1, sizeof(*t));

    if (t) {
        t->bits = calloc(nbytes, sizeof(char));
        t->bits_len = nbytes * CHAR_BIT;
        t->bytes_num = nbytes;
        t->end = INT_MIN; 
        t->start = INT_MAX; 
    }
    return t;
}

static void bits_table_delete(bits_table *t) {

    if (!t)
        return;    
    free(t->bits);
    free(t);
    return;
}

static bool bits_setbit(bits_table *t, int nth) {

    int shift = 0, pos = 0;

    if (!t || nth > t->bits_len)
        return false;

    shift = nth >= CHAR_BIT ? (nth/CHAR_BIT) : 0; 
    pos = nth % CHAR_BIT;
    t->bits[shift] = (t->bits[shift] | (1 << pos)); 
    t->start = nth < t->start ? nth : t->start;
    t->end = nth > t->end ? nth : t->end;

    return true;
}

static bool bits_check(bits_table *t, int nth) {

    int shift = 0, pos = 0;

    if (!t || nth > t->bits_len)
        return false;

    shift = nth >= CHAR_BIT ? (nth/CHAR_BIT) : 0;
    pos = nth % CHAR_BIT; 

    return (t->bits[shift] & (1 << pos)) ? true : false;
}

int* findMissingElements(int* nums, int numsSize, int* returnSize) {

    int *result = NULL, rsize = 0;
    bits_table *t = NULL; 

    result = calloc(MAX_SIZE, sizeof(int));
    t = bits_table_alloc(BITSET_BYTE_NUM);
    
    for (int i = 0; i < numsSize; i++) {
        bits_setbit(t, nums[i]);
    }

    for (int i = t->start; i <= t->end; i++) {
        if (!bits_check(t, i)) {
            result[rsize++] = i;
        }
    }

    bits_table_delete(t);

    *returnSize = rsize;
    return result;
}
