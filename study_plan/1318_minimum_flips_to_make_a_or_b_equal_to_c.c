/*
 * =====================================================================================
 *
 *       Filename:  1318_minimum_flips_to_make_a_or_b_equal_to_c.c
 *
 *    Description:  Minumum flips to make a or b equal to c  
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

#define INT_BITNUMS 32 // The number of bits of an integer.

void get_bits(int num, char *arr) {

    for (int i = 0; i < INT_BITNUMS; i++) {
        arr[i] = (num >> i) & 0x1;
    }
    return;
}

int minFlips(int a, int b, int c){

    char *arr_a = NULL, *arr_b = NULL;
    char *arr_aORb = NULL, *arr_c = NULL;
    int aORb = (a | b); 
    int count = 0;

    arr_a = (char *) calloc(INT_BITNUMS, sizeof(char));
    arr_b = (char *) calloc(INT_BITNUMS, sizeof(char));
    arr_c = (char *) calloc(INT_BITNUMS, sizeof(char));
    arr_aORb = (char *) calloc(INT_BITNUMS, sizeof(char));

    get_bits(a, arr_a);
    get_bits(b, arr_b);
    get_bits(c, arr_c);
    get_bits(aORb, arr_aORb);

    for (int i = 0; i < INT_BITNUMS; i++) {

        if (!arr_aORb[i] && arr_c[i]) {
            count++;
        } else if (arr_aORb[i] && !arr_c[i]) {
            if (arr_a[i] && arr_b[i]) {
                count += 2;
            } else {
                count++;
            }
        }
    }

    free(arr_a);
    free(arr_b);
    free(arr_c);
    free(arr_aORb);

    return count;
}

int main(void) {

    int count = 0;

    count = minFlips(4, 2, 7);
    printf("count: %d\n", count);

    count = minFlips(1, 2, 3);
    printf("count: %d\n", count);

    return EXIT_SUCCESS;
}

