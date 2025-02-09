/*
 * =====================================================================================
 *
 *       Filename:  3304_find_the_k_th_character_in_string_game_i.c
 *
 *    Description:  find the k th character in string game i
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

#define STRLEN 8192
#define INITSTR "a"
#define GET_NEXT_CHAR(ch) ((ch) == 'z' ? 'a' : (ch)+1)

static char *get_append(char *origin) {

    char *expansion = NULL;

    if (origin) {

        expansion = (char *) calloc(strlen(origin)+1, sizeof(char));

        for (int i = 0; i < strlen(origin); i++) {
            expansion[i] = GET_NEXT_CHAR(origin[i]);
        }
    }
    return expansion;
}

static void do_append(char *str, int minimum_len) {

    char *extra = NULL;

    while (strlen(str) < minimum_len) {
        extra = get_append(str);
        strcat(str, extra);
        free(extra);
    }
    return;
}

char kthCharacter(int k) {

    char *str = NULL;
    char result = '\0';

    if (k) {
        str = (char *) calloc(STRLEN, sizeof(char));    
        strcpy(str, INITSTR);
        do_append(str, k);
        result = str[k-1];
        free(str);
    }
    return result;
}

int main(void) {

    int k = 5;
    char result = '\0';

    result = kthCharacter(k);

    printf("result: %c\n", result);

    return EXIT_SUCCESS;
}
