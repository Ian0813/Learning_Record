/*
 * =====================================================================================
 *
 *       Filename:  670 maximum swap.c
 *
 *    Description:  maximum swap
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
#include <limits.h>

#define DIGIT_LEN 10
#define MAX_DIGIT_LEN 16
#define INT_TO_CH(val) ((val)+'0')
#define CH_TO_VAL(ch) ((ch)-'0')

static void reverse(char *ptr, int len) {

    char ch = '\0';

    for (int i = 0, j = len-1; i < j; i++, j--) {
        ch = ptr[i];
        ptr[i] = ptr[j];
        ptr[j] = ch;
    }
    return;
}

static char *get_digit_array(int num, int *dlen) {

    char *ptr = NULL, *temp = NULL;

    temp = ptr = (char *) calloc(MAX_DIGIT_LEN, sizeof(char));

    if (!ptr)
        return ptr;

    do {
        *temp = INT_TO_CH((num%10));
        num /= 10;
        temp++;
        *dlen += 1;
    } while (num);

    reverse(ptr, *dlen);

    return ptr;
}

static int get_value_from_array(char *arr, int len) {

    int value = 0;

    for (int i = 0; i < len; i++) {
        value *= 10;
        value += CH_TO_VAL(arr[i]);
    }
    return value;
}

static int get_start_index(char *digit_array, int dlen) {

    int index = 0;

    for (int i = dlen-1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (digit_array[i] > digit_array[j]) {
                index = i;                 
                break;
            }
        }
    }
    return index;
}

int maximumSwap(int num) {

    int start_index = 0;
    char *digit_array = NULL, temp = '\0';
    int dlen = 0, *accumlator = NULL, max_index = 0, max_value = INT_MIN;

    digit_array = get_digit_array(num, &dlen);
    accumlator = (int *) calloc(dlen, sizeof(int));

    for (int i = dlen-1; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            if (digit_array[i] > digit_array[j]) {
                accumlator[i] += CH_TO_VAL(digit_array[j]);
            } else if (digit_array[i] < digit_array[j]) {
                accumlator[j] += CH_TO_VAL(digit_array[i]);
            }
        }
    }

    start_index = get_start_index(digit_array, dlen);

    for (int i = start_index; i < dlen; i++) {
        if (max_value < accumlator[i]) {
            max_value = accumlator[i];
            max_index = i;
        } else if (max_value == accumlator[i]) {
            if (digit_array[max_index] <= digit_array[i]) {
                max_index = i;
            }
        }
    }

    if (max_index != -1) {
        for (int i = 0; i < max_index; i++) {
            if (digit_array[i] < digit_array[max_index]) {
                temp = digit_array[max_index];
                digit_array[max_index] = digit_array[i];
                digit_array[i] = temp;
                break;
            }
        }
    }

    max_value = get_value_from_array(digit_array, dlen);
    free(digit_array);
    free(accumlator);

    return max_value;
}
