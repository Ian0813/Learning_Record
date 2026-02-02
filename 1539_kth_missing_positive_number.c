/*
 * =====================================================================================
 *
 *       Filename:  1539_kth_missing_positive_number.c
 *
 *    Description:  kth missing positive number
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

int findKthPositive(int* arr, int arrSize, int k) {

    int diff = 0, result = 0;

    diff = arr[0] - 1;

    if ((diff) >= k) {
        result = k; 
    } else {

        k -= diff;

        for (int i = 0; i < arrSize - 1; i++) {
            if ((diff = arr[i+1] - arr[i]) > 1) {
                if ((diff - 1) >= k) {
                    result = arr[i] + k;
                    k = 0;
                    break;
                } else {
                    k -= (diff - 1);
                }
            }
        }

        if (k)
            result = arr[arrSize-1] + k;
    }

    return result;
}
