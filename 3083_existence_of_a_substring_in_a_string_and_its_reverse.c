/*
 * =====================================================================================
 *
 *       Filename:  3083 existence of a substring in a string and its reverse.c
 *
 *    Description:  existence of a substring in a string and its reverse
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04.2) 11.4.0
 *
 *         Author:  Ian
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

typedef enum {false, true} bool;

static void reverse(char *s) {

    int len = strlen(s);
	char temp = '\0';

	for (int i = 0, j = len-1; i < j; i++, j--) {
        temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
	return;
}

static bool is_exist_revsub(char *s, char *sub) {
    return strstr(s, sub) ? true : false; 
}

bool isSubstringPresent(char* s) {

    int len = strlen(s);
    bool rc = false;
	char sub[BUFSIZ] = {0}, sub_size = 2;

    for (int i = 0; i < (len - 1); i++) {

        memcpy(sub, s + i, sub_size);  
		reverse(sub);

		if (is_exist_revsub(s, sub)) {
            rc = true;
			break;
		}
    }

    return rc;
}

int main(void) {

    char str[BUFSIZ] = "abcd";

    printf("%d\n", isSubstringPresent(str));

    return EXIT_SUCCESS;
}
