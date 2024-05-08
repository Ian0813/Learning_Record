/*
 * =====================================================================================
 *
 *       Filename:  868_binary_gap.c
 *
 *    Description:  Binary Gap  
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

int convert_bstr(int n, char *str, int *one_counts) {

    int index = 0;

    while (n) {
        str[index] = (n%2) + '0';
        n /= 2;

        if (str[index] == '1') {
            *one_counts = *one_counts + 1; 
        }
        index++;
    }
    return index;
}

void reverse(char *str) {

    char ch = '\0';

    for (int i = 0, j = strlen(str)-1; i < j; i++, j--) {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
    }
    return;
}

int binaryGap(int n) {

    char binary[BUFSIZ] = {0}; 
    int len = 0, one_counts = 0;
    int last = 0, temp = 1, zero_counts = 1;
    int result = 0;

    len = convert_bstr(n, binary, &one_counts);

    reverse(binary);

    last = len - 1;

    if (len > 1 && one_counts > 1) {

        while (last) {

            for (int i = last-1; i >= 0; i--) {
                if (binary[i] == '1') {
                    last = i;
                    while (last > 0 && binary[last] == '1')
                        last--;
                    break;
                }
            }

           while (last && binary[last] == '0') {
               temp++; 
               last--;
           }

           if (temp > zero_counts) {
               zero_counts = temp;
           }
           temp = 1;
        }    
        result = zero_counts;
    }
    return result;
}
