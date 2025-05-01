/*
 * =====================================================================================
 *
 *       Filename:  1295_find_numbers_with_even_number_of_digits.c
 *
 *    Description:  find numbers with even number of digits
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

static int get_digits_number(int value) {

    int number = 0;

    while (value) {
        number += 1;
        value /= 10;
    }
    return number;
}

int findNumbers(int* nums, int numsSize) {

    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        if (!(get_digits_number(nums[i])%2)) {
            count++;
        }
    }
    return count;
}

