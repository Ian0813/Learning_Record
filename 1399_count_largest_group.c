/*
 * =====================================================================================
 *
 *       Filename:  1399_count_largest_group.c
 *
 *    Description:  count largest group
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

#define MAX_SIZE (9+9+9+9+1)

static int get_digit_sum(int value) {

    int sum = 0;

    while (value) {
        sum += (value%10); 
        value /= 10;
    }
    return sum;
}

static int get_maximum(int *table) {

    int max = 0;

    for (int i = 0; i < MAX_SIZE; i++) {
        if (table[i] > max) {
            max = table[i]; 
        }
    }
    return max;
}

static int count_maximum(int *table, int max) {

    int count = 0;

    for (int i = 1; i < MAX_SIZE; i++) {
        count = table[i] == max ? count + 1 : count;
    }
    return count;
}

int countLargestGroup(int n) {

    int table[MAX_SIZE] = {0};
    int maximum = 0;

    for (int i = 0; i <= n; i++) {
        table[get_digit_sum(i)]++;
    }

    maximum = get_maximum(table);
    return count_maximum(table, maximum);
}
