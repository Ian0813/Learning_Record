/*
 * =====================================================================================
 *
 *       Filename:  844_backspace.c
 *
 *    Description:  Backspace Compare
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

#define CONVERT_BACKSPACE(ch) (ch = ch == '#' ? '\b' : ch) 

typedef int bool; 

bool backspaceCompare(char* s, char* t) {

    char *dups = (char *) malloc(strlen(s) + 1);
    char *dupt = (char *) malloc(strlen(t) + 1);
	int indexs = 0, indext = 0; 

    for (int i = 0; i < strlen(s); i++) {
        if (s[i] != '#') {
            dups[indexs++] = s[i]; 
		} else {
            dups[--indexs] = '\0';
		}
	}

    for (int i = 0; i < strlen(t); i++) {
        if (t[i] != '#') {
            dupt[indext++] = t[i]; 
		} else {
            dupt[--indext] = '\0';
		}
    }

	memcpy(s, dups, strlen(s) + 1);
	memcpy(t, dupt, strlen(t) + 1);
	free(dups);
	free(dupt);

	return !strcmp(s, t);
}

int main(void) {

    char s[BUFSIZ] = "ab#c", t[BUFSIZ] = "ad#c";
	int rc = 0;

	rc = backspaceCompare(s, t);
	fprintf(stdout, "rc: %d\n", rc);

	return 0;
}

