/*
 * =====================================================================================
 *
 *       Filename:  3751_total_waviness_of_numbers_in_range_i.c
 *
 *    Description:  total waviness of numbers in range i
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

#define MAX_DIGIT_LEN 16
#define MINI_LEN 3

static char *digit_to_str(int val) {

    char *ptr = NULL, *temp = NULL;

    temp = ptr = (char *) calloc(MAX_DIGIT_LEN, sizeof(char));

    do {
        *temp = (val%10) + '0';
        temp++;
        val /= 10;
    } while (val);

    return ptr;
}


static char **get_num_array(int smaller, int bigger, int *arr_size) {

    char **array = NULL;
    int index = 0;

    array = (char **) calloc((bigger - smaller) + 1, sizeof(char *));

    for (int i = smaller; i <= bigger; i++) {
        array[*arr_size] = digit_to_str(i);
        *arr_size += 1;
    }

    return array;
}

static int get_wave_count(char *str, int size) {

    int count = 0;

    if (size < MINI_LEN) {
        return count;
    }

    for (int i = 1; i < (size-1); i++) {
        if (str[i] < str[i-1] && str[i] < str[i+1])
            count++;
        else if (str[i] > str[i-1] && str[i] > str[i+1])
            count++;
    }
    return count;
}    

int totalWaviness(int num1, int num2) {

    char **num_array = NULL;    
    int arr_size = 0, smaller = 0, bigger = 0, waviness = 0;

    smaller = num1 <= num2 ? num1 : num2;
    bigger = num1 == smaller ? num2 : num1;

    num_array = get_num_array(smaller, bigger, &arr_size);

    for (int i = 0; i < arr_size; i++) {
        waviness += get_wave_count(num_array[i], strlen(num_array[i]));
    }

    for (int i = 0; i < arr_size; i++) {
        free(num_array[i]);
    }
    free(num_array);

    return waviness;
}
