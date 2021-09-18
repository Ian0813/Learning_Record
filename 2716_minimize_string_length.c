/*
 * =====================================================================================
 *
 *       Filename:  2716_minimize_string_length.c
 *
 *    Description:  Minimize string length  
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

/*
 * Input: s = "aaabc"
 * Output: 3*
*/

#define ALPHA_SIZE 26

int minimizedStringLength(char * s) {

    char table[ALPHA_SIZE] = {0};
	int len = 0;

	for (int i = 0; i < strlen(s); i++) {
       table[s[i] - 97] = 1;     
	}

	for (int i = 0; i < ALPHA_SIZE; i++) {
        len = table[i] == 1 ? (len + 1) : len; 
	}
	return len; 
}

int main(void) {

    char *str = "aaabc";

	fprintf(stdout, "length: %d\n", minimizedStringLength(str));

	return 0;
}

