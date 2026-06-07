/*
 * =====================================================================================
 *
 *       Filename:  3179_find_the_n_th_value_after_k_seconds.c
 *
 *    Description:  find the n th value after k seconds
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

#define MAXIMUM_VALUE 1000000007ULL

int valueAfterKSeconds(int n, int k) {

    unsigned long long *array = NULL, *temp = NULL, loop = k; 
    int value = 0;

    array = (unsigned long long *) calloc(n, sizeof(unsigned long long));
    temp = (unsigned long long *) calloc(n, sizeof(unsigned long long));

    for (int i = 0; i < n; i++) {
        temp[i] = array[i] = 1LL;
    }

    while (loop) {
        for (int i = 0; i < n; i++) {
            if (!i) {
                array[i] = temp[i];       
            } else {
                array[i] = temp[i] + array[i-1];
            }

            if (array[i] >= MAXIMUM_VALUE)
                array[i] %= MAXIMUM_VALUE;
        }
        memcpy(temp, array, sizeof(unsigned long long) * n);
        loop--;
    }

    value = array[n-1];
    free(temp);
    free(array);

    return value;
}
