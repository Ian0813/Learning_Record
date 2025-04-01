/*
 * =====================================================================================
 *
 *       Filename:  2780_minimum_index_of_a_valid_split.c
 *
 *    Description:  minimum index of a valid split
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

#define TABLE_SIZE 1000000001
#define RECORD_ROW_SIZE 2

typedef enum {
    INCREASE = 0,
    DECREASE = 1
} record_type_t;

static void frequency_count(int *nums, int numsSize, int *table) {
    for (int i = 0; i < numsSize; i++) {
        table[nums[i]]++;
    }
    return;
}

static int get_dominant(int *nums, int numsSize, int *table) {

    int max = 0, dominat = 0;

    for (int i = 0; i < numsSize; i++) {
        if (table[nums[i]] > max) {
            max = table[nums[i]];
            dominat = nums[i];
        }
    }
    return dominat;
}

static bool is_dominant_array(int length, int amount) {

    bool rc = false;

    length -= amount;

    if (length < amount) {
        rc = true;
    }
    return rc;
}

static int mini_index_by_split(int *nums, int numsSize, int dominant, int **records) {

    int mini_index = -1;
    bool rc = false;

    for (int i = 0; i < (numsSize-1); i++) {

        rc = is_dominant_array(i+1, records[INCREASE][i]);

        if (i+1 <= (numsSize-1))
            rc = rc == true ? is_dominant_array(((numsSize-1)-(i+1))+1, records[DECREASE][i+1]): rc;

        if (rc) {
            mini_index = i;
            break;
        }
    }
    return mini_index;
}

static void occurrences_record(int **records, int dominant, int amount, int *nums, int numsSize) {

    int _amount = amount;

    for (int i = 0; i < numsSize; i++) {
        records[DECREASE][i] = _amount;
        if (nums[i] == dominant)
            _amount--;
    }

    _amount = amount;

    for (int i = numsSize-1; i >= 0; i--) {
        records[INCREASE][i] = _amount;
        if (nums[i] == dominant)
            _amount--;
    }
    return;
}

static void free_records(int **records) {

    free(records[INCREASE]);
    free(records[DECREASE]);
    free(records);

    return;
}

int minimumIndex(int* nums, int numsSize) {

    int *table = (int *) calloc(TABLE_SIZE, sizeof(int));
    int **records = (int **) calloc(RECORD_ROW_SIZE, sizeof(int*));
    int dominant = 0, min_index = 0;

    records[INCREASE] = (int *) calloc(numsSize, sizeof(int));
    records[DECREASE] = (int *) calloc(numsSize, sizeof(int));

    frequency_count(nums, numsSize, table);
    dominant = get_dominant(nums, numsSize, table);
    occurrences_record(records, dominant, table[dominant], nums, numsSize);
    min_index = mini_index_by_split(nums, numsSize, dominant, records);

    free(table);
    free_records(records);

    return min_index;
}
