/*
 * =====================================================================================
 *
 *       Filename:  3-6.c
 *
 *    Description:  The fixed width length version of function itoa() that have a third
 *    				parameter to set the width of a string.
 *
 *        Version:  1.0
 *        Created:  2021年09月18日 20時16分23秒
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

void reverse(char *s){

	int len = strlen(s) - 1, ch;

	for(int i = 0; i < len; i++, len--){
		ch = s[len];
		s[len] = s[i];
		s[i] = ch;	
	}
}


void itob(int n, char *s, int width){

	int sign, index = 0, padding;
	
	if((sign = n) < 0){
		n = -n;
	}

	do{
		s[index++] = (n%10) + '0';
	}while(n/=10);

	if(sign < 0){
		s[index++] = '-';
	}

	padding = width - strlen(s);
	memset((s + (strlen(s))), 32, padding);	

	reverse(s);
}



int main(int argc, char *argv[]){

	char str[100];
	memset(str, 0, sizeof(str));


	if(argc > 2){
		int width = atoi(argv[2]);
		printf("Converting...\n");
		itob(atoi(argv[1]), str, width);
		printf("Result : %s, len %ld\n", str, strlen(str));
	}else{
		printf("Please enter the correct arguments.\n");
	}

	return 0;
}






