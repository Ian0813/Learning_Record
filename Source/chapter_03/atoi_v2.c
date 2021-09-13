/*
 * =====================================================================================
 *
 *       Filename:  atoi_v2.c
 *
 *    Description:  Converting a string to its numeric equivalent. 
 *
 *        Version:  1.0
 *        Created:  2021年09月12日 15時54分45秒
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
#include <ctype.h>

int atoi_v2(char *s){

	int i, n, sign;

	for(i = 0; isspace(s[i]); i++)
			;

	sign = (s[i] == '-')? -1 : 1;  
		
	if(s[i] == '-' || s[i] == '+'){
		i++;
	}

    for(n = 0; isdigit(s[i]); i++){
		n = 10 * n + (s[i] - '0');
	}

	return n;	
}




int main(int argc, char *argv[]){
	
	int result;

	if(argc > 1){
		printf("Converting...\n");
		result = atoi_v2(argv[1]);
		printf("result : %d\n", result);	
	}else {
		printf("Please enter the correct argument.\n");
	}


	return 0;
}





