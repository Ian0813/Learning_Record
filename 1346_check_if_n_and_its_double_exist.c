/*
 * =====================================================================================
 *
 *       Filename:  1346_check_if_n_and_its_double_exist.c
 *
 *    Description:  check if n and its double exist
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

static bool binary_search(int *arr, int head, int end, int target, int origin) {

    int middle = (head+end)/2;    
    bool rc = false;

    if (head < end) {
        if (arr[middle] == target && middle != origin) {
            rc = true;  
        } else if (arr[middle] > target) {
            rc = binary_search(arr, head, middle, target, origin);
        } else if (arr[middle] < target) {
            rc = binary_search(arr, middle+1, end, target, origin);
        }
    }
    return rc;
}

static void swap(int *v1, int *v2) {

    int temp = *v1;

    *v1 = *v2;
    *v2 = temp; 
    return;
}

static void quick_sort(int *arr, int head, int end) {

    int front = head, last = head, tail = end; 

    if (front < tail) {
        while (last < tail) {
            if (arr[head] > arr[tail]) {
                last++;
                swap(&arr[last], &arr[tail]);
                continue;
            }   
            tail--;
        }
        swap(&arr[last], &arr[head]);
        quick_sort(arr, head, last-1);
        quick_sort(arr, last+1, end);
    }
    return;
}

bool checkIfExist(int* arr, int arrSize) {

    bool rc = false; 

    quick_sort(arr, 0, arrSize-1);

    for (int i = 0; i < arrSize; i++) {
        if ((rc = binary_search(arr, 0, arrSize, arr[i]*2, i))) {
            break;      
        }
    }
    return rc;
}
