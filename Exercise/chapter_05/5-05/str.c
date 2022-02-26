/*
 * =====================================================================================
 *
 *       Filename:  str.c
 *
 *    Description:  a pointer versions of the strncpy, strncmp and strncat.  
 *
 *        Version:  1.0
 *        Created:  2021年12月03日 00時50分05秒
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


/* pointer version   */
int strncmp_p(char *s, char *t, int n){
	
	for(; n && *s == *t; n--, s++, t++)
		;

	if(n != 0){
		return (*s - *t);
	}

	return 0;		
}


char *strncat_p(char *s, char *t, int n){

	int s_len = strlen(s);

	for(int i = 0; i < n && t[i]; i++){
		s[s_len++] = t[i];
	}
	
	return s;	
}

char *strncpy_p(char *s, char *t, int n){
	
	for(int i = 0; i < n && t[i] != '\0'; i++){
		s[i] = t[i];
	}

	return s;	
}

