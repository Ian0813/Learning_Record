/*
 * =====================================================================================
 *
 *       Filename:  125_valid_palindrome.c
 *
 *    Description:  Valid palidrome   
 *
 *         Author:  Ian
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef int bool;
#define true 1
#define false 0

bool isPalindrome(char *s) {

    char *copy = (char *) malloc(sizeof(char) * strlen(s) + sizeof(char));
	int i = 0, j = 0;

	if (strlen(s) < 1) {
        return true;
	}

	for (i = 0, j = 0; i < strlen(s); i++) {
        if (isalpha(*(s+i))) {
            *(copy+j) = *(s+i);
			j++;
		}
	}
    *(copy+j) = '\0';
	puts(copy);

	for (int head = 0, end = strlen(copy) - 1; head < end; head++, end--) {
        if (tolower(copy[head]) != tolower(copy[end])) {
            free(copy);
			return false;
		}
	}
	free(copy);
	return true;
}

int main(void) {

    printf("%d \n", isPalindrome("0P"));

	return 0;
}







