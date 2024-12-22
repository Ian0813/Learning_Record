/*
 * =====================================================================================
 *
 *       Filename:  3396_minimum_number_of_operations_to_make_elements_in_array_distinct.c
 *
 *    Description:  minimum number of operations to make elements in array distinct
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

#define MAX_SIZE 101
#define UNIT_SIZE 3

static void fill_table(int *table, int *nums, int numsSize) {

    for (int i = 0; i < numsSize; i++) {
        table[nums[i]]++;
    }
    return;
}

static bool check_unique(int *table) {

    bool rc = true; 

    for (int i = 0; i < MAX_SIZE; i++) {
        if (table[i] > 1) {
            rc = false;
            break;
        }
    }
    return rc;
}

static void update_table(int *table, int *nums, int size) {

    for (int i = 0; i < size; i++) {
        table[nums[i]]--;
    }
    return;
}

int minimumOperations(int* nums, int numsSize) {

    int remove_offset = 0;
    int remain_size = numsSize;
    int count = 0, unit = UNIT_SIZE;
    int table[MAX_SIZE] = {0}; 
    int *ptr = nums;

    fill_table(table, nums, numsSize);

    while (remain_size > 0) {
        if (check_unique(table)) {
            break;
        }    
        unit = remain_size >= UNIT_SIZE ? UNIT_SIZE : remain_size;
        update_table(table, &ptr[remove_offset], unit);
        remove_offset += UNIT_SIZE;
        remain_size -= UNIT_SIZE;
        count++;
    }
    return count;
}
