/*
 * =====================================================================================
 *
 *       Filename:  2288_apply_discount_to_prices.c
 *
 *    Description:  apply discount to prices
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04.3) 11.4.0
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

#define CH_TO_INT(val) ((val)-'0')
#define PRICE_MAXLEN 16
#define BUFFER_MAXLEN (200000) 

static bool is_price(char *ptr) {

    int len = 0;
    bool rc = true; 

    len = strlen(ptr);

    if (len > 1) {

        rc = ptr[0] == '$' ? true : false;

        for (int i = 1; rc && i < len; i++) {
            if (!isdigit(ptr[i])) {
                rc = false;
            }
        }
    } else {
        rc = false;
    }

    return rc;
}

static char *discount_price(char *price, int discount) {

    double final = 0.0;     
    long long value = 0LL;
    int len = 0;
    char *final_str = NULL;

    len = strlen(price);
    final_str = (char *) calloc(PRICE_MAXLEN, sizeof(char));
    final_str[0] = '$';

    for (int i = 1; i < len; i++) {
        value *= 10;    
        value += CH_TO_INT(price[i]);
    }

    final = (value * 1.0) - ((value * 1.0) * (discount/100.0));
    sprintf(&final_str[1], "%.02f", final);

    return final_str;
}

char* discountPrices(char* sentence, int discount) {

    char *ptr = NULL, *buffer = NULL;
    int bindex = 0;
    bool flag = false;

    buffer = (char *) calloc(BUFFER_MAXLEN, sizeof(char));
    ptr = strtok(sentence, " ");

    while (ptr) {

        if (is_price(ptr)) {
            ptr = discount_price(ptr, discount);
            flag = true;
        }

        memcpy(&buffer[bindex], ptr, strlen(ptr));
        bindex += strlen(ptr);

        if (flag)
            free(ptr);
        flag = false;

        ptr = strtok(NULL, " ");

        if (ptr)
            buffer[bindex++] = ' '; 
    }

    return buffer;
}
