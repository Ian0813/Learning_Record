/*
 * =====================================================================================
 *
 *       Filename:  557_reverse_words_in_a_string_iii.c
 *
 *    Description:  Reverse words in a string iii  
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

static void reverse(char *s) {

    char temp = '\0';

    for (int i = 0, j = strlen(s)-1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    return;
}

char* reverseWords(char* s) {

    char *last = (char *) calloc(strlen(s)+1, sizeof(char)), *cur = NULL, *remain = NULL;

    cur = strtok_r(s, " ", &remain);

    while (cur) {

        reverse(cur); 

        if (last) {
            strcat(last, cur);
        }

        cur = remain; 
        cur = strtok_r(cur, " ", &remain);

        if (cur) {
            strcat(last, " ");
        }
    }
    return last;
}

int main(void) {

    char test[BUFSIZ] = "Let's take LeetCode contest";    
    char *p = NULL;  

    p = reverseWords(test);
    printf("%s\n", p);

    free(p);

    return EXIT_SUCCESS;
}
