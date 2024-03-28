/*
 * =====================================================================================
 *
 *       Filename:  1207_unique_number_of_occurrences.c
 *
 *    Description:  Unique number of occurrences  
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

typedef enum _bool {false, true} bool;

#define NUM_TABLE_LEN 1001

bool uniqueOccurrences(int* arr, int arrSize) {

    int pos[NUM_TABLE_LEN] = {0};
    int neg[NUM_TABLE_LEN] = {0};
    int occurrences[NUM_TABLE_LEN] = {0};
    bool rc = true;

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] < 0) {
            neg[-arr[i]]++;
        } else {
            pos[arr[i]]++;
        }
    }

    for (int i = 0; i < NUM_TABLE_LEN; i++) {
        if (pos[i])
            occurrences[pos[i]] += 1; 
        if (neg[i])
            occurrences[neg[i]] += 1; 
    }

    for (int i = 0; i < NUM_TABLE_LEN; i++) {
        if (occurrences[i] > 1) {
            rc = false;
            break;
        }
    }

    return rc;
}
