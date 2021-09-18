/*
 * =====================================================================================
 *
 *       Filename:  itoa.c
 *
 *    Description:  Convert a number to a character string 
 *
 *        Version:  1.0
 *        Created:  2021年09月16日 00時59分48秒
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
#include <limits.h>


void reverse(char *s){

	int head = 0, tail = strlen(s) - 1, ch;

	for(; head < tail; head++, tail--){
		ch = s[tail];
		s[tail] = s[head];
		s[head] = ch;
	}
}

void itoa(int n, char *s){
	
	int i = 0, sign = n;

	if( sign < 0){
		n = -n;
	}
	
	do{
		s[i++] = n % 10 + '0';	
	}while((n/=10) > 0);

	if(sign < 0){
		s[i++] = '-';
	}

	reverse(s);
}


int main(int argc, char *argv[]){

	char str[100] = {0};	
	if(argc > 1){
		itoa(atoi(argv[1]), str);
		printf("str : %s\n", str);	
	}else{
		printf("Please enter the argument.\n");
	}

	return 0;
}


