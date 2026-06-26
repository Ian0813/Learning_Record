/*
 * =====================================================================================
 *
 *       Filename:  3754_concatnate_non_zero_digits_and_multiply_by_sum_i.c
 *
 *    Description:  concatnate non zero digits and multiply by sum i
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
#include <stdint.h>

typedef enum {false, true} bool; 

#define MAX_DIGIT_LEN (sizeof(long long) * CHAR_BIT)
#define DIGIT_TO_CH(digit) ((digit)+'0')
#define CH_TO_DIGIT(ch) ((ch)-'0')

#define REVERSE_STR(str, len) do {\
    char temp = '\0';\
    for (int i = 0, j = len-1; i < j; i++, j--) {\
        temp = str[i];\
        str[i] = str[j];\
        str[j] = temp;\
    }\
} while (0);

typedef struct {
    long long accumulate;
    long long concat_val;
} value_data;

static bool value_data_parsing(int n, value_data *vdata) {

    int digit_len = 0;
    char *digit_str = NULL;

    if (!n) {
        fprintf(stderr, "[%s] Invalid integer (zero) : %d\n", __func__, n);
        return false;
    }

    if (!vdata) {
        fprintf(stderr, "[%s] Invalid argument.\n", __func__);
        return false;
    }

    digit_str = calloc(MAX_DIGIT_LEN, sizeof(char));

    while (n) {
        if ((n%10)) {
            vdata->accumulate += (n%10);
            digit_str[digit_len++] = DIGIT_TO_CH((n%10));
        }
        n /= 10;
    }

    REVERSE_STR(digit_str, digit_len);

    for (int i = 0; i < digit_len; i++) {
        vdata->concat_val *= 10LL;    
        vdata->concat_val += CH_TO_DIGIT(digit_str[i]);    
    }

    free(digit_str);
    digit_len = 0;
    return true;
}

long long sumAndMultiply(int n) {

    value_data vdata = {0LL};
    return value_data_parsing(n, &vdata) ? (vdata.concat_val * vdata.accumulate) : 0;
}
