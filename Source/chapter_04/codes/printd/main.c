/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  This function is to represent a number by character.  
 *
 *        Version:  1.0
 *        Created:  2021年11月09日 00時46分20秒
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


void printd(int);

int main(void){

	int number;

	printf("Please enter a number as a input : ");
	scanf("%d", &number);


	printd(number);
	printf("\n");

	return 0;
}
