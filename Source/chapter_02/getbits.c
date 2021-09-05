/*
 * =====================================================================================
 *
 *       Filename:  getbits.c
 *
 *    Description:  getbits(x, p , n) Return the n-bits field of x that begins at 
 *    				position p 
 *
 *        Version:  1.0
 *        Created:  2021年09月01日 21時49分04秒
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


/*  getbits : get n bits from position p  */
unsigned int getbits(unsigned int x, int p, int n){
	
	return ( x >> (p + 1 - n) ) & ~( ~0 << n );
}



int main(){

	int x, p, n;
	unsigned int result;
	printf("Please enter three integer : \n");
	scanf("%d%d%d", &x, &p, &n);

	result = getbits(x, p, n);	

	printf("result : %u\n", result);

	return 0;
}
