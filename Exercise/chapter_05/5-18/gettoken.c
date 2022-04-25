/*
 * =====================================================================================
 *
 *       Filename:  gettoken.c
 *
 *    Description:  Find a next token in the input.
 *
 *        Version:  1.0
 *        Created:  2022年04月02日 15時31分32秒
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
#include "dcl_parser.h"
#include <unistd.h>

int gettoken(void) { /* return next token */

	int c, getch(void);
	void ungetch(int);
	char *p = token;

	if (prevtoken == YES) {
		prevtoken = NO;
		return tokentype;
	}

	while ((c = getch()) == ' ' || c == '\t')
			;


	if (c == '(') {
		if ((c = getch()) == ')') {
			strcpy(token, "()");
			return tokentype = PARENS;
		} else {
			ungetch(c);
			return tokentype = '(';
		}
	} else if (c == '[') {
		for (*p++ = c; (*p++ = getch()) != ']';)
				;
		return tokentype = BRACKETS;
	} else if (isalpha(c)) {
		for (*p++ = c; isalnum(c = getch());) {
			*p++ = c;
		}
		ungetch(c);
		return tokentype = NAME;
	} else {
		return tokentype = c;
	}
}

