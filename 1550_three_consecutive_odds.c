/*
 * =====================================================================================
 *
 *       Filename:  1550_three_consecutive_odds.c
 *
 *    Description:  three consecutive odds
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

bool threeConsecutiveOdds(int* arr, int arrSize) {

    int count = 0;
    bool rc = false;

    for (int i = 0; i < arrSize; i++) {
        count = arr[i] & 0x1 ? count+1 : 0;

        if (count == 3) {
            rc = true;
            break;
        }
    }
    return rc;
}
