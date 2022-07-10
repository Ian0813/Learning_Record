/*
 * =====================================================================================
 *
 *       Filename:  getch.c
 *
 *    Description:  Get character or save it in an array for use in the future. 
 *
 *        Version:  1.0
 *        Created:  2022年07月09日 23時26分10秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ian 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>

#define ARRAY_SIZE 1000

int index = -1;
char char_array[ARRAY_SIZE];

int getch(void) {

	if (index == -1) {
		return getchar();
	} else {
		return char_array[index--];
	}
}

void ungetch(int c) {
	
	if (index < ARRAY_SIZE) {
		char_array[++index] = c; 
	} else {
		printf("Space is not enough.\n");
	}
}



