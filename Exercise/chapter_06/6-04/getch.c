/*
 * =====================================================================================
 *
 *       Filename:  getch.c
 *
 *    Description:  Get character or save it in an array for use in the future.  
 *
 *        Version:  1.0
 *        Created:  2022年05月29日 21時19分57秒
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

#define MAX_CHAR 100

static char ch_buffer[MAX_CHAR];
static int index = -1;

int getch(void) {
	if (index != -1) {
		return ch_buffer[index--];
	} else {
		return getchar();
	}
}

void ungetch(int ch) {
	ch_buffer[++index] = ch;	
	return;
}





