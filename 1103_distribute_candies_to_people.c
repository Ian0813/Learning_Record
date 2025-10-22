/*
 * =====================================================================================
 *
 *       Filename:  1103 distribute candies to people.c
 *
 *    Description:  distribute candies to people
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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

static void dispatch(int candies, int *arr, int len) {

    int value = 0;
    bool enough = 0; 

    while (candies) {
        for (int i = 0; i < len && candies; i++) {
            enough = candies >= (value+1) ? true : false;
            value = enough ? value+1 : candies; 
            candies = enough ? (candies-value) : 0; 
            arr[i] += value;
        }
    }

    return; 
}

int* distributeCandies(int candies, int num_people, int* returnSize) {

    int *result = NULL;

    result = (int *) calloc(num_people, sizeof(int));
    *returnSize = num_people;

    dispatch(candies, result, num_people);

    return result;
}
