/*
 * =====================================================================================
 *
 *       Filename:  443_string_compression.c
 *
 *    Description:  String compression  
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

#define DIGITS_NUM 5

struct string_handle {
    char cur;
    int cur_index;
    int windex;
    int rindex;
    int counter;
};

static void reverse(char *str) {

    char temp = '\0';

    for (int i = 0, j = strlen(str)-1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    return;
}

static char *inttostr(int num) {

    char *str = NULL;
    int part = 0;

    str = (char *) calloc(DIGITS_NUM, sizeof(char));

    while (num) {
        part = num%10; 
        num /= 10;
        sprintf(str+strlen(str), "%d", part);
    }
    reverse(str);
    return str;
}

int compress(char* chars, int charsSize) {

    struct string_handle handler = {.cur = chars[0], .counter = 1, .cur_index = 0, .windex = 1};
    char *numstr = NULL, hold_ch = '\0';

    for (int i = 1; i < charsSize; i++) {

        if (handler.cur_index == -1) {
            handler.cur_index = i;
        }

        if (chars[i] != handler.cur || i == charsSize-1) {

            if (i == charsSize-1 && chars[i] == handler.cur) {
                // To count the last character in the end of an array
                handler.counter++;
            }

            hold_ch = chars[i];
            handler.windex = handler.cur_index + 1;

            if (handler.counter > 1) {
                numstr = inttostr(handler.counter);
                for (int i = 0; i < strlen(numstr); i++) {
                    chars[handler.windex++] = numstr[i];
                }
                free(numstr);
                numstr = NULL;
            }

            if (handler.cur != hold_ch) {
                chars[handler.windex] = chars[i];
            }

            if (handler.cur != hold_ch && i == charsSize-1) {
                handler.windex++;
            }

            handler.cur = chars[i];
            handler.counter = 1;
            handler.cur_index = handler.windex; 
        } else {
            handler.counter++;
        }
    }
    return handler.windex;
}

int main(void) {

    char chars1[] = "aabbccc"; 
    char chars2[] = "aaabbaabbbccaaaAAACCC;;A";
    char chars3[] = "aa"; 
    int num = 0; 

    num = compress(chars1, strlen(chars1)/sizeof(*chars1));

    printf("num: %d\n", num);
    for (int i = 0; i < num; i++) {
        printf("%c ", chars1[i]);
    }
    putchar('\n');

    num = compress(chars2, strlen(chars2)/sizeof(*chars2));

    printf("num: %d\n", num);
    for (int i = 0; i < num; i++) {
        printf("%c ", chars2[i]);
    }
    putchar('\n');

    num = compress(chars3, strlen(chars3)/sizeof(*chars3));

    printf("num: %d\n", num);
    for (int i = 0; i < num; i++) {
        printf("%c ", chars3[i]);
    }
    putchar('\n');

    return EXIT_SUCCESS;
}
