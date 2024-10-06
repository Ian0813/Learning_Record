/*
 * =====================================================================================
 *
 *       Filename:  402_remove_k_digits.c
 *
 *    Description:  Remove k digits  
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
#include <ctype.h>

#ifdef BUFSIZ
#undef BUFSIZ 
#define BUFSIZ 100000
#endif

char get_minimum(char *buf, int *start, int *end, char mini_char) {

    char mini = CHAR_MAX;
    int mini_index = 0;

    for (*start; *start < *end; *start += 1) {
        if (buf[*start] < mini) {
            mini = buf[*start];
            mini_index = *start;
            if (mini == mini_char)
                break;
        }
    }
    *start = mini_index;
    buf[*start] = CHAR_MAX;
    return mini;
}

static void compress(char *buf, int *index) {

    int i = 0, tindex = 0;
    char temp[BUFSIZ] = {0};

    while (buf[i] == '0' && i < (*index-1))
        i++;

    for (i; i < *index; i++) {
        temp[tindex++] = buf[i];
    }

    memset(buf, 0, sizeof(char) * *index);
    memcpy(buf, temp, sizeof(char) * tindex);
    *index = tindex;
    return;
}

char* removeKdigits(char* num, int k) {

    char *result = NULL, mini = CHAR_MAX;
    int total = strlen(num) - k;
    int index = 0, start = 0, end = strlen(num)-(total-1);
    char check_mini = '0';

    if (k) {

        result = (char *) calloc(strlen(num), sizeof(char)); 

        if (strlen(num) == k) {
            memset(num, 0, sizeof(char)*strlen(num));
            num[0] = '0';
        } else if (strlen(num)-k == 1) {
            start = 0;
            end = strlen(num);
            mini = get_minimum(num, &start, &end, check_mini);
            memset(num, 0, sizeof(char)*strlen(num));
            num[0] = mini; 
        } else {
            while (index < total) {
                mini = get_minimum(num, &start, &end, check_mini);
                start++;
                end++;
                result[index++] = mini;
                if (isdigit(num[end-1]))
                    check_mini = mini > num[end-1] ? num[end-1] : mini;
            }
            memset(num, 0, strlen(num));
            compress(result, &index);
            memcpy(num, result, index*sizeof(char));
        }
    }
    free(result);
    return num;
}

int main(void) {

    char num[] = "1432219";

    removeKdigits(num, 3);
    printf("num: %s\n", num);

    return EXIT_SUCCESS;
}

