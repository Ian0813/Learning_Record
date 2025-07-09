/*
 * =====================================================================================
 *
 *       Filename:  762_prime_number_of_set_bits_in_binary_representation.c
 *
 *    Description:  prime number of set bits in binary representation
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
#include <limits.h>
#include <math.h>

typedef enum {false, true} bool;

static bool is_prime(int value) {

    bool rc = true;
    int boundary = ((int) log(value))+1;

    for (int i = 2; i <= boundary; i++) {
        if (!(value%i)) {
            rc = false;
            break;
        }
    }
    return rc;
}

static int calculate_exponent(int base, int exp)
{
    int result = 0;

    if (!exp) {
        return 1;
    } else if (exp == 1) {
        return base;
    } else if (exp) {
        result = calculate_exponent(base, exp-1) * base;
    }
    return result;
}

static int get_maxbits(int value)
{
    int pos = (CHAR_BIT * sizeof(int)) - 1;

    for (pos; pos >= 0; pos--) {
        if ((value >> pos) & 0x1) {
            break;
        }
    }
    return pos;
}

static int *get_primes(int max, int *length) {

    int *arr = NULL;

    arr = (int *) calloc(max, sizeof(int));

    for (int i = 2; i <= max; i++) {
        if (is_prime(i)) {
            arr[*length] = i;
            *length += 1;
        }
    }
    return arr;
}

static int get_bits(int value) {

    int count = 0;
    int pos = (CHAR_BIT * sizeof(int)) - 1;

    for (pos; pos >= 0; pos--) {
        if ((value >> pos) & 0x01) {
            count++;
        }
    }
    return count;
}

static int binary_search(int *arr, int head, int end, int target) {

    int middle = (head+end)/2;
    int rc = middle;

    if (head < end) {
        if (arr[middle] == target) {
            rc = middle;
        } else if (arr[middle] > target) {
            rc = binary_search(arr, head, middle, target);
        } else if (arr[middle] < target) {
            rc = binary_search(arr, middle+1, end, target);
        }
    }
    return rc;
}

static int count_prime_bits(int left, int right, int *primes, int length) {

    int index = 0, bits_number = 0, count = 0;

    for (int i = left; i <= right; i++) {

        bits_number = get_bits(i);
        index = binary_search(primes, 0, length, bits_number);

        if (index < length && primes[index] == bits_number) {
            count++;
        }
    }
    return count;
}

int countPrimeSetBits(int left, int right) {

    int max_value = 0, max_bits = 0, length = 0, track_count = 0;
    int *primes = NULL;

    max_value = calculate_exponent(10, 6);
    max_bits = get_maxbits(max_value);

    primes = get_primes(max_bits, &length);
    track_count = count_prime_bits(left, right, primes, length);

    return track_count;
}
