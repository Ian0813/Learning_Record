/*
 * =====================================================================================
 *
 *       Filename:  strcpy.c
 *
 *    Description:  copy the string t to s.
 *
 *        Version:  1.0
 *        Created:  2021年11月29日 21時58分51秒
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

/* strcpy : copy t to s; array subscript version */
void strcpy_v1(char *s, char *t){

	int i;

	i = 0;
	while((s[i] = t[i]) != '\0'){
		s++;
		t++;
	}
}

/* strcpy : a version of strcpy with pointers  */
void sctcpy_v2(char *s, char *t){

	while((*s = *t) != '\0'){
		s++;
		t++;
	}
}

/* strcpy : a pointer version 2 */
void strcpy_v3(char *s, char *t){

	while((*s++ = *t++) != '\0')
			;
}

/* strcpy : a pointer version 3*/
void strcpt_v4(char *s, char *t){

	while((*s = *t))
		;
}






