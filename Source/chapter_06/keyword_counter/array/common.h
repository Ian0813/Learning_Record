/*
 * =====================================================================================
 *
 *       Filename:  common.h
 *
 *    Description:  Declare the prototype of each function to use.
 *
 *        Version:  1.0
 *        Created:  2022年05月29日 22時12分07秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ian 
 *   Organization:  
 *
 * =====================================================================================
 */

struct key {
	char *word;
	int count;
};

int getch(void);

void ungetch(int ch);

int binsearch(char *, struct key *, int);

int getword(char *, int);

