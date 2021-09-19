/*
 * =====================================================================================
 *
 *       Filename:  3-5.c
 *
 *    Description:  The function itob(n, s, b)
 *    				will convert the integer n into a base b character representation
 *    				in the string s. 
 *
 *        Version:  1.0
 *        Created:  2021年09月18日 19時14分19秒
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


void itob(int n, char *s, int base){

	int sign, index = 0;
	
	if((sign = n) < 0){
		n = -n;
	}

	do{
		if(n%base > 9){
			s[index++] = (n%base) - 10 + 'A';
		}else{
			s[index++] = (n%base) + '0';
		}
	}while(n/=base);

	if(sign < 0){
		s[index++] = '-';
	}

	reverse(s);
}





int main(int argc, char *argv[]){

	char str[100];
	memset(str, 0, sizeof(str));


	if(argc > 2){
		int base = atoi(argv[2]);
		printf("Converting...\n");
		itob(atoi(argv[1]), str, base);
		if(base == 16){
			printf("Result : 0x%s\n", str);
		}else{
			printf("Result : %s\n", str);
		}		
	}else{
		printf("Please enter the correct arguments.\n");
	}

	return 0;
}


