/*
 * =====================================================================================
 *
 *       Filename:  3280_convert_date_to_binary.c
 *
 *    Description:  convert date to binary
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

#define CH_TO_INT(ch) ((ch)-'0')
#define INT_TO_CH(val) ((val)+'0')
#define REVERSE(str) {char temp; for (int i = 0, j = strlen(str)-1; i < j; i++, j--) {temp = str[i]; str[i] = str[j]; str[j] = temp;}}

static int str_to_int(char *str) {

    int value = 0;

    for (int i = 0; i < strlen(str); i++) {
        value *= 10;
        value += (CH_TO_INT(str[i]));
    }
    return value;
}

static char *to_binary(int value) {

    char binary[BUFSIZ] = {0};
    int index = 0;

    while (value) {
        binary[index++] = INT_TO_CH(value%2); 
        value /= 2;
    }
    REVERSE(binary);
    return strdup(binary);
}

char* convertDateToBinary(char* date) {

    char *ptr = NULL, *processed = NULL;
    int value = 0;
    char *result = NULL;

    result = (char *) calloc(BUFSIZ, sizeof(char));
    ptr = strtok(date, "-"); 

    while (ptr) {
        if (strlen(result))
            strcat(result, "-");
        value = str_to_int(ptr);
        processed = to_binary(value); 
        strcat(result, processed);
        free(processed);
        ptr = strtok(NULL, "-"); 
    }
    return result; 
}

int main(void) {

    char date[BUFSIZ] = "2080-02-29";
    char *ptr = NULL;

    ptr = convertDateToBinary(date); 

    printf("%s\n", ptr);

    free(ptr);

    return EXIT_SUCCESS;
}

