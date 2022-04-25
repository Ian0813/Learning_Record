/*
 * =====================================================================================
 *
 *       Filename:  getch.c
 *
 *    Description:  The character handler that for input and output operation. 
 *
 *        Version:  1.0
 *        Created:  2022年04月02日 18時14分23秒
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

#define MAXIMUM 100

static char array_char[MAXIMUM];
static int array_index = -1; 

int getch(void){

	int temp;

	if (array_index == -1) {
		return getchar();
	} else {
		temp = array_char[array_index];
		array_index--;
		return temp; 
	}
}

void ungetch(int ch){

	if ((array_index+1) < MAXIMUM) {
		array_index++;
		array_char[array_index] = ch;	
	} else {
		fprintf(stderr, "The space is not enough.\n");
	}
}
