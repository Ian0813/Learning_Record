/*
 * =====================================================================================
 *
 *       Filename:  00000_multiply_strings.c
 *
 *    Description:  Multiply Strings  
 *
 *       Compiler:  gcc (Ubuntu 12.3.0-1ubuntu1~22.04) 12.3.0
 *
 *         Author:  Ian
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define CHAR_TO_INT(ch) (ch - 48)  
#define INT_TO_CHAR(num) (num + 48)  
#define MAX 1001

void reverse(char *str) {

    int head = 0, end = strlen(str) - 1; 
    char ch = '\0';

    for (; head < end; head++, end--) {
        ch = str[head];
        str[head] = str[end];
        str[end] = ch;
    }
    return;
}

void add_strings(char *result, char *addend) {

    int value = 0;
    int carryin = 0;

    do {
        value = 0;

        if (isdigit(*result)) {
            value += CHAR_TO_INT(*result);
        }

        if (isdigit(*addend)) {
            value += CHAR_TO_INT(*addend);
        }
        value += carryin;

        if (value > 9) {
            carryin = value/10;
            value %= 10;
        } else {
            carryin = 0;
        }
        *result = INT_TO_CHAR(value);
        result++;
        addend++;
    } while (isdigit(*result) || isdigit(*addend));

    if (carryin) {
        *result = INT_TO_CHAR(carryin);
        result++;
    }
    *result = '\0';

    return;
}

char* multiply(char* num1, char* num2) {

    char *temp = (char *) calloc(MAX, sizeof(char));
    char *result = (char *) calloc(MAX, sizeof(char));
    int value = 0, index = 0, carryin = 0, shift = 0;

    for (int i = strlen(num1) - 1; i >= 0; i--) {

        memset(temp, 0, sizeof(char) * MAX);
        index = 0;

        for (int j = strlen(num2) - 1; j >= 0; j--) {

            value = CHAR_TO_INT(num1[i]) * CHAR_TO_INT(num2[j]);
            value += carryin;

            if (value > 9) {
                carryin = value/10;
                value %= 10;
            } else {
                carryin = 0;
            }
            temp[index++] = INT_TO_CHAR(value);
        }

        if (carryin > 0) {
            temp[index++] = INT_TO_CHAR(carryin);
            carryin = 0;
        }
        temp[index] = '\0';
        add_strings(result + shift, temp);
        shift++;
    }
	free(temp);
    reverse(result);

	return result;
}

int main(void) {

    char *result = NULL;
    result = multiply("123", "456"); 

    printf("result: %s\n", result);
	free(result);

    return EXIT_SUCCESS;
}
