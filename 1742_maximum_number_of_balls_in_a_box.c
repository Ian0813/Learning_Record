/*
 * =====================================================================================
 *
 *       Filename:  1742_maximum_number_of_balls_in_a_box.c
 *
 *    Description:  Maximum number of balls in a box  
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

#define ARRAY_BOUNDARY 46

int convert_num(int val) {

    int sum = 0;

    while (val) {
        sum = sum + (val%10);        
        val /= 10;
    }

    return sum;
}

int countBalls(int lowLimit, int highLimit) {

    int len = (highLimit - lowLimit) + 1;
    int arr[ARRAY_BOUNDARY] = {0};
    int max = 0;

    for (int i = lowLimit; i <= highLimit; i++) {
        arr[convert_num(i)]++;
    }

    for (int i = 0; i < ARRAY_BOUNDARY; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
