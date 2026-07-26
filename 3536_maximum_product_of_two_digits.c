/*
 * =====================================================================================
 *
 *       Filename:  3536_maximum_product_of_two_digits.c
 *
 *    Description:  maximum product of two digits
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

#define DIGIT_LEN 10

int maxProduct(int n) {

    int digit_count[DIGIT_LEN] = {0};
    int v1 = -1, v2 = -1;

    do {
        digit_count[(n%10)]++;
        n /= 10;
    } while (n);

    for (int i = DIGIT_LEN-1; i >= 0; i--) {

        if (v1 == -1 && digit_count[i]) {
            v1 = i;
            digit_count[i]--;
        }

        if (v2 == -1 && digit_count[i]) {
            v2 = i;
            digit_count[i]--;
        }

        if (v1 != -1 && v2 != -1)
            break;
    }
    return (v1 * v2);
}
