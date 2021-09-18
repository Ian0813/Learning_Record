/*
 * =====================================================================================
 *
 *       Filename:  2810_faulty_keyboard.c
 *
 *    Description:  faulty keyboard  
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

void reverse(char *s, int start, int end) {

    char ch = '\0';

    while (start < end) {
        ch = s[start];        
        s[start] = s[end];
        s[end] = ch;
        start++;
        end--;
    }
    return;
}

char * finalString(char * s){

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == 'i') {
            reverse(s, 0, i - 1);  
            memmove(s + i, s + (i + 1), strlen(s) - (i+1));   
            s[strlen(s) - 1] = '\0';
            i--;
        }
    }
    return s;
}

int main(void) {

    return 0;
}
