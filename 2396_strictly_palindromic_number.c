/*
 * =====================================================================================
 *
 *       Filename:  2396_strictly_palindromic_number.c
 *
 *    Description:  strictly palindromic number
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
#include <stdint.h>
#include <limits.h>

typedef enum {false, true} bool;

#define INT_TO_CH(val) ((val)+'0')
#define NUM_LEN 20

char *convert_on_base(int val, int base) {

    char result[NUM_LEN] = {0};    
    char *ptr = result; 

    while (val) {
        *(ptr++) = INT_TO_CH(val%base);
        val /= base;
    }
    return strdup(result);
}

bool is_palindrome(const char *str) {

    bool rc = true; 

    for (int i = 0, j = strlen(str)-1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            rc = false; 
            break;
        }
    }
    return rc;
}    

bool isStrictlyPalindromic(int n) {

    bool rc = true;
    char *ptr = NULL;

    if (n < 5) {
        for (int i = 2; i < (n-1); i++) {

            ptr = convert_on_base(n, i);

            if (!is_palindrome(ptr)) {
                rc = false;  
                break;
            }
            free(ptr);
        }    
    } else {
        rc = false;
    }

    return rc;
}

