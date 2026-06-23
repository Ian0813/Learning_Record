/*
 * =====================================================================================
 *
 *       Filename:  3602_hexadecimal_and_hexatrigesimal_conversion.c
 *
 *    Description:  hexadecimal and hexatrigesimal conversion
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

#define TRANS_TO_BASE_DIGIT(ptr, temp) ((ptr) = (temp >= 10) ? ((temp-10) + 'A') : (temp + '0'))

typedef enum {
    BASE_HEXADECIMAL = 0,
    BASE_HEXATRIGESIMAL = 1,
} base_numeric_t;

static void reverse(char *p, int len) {

    char temp = '\0';

    for (int i = 0, j = len-1; i < j; i++, j--) {
        temp = p[i];
        p[i] = p[j];
        p[j] = temp;
    }
    return;
}

static char *convert_to_str(unsigned int value, base_numeric_t base) {

    unsigned int temp = 0, base_value = 0, pindex = 0;
    char *ptr = (char *) calloc(MAX_INPUT, sizeof(char));

    switch (base) {
        case BASE_HEXADECIMAL:
            base_value = 16U;
        break;
        case BASE_HEXATRIGESIMAL:
            base_value = 36U;
        break;
    }

    while (value) {
        temp = value % base_value;
        TRANS_TO_BASE_DIGIT(ptr[pindex], temp);
        pindex++;
        value /= base_value;
    }

    reverse(ptr, pindex);
    return ptr;
}

char* concatHex36(int n) {

    char *ptr1 = NULL, *ptr2 = NULL; 
    int p1_len = 0, p2_len = 0;

    ptr1 = convert_to_str(n * n, BASE_HEXADECIMAL);
    ptr2 = convert_to_str(n * n * n, BASE_HEXATRIGESIMAL);

    p1_len = strlen(ptr1);
    p2_len = strlen(ptr2);

    ptr1 = (char *) reallocarray(ptr1, p1_len + p2_len + 1, sizeof(char));
    strcat(ptr1, ptr2);
    free(ptr2);

    return ptr1;
}
