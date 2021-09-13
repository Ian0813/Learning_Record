/*
 * =====================================================================================
 *
 *       Filename:  reverse.c
 *
 *    Description:  Reverse the string received. 
 *
 *        Version:  1.0
 *        Created:  2021年09月14日 01時02分30秒
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




int main(int argc, char *argv[]){

	int len, c;
	char *str;
	if(argc > 1){
		str = argv[1];
		printf("Before reverse : %s\n", str);
		len = strlen(str);
		for(int i = 0, j = len - 1; i < j; i++, j--){
			c = str[i];
			str[i] = str[j];
			str[j] = c;	
		}
		printf("After reverse  : %s\n", str);
	}

	return 0;
}

