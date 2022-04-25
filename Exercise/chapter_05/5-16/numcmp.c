/*
 * =====================================================================================
 *
 *       Filename:  numcmp.c
 *
 *    Description:  Compare s1 and s2 numcrically.
 *
 *        Version:  1.0
 *        Created:  2022年01月27日 23時42分01秒
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


/* numcmp : compare s1 and s2 numerically. */
int numcmp(char *s1, char *s2){
	
	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);

	if(v1 < v2){
		return -1;
	}else if(v1 > v2){
		return 1;
	}else{
		return 0;
	}
}
