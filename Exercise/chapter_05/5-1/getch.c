/*
 * =====================================================================================
 *
 *       Filename:  getch.c
 *
 *    Description:  Get a character or push a character back. 
 *
 *        Version:  1.0
 *        Created:  2021年11月21日 14時58分44秒
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


#define BUFSIZE 100

char buf[BUFSIZE];    /* buffer for ungetch */
int bufp = 0;         /* next free position in buf */


int getch(void) /* get a (possibily pushed bach) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}


void ungetch(int c) /*  push character back on input */
{
	printf("[%s] %d, %c\n", __func__, c, c);
	if(bufp >= BUFSIZE){
		printf("ungetch : too many characters \n");
	}else{
		buf[bufp++] = c;
	}
}

