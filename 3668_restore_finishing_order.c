/*
 * =====================================================================================
 *
 *       Filename:  3668_restore_finishing_order.c
 *
 *    Description:  restore finishing order
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
#include <limits.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAXIMUM_ID 101

static void store_id(int *order, int orderSize, int *ids) {

    for (int i = 0; i < orderSize; i++) {
        ids[order[i]] = i;
    }

    return;
}

int* recoverOrder(int* order, int orderSize, int* friends, int friendsSize, int* returnSize) {

    int ids[MAXIMUM_ID] = {0};
    int *result = NULL, id = MAXIMUM_ID + 1, temp = MAXIMUM_ID + 1;

    result = (int *) calloc(friendsSize, sizeof(int)); 
    *returnSize = 0;

    store_id(order, orderSize, ids);

    while (*returnSize != friendsSize) {

        for (int i = 0; i < friendsSize; i++) {
            if (ids[friends[i]] < temp) {
                id = friends[i]; 
                temp = ids[friends[i]]; 
            }
        }

        ids[id] = INT_MAX;
        result[*returnSize] = id; 
        temp = MAXIMUM_ID + 1;
        *returnSize += 1;
    }

    return result;
}
