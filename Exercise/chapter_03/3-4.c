/*
 * =====================================================================================
 *
 *       Filename:  3-4.c
 *
 *    Description:  Handle the largest negative number when converting an integer to a string.
 *
 *        Version:  1.0
 *        Created:  2021年09月18日 00時13分21秒
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
#include <limits.h> 
#include <string.h>

void reverse(char *str);


void itoa_v2(int n, char *str){

	int sign, index = 0, key_value = 1;

	if((sign = n) < 0){
		n = ~n;
	}

	do{
		if(sign < 0){
			if((n%10) + key_value == 10){
				str[index++] = (n%10) + '0';  	
			}else{
				str[index++] = (n%10) + '0' + key_value;
				key_value = 0;
			}	
		}else{
			str[index++] = (n%10) + '0';
		}
		
	}while(n /= 10);

	if(sign < 0){
		str[index++] = '-';
	}

	reverse(str);
}


void reverse(char *str){

	int len = strlen(str) - 1;
	int ch;

	for(int i = 0; i < len; i++, len--){
		
		ch = str[len];
		str[len] = str[i];
		str[i] = ch; 
	}
}


int main(int argc, char *argv[]){

	int num;
	char str[100];
	memset(str, 0, sizeof(str));

	printf("Please enter a value for conversion to a string.\n");
	scanf("%d", &num);
	//num = INT_MIN;	

	itoa_v2(num, str);
	printf("str : %s\n", str);

	
	return 0;
}

