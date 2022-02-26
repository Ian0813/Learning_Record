/*
 * =====================================================================================
 *
 *       Filename:  itoa.c
 *
 *    Description:  Convert a number to a character string recursively. 
 *
 *        Version:  1.0
 *        Created:  2021年09月16日 00時59分48秒
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
#include <limits.h>


void reverse(char *s){

	int head = 0, tail = strlen(s) - 1, ch;

	for(; head < tail; head++, tail--){
		ch = s[tail];
		s[tail] = s[head];
		s[head] = ch;
	}
}

void itoa(int n, char *s){
	
	static int index = 0;
 	int	sign = n;
	//printf("n : %d\n", n);

	if( sign < 0){
		n = -n;
		s[index++] = '-';
	}

	if(n/10){
		itoa(n/10, s);
	}

	s[index++] = '0' + (n%10);
	
}

