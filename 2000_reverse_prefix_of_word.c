/*
 * =====================================================================================
 *
 *       Filename:  2000_reverse_prefix_of_word.c
 *
 *    Description:  Reverse prefix of word  
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


void range_reverse(char *str, int head, int end) {

    char ch = '\0'; 

    for (; head < end; head++, end--) {
        ch = str[head];
        str[head] = str[end];
        str[end] = ch;
    }
    return;
}

char* reversePrefix(char* word, char ch) {

    for (int i = 0; i < strlen(word); i++) {
        if (word[i] == ch) {
            range_reverse(word, 0, i);
            break;
        }
    }
    return word;
}
