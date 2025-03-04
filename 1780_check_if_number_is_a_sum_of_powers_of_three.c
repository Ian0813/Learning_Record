/*
 * =====================================================================================
 *
 *       Filename:  1780_check_if_number_is_a_sum_of_powers_of_three.c
 *
 *    Description:  check if number is a sum of powers of three
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

#define MAX_EXPONENT 16
#define ARR_SIZE (MAX_EXPONENT+1)

typedef enum {
    false, true
} bool;

unsigned int power_of_three(int exp) {
    if (!exp) {
        return 1;
    }
    return power_of_three(exp-1)*3;
}

static void fill_power_array(int *arr, int size) {

    for (int i = 0; i < size; i++) {
        arr[i] = power_of_three(i);
    }
    return;
}

static bool check_is_sum(int n, int *powers, int index) {

    bool rc = false;

    if (index >= 0) {
        if (!(n-powers[index])) {
            return true;
        } else if (n < powers[index]) {
            rc = check_is_sum(n, powers, index-1);
        } else {
            rc = check_is_sum(n-powers[index], powers, index-1);
        }
    }
    return rc;
}

bool checkPowersOfThree(int n) {

    bool rc = false;
    int power_3_array[ARR_SIZE] = {0};
    int three_count[ARR_SIZE] = {0};

    fill_power_array(power_3_array, ARR_SIZE);

    rc = check_is_sum(n, power_3_array, ARR_SIZE-1);
    return rc;
}
