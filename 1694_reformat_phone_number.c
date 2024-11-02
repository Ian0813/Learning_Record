/*
 * =====================================================================================
 *
 *       Filename:  1694_reformat_phone_number.c
 *
 *    Description:  Reformat phone number   
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

static void remove_dashes(char *number) {

    int remain = 0, offset = 0;

    for (remain = 0, offset = 0; offset < strlen(number); offset++) {
        if (isdigit(number[offset])) {
            number[remain++] = number[offset];
        }
    }
    number[remain] = '\0';

    return;
}    

char* reformatNumber(char* number) {

    int digit_amount = 0;
    int len = 0, remain = 0, rindex = 0;
    char *result = NULL;

    result = (char *) calloc(strlen(number)*2, sizeof(char));
    remove_dashes(number); 
    len = strlen(number);

    while (len >= 3 && ((len-3) != 1)) {
        memcpy(result+rindex, number+(strlen(number)-len), sizeof(char) * 3);
        rindex += 3;
        result[rindex] = '-';
        rindex += 1;
        len -= 3;
    }

    while (len >= 2) {
        memcpy(result+rindex, number+(strlen(number)-len), sizeof(char) * 3);
        rindex += 2;
        result[rindex] = '-';
        rindex += 1;
        len -= 2;
    }

    result[rindex-1] = '\0';
    return result;
}

int main(void) {

    char str[] = "1211"; 
    char *ptr = NULL;

    ptr = reformatNumber(str);
    printf("ptr len: %ld\n", strlen(ptr));
    for (int i = 0; i < strlen(ptr); i++) {
        printf("%c ", ptr[i]);
    }
    putchar('\n');
    free(ptr);

    return EXIT_SUCCESS;
}
