/*
 * =====================================================================================
 *
 *       Filename:  2843_count_symmetric_integers.c
 *
 *    Description:  count symmetric integers
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

#define INT_TO_CH(value) ((value)+'0')
#define CH_TO_INT(ch) ((ch)-'0')
#define PAIR_SIZE 2

enum {
    FIRST = 0,
    SECOND = 1
};

static char *numeric_to_str(int value) {

    char str[BUFSIZ] = "0", ch = '\0';
    int len = 0;

    while (value) {
        str[len++] = INT_TO_CH(value%10);
        value /= 10;
    }

    for (int i = 0, j = strlen(str)-1; i < j; i++, j--) {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
    }

    return strdup(str);
}

static int get_sum(char *str, int len) {

    int sum = 0;

    for (int i = 0; i < len; i++) {
        sum += CH_TO_INT(str[i]);
    }
    return sum;
}

int countSymmetricIntegers(int low, int high) {

    int count = 0, len = 0, number_pair[PAIR_SIZE] = {0};
    char *ptr = NULL;

    for (int i = low; i <= high; i++) {

        ptr = numeric_to_str(i);

        len = strlen(ptr);

        if (!(len%2)) {
            number_pair[FIRST] = get_sum(ptr, len/2);
            number_pair[SECOND] = get_sum(&ptr[len/2], len/2);

            if (number_pair[FIRST] == number_pair[SECOND]) {
                count++;
            }
            memset(number_pair, 0, sizeof(number_pair));
        }
        free(ptr);
    }
    return count;
}
