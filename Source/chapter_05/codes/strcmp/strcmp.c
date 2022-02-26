/*
 * =====================================================================================
 *
 *       Filename:  strcmp.c
 *
 *    Description:  comparison two strings
 *
 *        Version:  1.0
 *        Created:  2021年12月02日 01時09分17秒
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


/* strcmp : return < 0 if s < t, 0 if s == t, > 0 if s > t  */
int strcmp_v1(char *s, char *t){

	int i;

	for(i = 0; s[i] == t[i]; s++, t++){
		if(s[i] == '\0'){
			return 0;
		}
	}

	return s[i] - t[i];
}

/* strcmp : a pointer version of the strcmp */
int strcmp_v2(char *s, char *t){

	for(; *s == *t; s++, t++){
		if(*s == '\0'){
			return 0;
		}
	}

	return *s - *t;
}

