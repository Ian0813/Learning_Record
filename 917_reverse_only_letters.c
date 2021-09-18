/*
 * =====================================================================================
 *
 *       Filename:  917_reverse_only_letters.c
 *
 *    Description:  Reverse only letters 
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

unsigned int string_len(char *s) {

    unsigned int length = 0;

    while (*s++) {
        length++;
    }
	return length;
}

void swap(char *ch1, char *ch2) {

    char temp = *ch1;

	*ch1 = *ch2;
	*ch2 = temp;

	return;
}

char* reverseOnlyLetters(char* s) {

    unsigned int head = 0, tail = string_len(s) - 1;

	for (head = 0, tail = string_len(s); head < tail;) {
        if (!isalpha(s[head])) {
            head++;
			continue;
		} else if (!isalpha(s[tail])) {
            tail--;
			continue;
		}
		swap(&s[head], &s[tail]);
		head++;
		tail--;
	}
	return s;
}

int main(void) {

    char str[BUFSIZ] = "a-bC-dEf-ghIj";

    printf("%s\n", reverseOnlyLetters(str));

	return 0;
}
