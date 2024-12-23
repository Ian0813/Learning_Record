/*
 * =====================================================================================
 *
 *       Filename:  1769_minimum_number_of_operations_to_move_all_balls_to_each_box.c
 *
 *    Description:  minimum number of operations to move all balls to each box
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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAX_LENGTH 2000

enum { ZERO = '0', ONE = '1'};

static void mark_one_location(int *one_indices, int *index, char *boxes) {

    for (int i = 0; i < strlen(boxes); i++) {
        if (boxes[i] == ONE) {
            one_indices[*index] = i;
            *index += 1;
        }
    }    
    return;
}

static int get_movement(int val, int *one_indices, int one_index) {

    int sum = 0;

    for (int i = 0; i < one_index; i++) {
        sum += abs(val-one_indices[i]);
    }
    return sum;
}

int* minOperations(char* boxes, int* returnSize) {

    int one_indices[MAX_LENGTH] = {0}; 
    int *result = NULL;
    int size = 0, one_index = 0;

    if (strlen(boxes)) {

        result = (int *) calloc(strlen(boxes), sizeof(int));              
        mark_one_location(one_indices, &one_index, boxes);

        for (int i = 0; i < strlen(boxes); i++) {
            result[i] = get_movement(i, one_indices, one_index);            
            size++;
        }
    }

    *returnSize = size;

    for (int i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }
    putchar('\n');

    return result;
}

