/*
 * =====================================================================================
 *
 *       Filename:  2165_smallest_value_of_the_rearranged_number.c
 *
 *    Description:  smallest value of the rearranged number
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

#define LONG_BIT 32

#define DIGIT_NUMBER 10
#define INT_TO_CH(val) ((val)+'0') 
#define CH_TO_INT(ch) ((ch)-'0') 

typedef enum {
    POSITIVE = 0,
    NEGATIVE = 1,
} sign_indicator;

struct count_info {
    int table[DIGIT_NUMBER];
    int amount;
};

struct result_info {
    long long value;
    char str[LONG_BIT]; 
    int len;
};

static void count_digits(struct count_info *counter, long long num) {

    while (num) {
        counter->table[num%10]++;
        num /= 10;
        counter->amount++;
    }
    return;
}    

static void reform_num(struct count_info *counter, sign_indicator flag, struct result_info *result) {

    int index = flag == POSITIVE ? 0 : 9, i = 0;

    if (counter->amount > result->len) {
        index = (flag == POSITIVE && !(result->len)) ? index + 1 : index;

        if (flag == POSITIVE) {
            for (i = index; i < DIGIT_NUMBER; i++) {
                if (counter->table[i]) {
                    break;
                }
            }
        } else if (flag == NEGATIVE) {
            for (i = index; i >= 0; i--) {
                if (counter->table[i]) 
                    break;
            }
        }

        counter->table[i]--;
        result->str[result->len] = INT_TO_CH(i);
        result->len += 1;

        reform_num(counter, flag, result);
    }
    return;
}

static long long convert_to_longlong(const char *str) {

    long long value = 0LL;

    for (int i = 0; i < strlen(str); i++) {
        value *= 10;        
        value += ((long long) CH_TO_INT(str[i])); 
    }
    return value;
}

long long smallestNumber(long long num) {

    sign_indicator flag = POSITIVE;
    struct count_info counter = {0};
    struct result_info result = {0};

    flag = num < 0 ? NEGATIVE : POSITIVE;
    num = flag == POSITIVE ? num : -num;

    count_digits(&counter, num);
    reform_num(&counter, flag, &result);

    printf("result: %s\n", result.str);

    if (strlen(result.str)) {
        result.value = convert_to_longlong(result.str);
        result.value = flag == POSITIVE ? result.value : result.value*-1LL;
        printf("value: %lld\n", result.value);
    }
    return result.value;    
}
