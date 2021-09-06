/*
 * =====================================================================================
 *
 *       Filename:  2-10.c
 *
 *    Description:  map a single character to lowercase for the ASCII character set,
 *    				using ternary operator,
 *
 *        Version:  1.0
 *        Created:  2021年09月07日 00時56分49秒
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

int lower(int c){

	
	return (c >= 65 && c <= 90) ? c + 32 :
		printf("This character is not lowercase alphabet.\n");
	
}


int main(){

	char str[100] = "HELLO";

	for(int i = 0; i < strlen(str); i++){
		printf("%c", lower(str[i]));
	}
	putchar(10);

	return 0;
}


