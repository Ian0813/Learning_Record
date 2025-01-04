/*
 * =====================================================================================
 *
 *       Filename:  2269_find_the_k_beauty_of_a_number.c
 *
 *    Description:  find the k beauty of a number
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

#define INT_TO_CH(num) ((num)+'0')
#define CH_TO_INT(ch) ((ch)-'0')

#define REVERSE(str, size) { char temp; for (int i = 0, j = size-1; i < j; i++, j--) { temp = str[i]; str[i] = str[j]; str[j] = temp; } }

static char *num_to_str(int num) {

    char *str = NULL;
    int index = 0;

    str = (char *) calloc(BUFSIZ, sizeof(char));

    while (num) {
        str[index++] = INT_TO_CH(num%10); 
        num /= 10;
    }

    REVERSE(str, index);
    str[index] = '\0';

    return str;
}

static int str_to_int(char *str) {

    int num = 0;    
    const int base = 10;

    for (int i = 0; i < strlen(str); i++) {
        num *= base;
        num += CH_TO_INT(str[i]);    
    }
    return num;
}

int divisorSubstrings(int num, int k) {

    char *str = NULL, substr[BUFSIZ] = {0};
    int count = 0, divisor = 0;

    str = num_to_str(num);

    for (int i = 0; i <= strlen(str)-k; i++) {

        memcpy(substr, &str[i], sizeof(char)*k);
        divisor = str_to_int(substr);

        if (divisor && !(num%divisor))
            count++;
        memset(substr, 0, sizeof(char) * k);
    }
    return count;
}
