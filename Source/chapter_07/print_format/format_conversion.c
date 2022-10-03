/*
 * =====================================================================================
 *
 *       Filename:  format_conversion.c
 *
 *    Description:  Use a variety of format specifiers to print a string out. 
 *
 *        Version:  1.0
 *        Created:  2022年08月20日 14時59分42秒
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


void main(void) {

	char *str = "hello, world";

	printf("The \"%s\" string contains %ld bytes.\n", str, strlen(str));

	putchar(10);	

	printf("%%s       : %s\n", str);
	printf("%%10s     : %10s\n", str);
	printf("%%.10s    : %.10s\n", str);
	printf("%%-10s    : %-10s\n", str);
	printf("%%.15s    : %.15s\n", str);
	printf("%%-15s    : %-15s\n", str);
	printf("%%15.10s  : %15.10s\n", str);
	printf("%%-15.10s : %-15.10s\n", str);


	return;
}

