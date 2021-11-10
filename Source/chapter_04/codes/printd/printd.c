/*
 * =====================================================================================
 *
 *       Filename:  printd.c
 *
 *    Description:  This function is to represent a number by character.  
 *
 *        Version:  1.0
 *        Created:  2021年11月09日 00時53分42秒
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

void printd(int n){

	if( n < 0 ){
		putchar('-');
		n = -n;	
	}


	if(n/10){
		printd(n/10);
	}
	putchar(n%10+'0');
}

