/*
 * =====================================================================================
 *
 *       Filename:  2443_sum_of_number_and_its_reverse.c
 *
 *    Description:  sum of number and its reverse
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04.3) 11.4.0
 *
 *         Author:  Ian
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef enum {false, true} bool;

static int get_reverse(int value) {

    int temp = 0;     

    while (value) {
        temp *= 10;
        temp += (value%10);
        value /= 10;
    }

    return temp;
}

bool sumOfNumberAndReverse(int num) {

    int forward = 0, backward = 0;

    if (!num)
        return true;

    backward = forward = num/2;
    backward = (num%2) ? (backward+1) : backward; 

    for (forward, backward; forward > 0 && backward < num; forward--, backward++) {
        if (forward == get_reverse(backward)) {
            return true;
        }
    }
    return false;
}
