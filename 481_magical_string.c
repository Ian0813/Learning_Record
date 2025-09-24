/*
 * =====================================================================================
 *
 *       Filename:  481 magical string.c
 *
 *    Description:  magical string
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04.2) 11.4.0
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

#define INIT_LEN BUFSIZ
#define TARGET_LEN 2
#define CH_TO_INT(ch) ((isdigit(ch) ? ((ch)-'0') : ch))

typedef struct magic_str {
    char *str;
    int index;
    int steps;
    int length;
    int cur_len;
} magic_string;

static magic_string *magic_str_init(int length) {

    magic_string *s = NULL; 

    s = (magic_string *) malloc(sizeof(magic_string));  

    s->str = (char *) calloc(length, sizeof(char));
    s->steps = 3;
    s->index = 2;
    s->cur_len = 3;
    s->length = length;
    strcpy(s->str, "122");

    return s;
}

static void magic_str_cond_generate(magic_string *s, int least_len) {

    int number = 0, len = 0, tindex = 0;
    char target = '1', target_arr[TARGET_LEN] = "12";

    while (s->cur_len < least_len) {

        number = CH_TO_INT(s->str[s->index]);
        s->cur_len += number;

        if (s->cur_len >= s->length) {
            s->str = reallocarray(s->str, s->length * 2, sizeof(char));
            s->length = s->length * 2;
        }

        while (number) {
            s->str[s->steps++] = target;
            number--;
        }

        s->index++;
        tindex = (tindex+1) % TARGET_LEN;
        target = target_arr[tindex];
    }

    return;
}

static void magic_str_free(magic_string *s) {

    if (s) {
        free(s->str);
        free(s);
    }
    return;
}

static int get_onecount(magic_string *s, int least_len) {

    int count = 0;

    if (!s)
        return count;

    for (int i = 0; i < least_len; i++) {
        count = s->str[i] == '1' ? (count + 1) : count;
    }

    return count;
}

int magicalString(int n) {

    int count = 0;
    magic_string *s = NULL;

    s = magic_str_init(INIT_LEN);
    magic_str_cond_generate(s, n);

    count = get_onecount(s, n); 
    magic_str_free(s);

    return count;
}
