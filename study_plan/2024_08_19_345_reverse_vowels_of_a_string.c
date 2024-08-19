/*
 * =====================================================================================
 *
 *       Filename:  2024_08_19_345_reverse_vowels_of_a_string.c
 *
 *    Description:  Reverse vowels of a string  
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
#include <ctype.h>

typedef enum {false, true} bool;

#ifdef BUFSIZ
#undef BUFSIZ
#define BUFSIZ 100001
#endif

const char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}; 

bool isvowel(char ch) {

    for (int i = 0; i < sizeof(vowels)/sizeof(char); i++) {
        if (ch == vowels[i]) {
            return true; 
        }
    }
    return false;
}

char* reverseVowels(char* s) {

    char arr[BUFSIZ] = {0};
    int index = 0;

    for (int i = 0; i < strlen(s); i++) {
        if (isvowel(s[i])) {
            arr[index++] = s[i];  
        }
    }

    for (int i = 0; i < strlen(s); i++) {
        if (isvowel(s[i])) {
            s[i] = arr[--index];  
        }    
    }
    return s;
}
