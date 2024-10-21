/*
 * =====================================================================================
 *
 *       Filename:  2429_minimize_xor.c
 *
 *    Description:  Minimize xor  
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

#define BIT_COUNT_OF(type) (sizeof(type)*8)

static int count_bits(int val) {

    int bit_amount = BIT_COUNT_OF(int);
    int amount = 0;

    for (int i = bit_amount-1; i >= 0; i--) {
        if ((val >> i) & 1) {
            amount++; 
        }
    }
    return amount;
}

static int remove_least_bits(int num1, int number) {

    int bit_amount = BIT_COUNT_OF(int);

    for (int i = 0; number; i++) {
        if ((num1) & (1 << i)) {
            num1 ^= (1 << i);
            number--;
        }
    }
    return num1;
}

static int append_least_bits(int num1, int number) {

    int bit_amount = BIT_COUNT_OF(int);

    for (int i = 0; number; i++) {
        if (!(num1 & (1 << i))) {
            num1 |= (1 << i);  
            number--;
        }
    }
    return num1;
}

static int calculate_minimum_val(int num1, int n1_bits, int n2_bits) {

    int difference = (n1_bits > n2_bits) ? n1_bits-n2_bits : n2_bits-n1_bits;  
    int result = 0;

    if (!difference) {
        result = num1;
    } else if (n1_bits > n2_bits) {
        result = remove_least_bits(num1, difference);    
    } else {
        result = append_least_bits(num1, difference);
    }
    return result;
}

int minimizeXor(int num1, int num2) {

    int n1_bits = 0, n2_bits = 0;
    int result = 0;

    n1_bits = count_bits(num1);
    n2_bits = count_bits(num2);

    result = calculate_minimum_val(num1, n1_bits, n2_bits);
    return result;
}

int main(void) {

    int result = 0;

    result = minimizeXor(1, 12);

    printf("result: %d\n", result);

    return EXIT_SUCCESS;
}
