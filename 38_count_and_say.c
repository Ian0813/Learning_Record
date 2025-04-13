/*
 * =====================================================================================
 *
 *       Filename:  38_count_and_say.c
 *
 *    Description:  count and say
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

#define INT_TO_CH(value) ((value)+'0')
#define CH_TO_INT(ch) ((ch)-'0')
#define DIGIT_SIZE 10

typedef struct compressed_data {
    char *str;
    char *count_str;
    char previous_ch;
    int table[DIGIT_SIZE];
} compressed_info_t;

static char *get_count_str(int value) {

    int len = 0;
    char temp[BUFSIZ] = {0}, ch = '\0';

    while (value) {
        temp[len++] = INT_TO_CH(value%10); 
        value /= 10;
    }

    for (int i = 0, j = len-1; i < j; i++, j--) {
        ch = temp[i];     
        temp[i] = temp[j];
        temp[j] = ch;
    }
    return strdup(temp);
}

char* countAndSay(int n) {

    char *result = NULL;
    int rindex = 0, index = 0;
    compressed_info_t data = {0};

    if (n == 1) {
        result = strdup("1");
    } else {

        result = (char *) calloc(BUFSIZ, sizeof(char));
        data.str = countAndSay(n-1);
        data.table[CH_TO_INT(data.str[0])]++;
        data.previous_ch = data.str[0];
        index++; 

        do {
            if (data.previous_ch != data.str[index]) {
                data.count_str = get_count_str(data.table[CH_TO_INT(data.previous_ch)]);
                memcpy(&result[rindex], data.count_str, strlen(data.count_str));
                rindex += strlen(data.count_str);
                result[rindex++] = data.previous_ch;
                data.table[CH_TO_INT(data.previous_ch)] = 0; 
                free(data.count_str);

                if (data.str[index] != '\0') {
                    data.table[CH_TO_INT(data.str[index])]++;
                    data.previous_ch = data.str[index];
                }
            } else {
                data.table[CH_TO_INT(data.str[index])]++;
            }
            index++;
        } while (index <= strlen(data.str));
        free(data.str);
    }
    return result; 
}

int main(int argc, char *argv[]) {

    char *result = NULL;
    int n = 1;

    if (argc > 1) {
        n = atoi(argv[1]);
    }

    result = countAndSay(n);

    printf("result: %s\n", result);

    free(result);

    return EXIT_SUCCESS;
}
