/*
 * =====================================================================================
 *
 *       Filename:  2138_divide_a_string_into_groups_of_size_k.c
 *
 *    Description:  Divide a string into groups of size k  
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

char** divideString(char* s, int k, char fill, int* returnSize) {

    int number = 0;
    char **result = NULL;
	int index = 0, remain = 0, len = 0, tail = 0;

	if ((remain = strlen(s)%k)) {
        number = strlen(s)/k + 1;  
	} else {
        number = strlen(s)/k;  
	}

    result = (char **) calloc(number, sizeof(char *));

    for (int i = 0; i < number; i++) {
        result[i] = (char *) malloc(sizeof(char) * (k+1));
    }

    for (int times = 0; times < strlen(s)/k; times++) {
        memcpy(result[index], s + len, k);
		result[index][k] = '\0';
        len += k; 
        index++;
	}

	if (remain) {
        tail = strlen(s) - len;
		memcpy(result[index], s + len, tail);
		for (int i = tail + 1; i <= k; i++) {
            result[index][i-1] = fill;
		}
		result[index][k] = '\0';
	}

	*returnSize = number;

	return result; 
}

void release(char **s, int size) {
    for (int i = 0; i < size; i++) {
        free(s[i]); 
	}
	free(s);
	return;
}

int main(void) {

    char **result = NULL;
	int size = 0, sublen = 3;
	char *s = "abcdefghii", fill = 'x';

    result = divideString(s, sublen, fill, &size);

	for (int i = 0; i < size; i++) {
        fprintf(stdout, "%s\n", result[i]);
	}

    release(result, size);

    return 0;
}
