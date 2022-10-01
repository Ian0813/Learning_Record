/*
 * =====================================================================================
 *
 *       Filename:  getop.c
 *
 *    Description:  Get next operator or numeric operand 
 *
 *        Version:  1.0
 *        Created:  2022年09月15日 01時48分48秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ian 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUMBER '0' /*  signal that a number was found */

int getop(char s[]) {

    int i, rc; 
	char c;
	static char lastc[] = " ";

	if (sscanf(lastc, "%c", &c) < 0) {
        perror("sscanf ");
		exit(EXIT_FAILURE);
	}

	lastc[0] = ' ';    /* clear last character */
	while ((s[0] = c) == ' ' || c == '\t') {

        if (scanf("%c", &c) == EOF) {
            c = EOF;
		}
	}

	s[1] = '\0';
	if (!isdigit(c) && c != '.') {
        return c;    /* not a number */
	}

	i = 0;
	if (isdigit(c)) {   /* collect integer part */            
        do {
            rc = scanf("%c", &c);
			if (!isdigit(s[++i] = c)) {
                break;
			}
		} while (rc != EOF);
	}

	if (c == '.') {
        do {
            rc = scanf("%c", &c);
			if (!isdigit(s[++i] = c)) {
                break;
			}
		} while (rc != EOF);
	}
	s[i] = '\0';
	if (rc != EOF) {
        lastc[0] = c;
	}

	return NUMBER;
}	




