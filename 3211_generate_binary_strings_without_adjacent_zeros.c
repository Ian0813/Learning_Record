/*
 * =====================================================================================
 *
 *       Filename:  3211_generate_binary_strings_without_adjacent_zeros.c
 *
 *    Description:  generate binary strings without adjacent zeros
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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAX_LENGTH (18U)
#define MAX_COLUMNS (10000)

static void generate(char **strings, int digit, int size, int *index) {

    int append_index = 0;

    if (digit <= size) {

        if (digit == 1) {
            strings[0] = (char *) malloc((size+1) * sizeof(char));
            strings[1] = (char *) malloc((size+1) * sizeof(char));
            strcpy(strings[0], "0");
            strcpy(strings[1], "1");
            *index += 2;
        } else {

            append_index = *index;

            for (int i = 0; i < *index; i++) {
                if (strings[i][strlen(strings[i])-1] == '1') {
                    strings[append_index] = (char *) malloc((size+1) * sizeof(char));
                    memset(strings[append_index], 0, size);
                    memcpy(strings[append_index], strings[i], strlen(strings[i])); 
                    strcat(strings[append_index], "0");
                    append_index++;
                }
                strcat(strings[i], "1");  
            }
            *index = append_index;
        }
    }

    if (digit < size) {
        generate(strings, digit+1, size, index);
    }

    return;
}

static int get_power(int exp, int base) {

    int result = 1;

    if (exp) {
        while (exp--) {
            result *= base; 
        }
    }
    return result;
}

static int get_maxrow(int pattern_length) {

    int base = 2;
    return get_power(pattern_length, base);
}

char** validStrings(int n, int* returnSize) {

    int max_rows = 0; 
    int index = 0;
    char **result = NULL;

    if (n) {
        max_rows = get_maxrow(n);
        result = (char **) calloc(max_rows, sizeof(char *));
        generate(result, 1, n, &index);
#if 0
        for (int i = 0; i < index; i++) {
            printf("%s\n", result[i]);
        }
#endif
    }
    *returnSize = index;
    return result;
}

int main(void) {

    char **result = NULL;
    int index = 0;

    result = validStrings(1, &index);

    for (int i = 0; i < index; i++) {
        printf("%s\n", result[i]);
        free(result[i]);
    }
    free(result);

    return EXIT_SUCCESS;
}
