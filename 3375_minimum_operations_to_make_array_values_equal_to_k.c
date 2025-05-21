/*
 * =====================================================================================
 *
 *       Filename:  3375_minimum_operations_to_make_array_values_equal_to_k.c
 *
 *    Description:  minimum operations to make array values equal to k
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

#define TABLE_SIZE 101

typedef enum {
   NO_OPERATION = 0,
   DO_OPERATION = 1
} operation_type;

static void fill_table(int *nums, int numsSize, int *table) {

    for (int i = 0; i < numsSize; i++) {
        table[nums[i]]++;
    }
    return;
}

static int get_operations(int *nums, int numsSize, int *table, int k) {

    int count = 0;
    operation_type flag = NO_OPERATION; 

    for (int i = 0; i < numsSize; i++) {
        if (table[nums[i]] && nums[i] >= k) {
            count = nums[i] > k ? count+1 : count;
            flag = DO_OPERATION;
            table[nums[i]] = 0;
        } else if (nums[i] < k) {
            flag = NO_OPERATION;
            break;
        }
    }

    if (!flag)
        count = -1;
    return count;
}

int minOperations(int* nums, int numsSize, int k) {

    int table[TABLE_SIZE] = {0}, rc = 0;

    fill_table(nums, numsSize, table);
    rc = get_operations(nums, numsSize, table, k);

    return rc;
}
