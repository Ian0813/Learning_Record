/*
 * =====================================================================================
 *
 *       Filename:  strcat.c
 *
 *    Description:  a pointer version of the strcat() 
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


/* strcat : a pointer version */
void strcat(char *s, char *t){


	while(*s != '\0')
		s++;

	for(; (*s = *t) != '\0'; s++, t++)
		;

}

