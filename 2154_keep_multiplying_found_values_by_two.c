/*
 * =====================================================================================
 *
 *       Filename:  2154_keep_multiplying_found_values_by_two.c
 *
 *    Description:  keep multiplying found values by two
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

#define TABLE_SIZE 2001

struct value_table {
    int table[TABLE_SIZE];
};

static void table_number_register(struct value_table *finder, int *num, int numsSize) {

    if (!finder)
        return;

    for (int i = 0; i < numsSize; i++) {
        finder->table[num[i]]++;    
    }

    return;
}

static int find_process(struct value_table *finder, int *nums, int numsSize, int original) {

    int last = 0;

    if (!finder)
        return 0;

    last = original;

    while (finder->table[last]) {

        finder->table[last]--;
        last *= 2;

        if (!finder->table[last]) {
            break;
        }
    }

    return last;
}

int findFinalValue(int* nums, int numsSize, int original) {

    struct value_table finder = {0};

    table_number_register(&finder, nums, numsSize);

    return find_process(&finder, nums, numsSize, original);
}
