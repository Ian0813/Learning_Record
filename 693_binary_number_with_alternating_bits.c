/*
 * =====================================================================================
 *
 *       Filename:  693_binary_number_with_alternating_bits.c
 *
 *    Description:  Binary number with alternating bits  
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

typedef enum {false, true} bool;

void reverse(char *str) {

    char temp = '\0';

    for (int i = 0, j = strlen(str)-1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
    return;
}

char *get_bits_array(int n) {

    char *bits = (char *) calloc(sizeof(int)*8, sizeof(char));
    char *ptr = bits;

    while (n) {
        *ptr = (n%2)+'0';
        ptr++;
        n /= 2;
    }
    reverse(bits);
    return bits;
}    

bool hasAlternatingBits(int n) {

    char *bits = NULL;
    bool rc = true;

    if (n) {
        bits = get_bits_array(n);
        for (int i = 0; i < strlen(bits)-1; i++) {
            if (bits[i] == bits[i+1]) {
                rc = false;
                break;
            }
        }
    }
    return rc;
}
