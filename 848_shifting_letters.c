/*
 * =====================================================================================
 *
 *       Filename:  848_shifting_letters.c
 *
 *    Description:  Shifting Letters  
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

char* shiftingLetters(char* s, int* shifts, int shiftsSize) {

    int sum = 0;

    for (int i = shiftsSize-1; i >= 0; i--) {
        sum = sum + (shifts[i]%26);
        shifts[i] = sum;
    }

    for (int i = 0; i < shiftsSize; i++) {
        s[i] = (((s[i]-'a')+shifts[i])%26)+'a';
    }
    return s;
}

int main(void) {

    char s[4] = "abc";
    int arr[] = {3, 5, 9};
    char *ptr = NULL;

    ptr = shiftingLetters(s, arr, 3);

    printf("ptr: %s\n", ptr); 

    return EXIT_SUCCESS;
}
