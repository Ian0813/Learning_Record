/*
 * =====================================================================================
 *
 *       Filename:  405_convert_a_number_to_hexadecimal.c
 *
 *    Description:  Convert a number to hexadecimal 
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

void hexstr_append(char *hex_str, int *len, uint8_t segment) {

    uint8_t hexadecimal = 0;

    for (int i = 4; i >= 0; i -= 4) {

        hexadecimal = (segment >> i) & 0x0F;

        switch (hexadecimal) {
            case 10: {
                hex_str[*len] = 'a'; 
            }
            break;
            case 11: {
                hex_str[*len] = 'b'; 
            }
            break;
            case 12: {
                hex_str[*len] = 'c'; 
            }
            break;
            case 13: {
                hex_str[*len] = 'd'; 
            }
            break;
            case 14: {
                hex_str[*len] = 'e'; 
            }
            break;
            case 15: {
                hex_str[*len] = 'f'; 
            }
            break;
            default:
                hex_str[*len] = (hexadecimal + '0');
        }
        *len += 1;
    }
}

char* toHex(int num) {

    char *hex_str = NULL;
    uint8_t segment = 0;
    int len = 0;

    hex_str = (char *) calloc(9, sizeof(char));
    
    if (num) {
        for (int i = 24; i >= 0; i-=8) {
            segment = (num >> i) & 0xFF;
            hexstr_append(hex_str, &len, segment);
        }

        while (hex_str[0] == '0') {
            memmove(hex_str, hex_str+1, len-1);
            len--;
        }    
    } else {
        hex_str[len++] = (num + '0');
    }
    hex_str[len] = '\0';
    return hex_str;
}

int main(void) {

    char *str = NULL;

    str = toHex(1000000000);

    printf("str: %s\n", str);

    free(str);
    return EXIT_SUCCESS;
}
