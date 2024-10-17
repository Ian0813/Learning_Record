/*
 * =====================================================================================
 *
 *       Filename:  2997_minimum_number_of_operations_to_make_array_xor_equal_to_k.c
 *
 *    Description:  minimum number of operations to make array xor equal to k
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

#define MAX_BITS_AMOUNT(type) (sizeof(type)*8) 

static void array_xor(int *nums, int numsSize, int k) {

    for (int i = 0; i < numsSize; i++) {
        nums[i] = nums[i] ^ k;
    }
    return;
}

static int get_xor_arr(int *nums, int numsSize) {

    int result = 0;

    if (numsSize) {
        for (int i = 0; i < numsSize; i++) {
            result ^= nums[i];
        }    
    }
    return result;
}

static int count_bit_difference(int arr_xor, int k) {

    int counter = 0;

    for (int i = 0; i < MAX_BITS_AMOUNT(int); i++) {
        if (((arr_xor>>i)&0x01) ^ ((k>>i)&0x01)) {
            counter++;
        }
    }
    return counter;
}    

static void print_bits(int num) {

    for (int i = (MAX_BITS_AMOUNT(int))-1; i >= 0; i--) {
        printf("%hhx ", (num >> i) & 0x01);
    }
    putchar('\n');
    return;
}

int minOperations(int* nums, int numsSize, int k) {

    int arr_xor = 0;
    int min_operations = 0;

    if (numsSize) {
        arr_xor = get_xor_arr(nums, numsSize);
        min_operations = count_bit_difference(arr_xor, k);
    }
    return min_operations;
}

int main(void) {

    int arr[] = {16,2,20,13,15,20,13};
    
    printf("min operations: %d\n", minOperations(arr, sizeof(arr)/sizeof(*arr), 16));

    return EXIT_SUCCESS;
}
