/*
 * =====================================================================================
 *
 *       Filename:  2549_count_distinct_numbers_on_board.c
 *
 *    Description:  count distinct numbers on board
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

#define TABLE_SIZE 101

int _distinctIntegers(int n, int tag, int *table) {

    int count = 0;

    if (tag == 1)
        table[n] = tag;

    for (int i = 1; i < n; i++) {
        if ((n%i) == 1 && !table[i])
            table[i] = tag; 
    }

    for (int i = n; i; i--) {
        if (table[i] == tag)    
            count++; 
    }

    return count;
}

int distinctIntegers(int n) {

    int tag = 1, table[TABLE_SIZE] = {0};
    int count = 0;

    for (int i = n; i; i--) {
        count += _distinctIntegers(i, tag, table);
        tag++;
    }
    return count;
}
