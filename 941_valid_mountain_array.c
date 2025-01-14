/*
 * =====================================================================================
 *
 *       Filename:  941_valid_mountain_array.c
 *
 *    Description:  valid mountain array
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

#define MIN_BOUNDARY 3

int find_maxindex(int *arr, int arrSize) {

    int i = 0;
    int max = 0, mindex = 0;

    for (i; i < arrSize; i++) {
        if (arr[i] > max) {
            max = arr[i];    
            mindex = i;
        }

        if (i > mindex && arr[i] < max) {
            break; 
        }
    }
    return mindex;
}

bool validate_mountain(int *arr, int mindex, int arrSize) {

    bool rc = true;

    for (int i = 0; i < mindex; i++) {
        if (arr[i] >= arr[i+1]) {
            return (rc = false);
        }
    }

    for (int i = arrSize-1; i > mindex; i--) {
        if (arr[i] >= arr[i-1]) {
            rc = false; 
            break;
        }    
    }
    return rc;
}

bool validMountainArray(int* arr, int arrSize){

    bool rc = true;
    int mindex = 0;

    if (arrSize < MIN_BOUNDARY) {
        rc = false;     
    } else {
        mindex = find_maxindex(arr, arrSize);
        if (!mindex || mindex == arrSize-1) {
            rc = false;
        } else
            rc = validate_mountain(arr, mindex, arrSize);
    }
    return rc;
}
