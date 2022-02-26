/*
 * =====================================================================================
 *
 *       Filename:  reverse.c
 *
 *    Description:  Reverse a string recursively. 
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


void reverse(char *s, int head, int tail){

	char temporary;

	if(head < tail){
		temporary = s[head];
		s[head] = s[tail];
		s[tail] = temporary;
		reverse(s, head + 1, tail - 1);
	}	
}


