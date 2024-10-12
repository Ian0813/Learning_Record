/*
 * =====================================================================================
 *
 *       Filename:  3079_find_the_sum_of_encrypted_integers.c
 *
 *    Description:  find the sum of encrypted integers
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

#define BASE_TEN (10U) 

static void decrypt(int cipher, int *ret) {

    int base = 0;
    int max_digit = INT_MIN;
    int remainder = 0;
    int addition = 1;

    while (cipher) {
        remainder = cipher%BASE_TEN;
        base += addition; 
        addition *= BASE_TEN;
        cipher /= BASE_TEN;
        if (remainder > max_digit)
            max_digit = remainder;
    }
    *ret = (base * max_digit);
    return;
}

int sumOfEncryptedInt(int* nums, int numsSize) {

    int *decrypt_list = NULL;
    int result = 0;

    if (numsSize) {

        decrypt_list = (int *) calloc(numsSize, sizeof(int)); 

        for (int i = 0; i < numsSize; i++) {
            decrypt(nums[i], &decrypt_list[i]);
        }

        for (int i = 0; i < numsSize; i++) {
            result += decrypt_list[i];
        }
        free(decrypt_list);
    }
    return result;
}
