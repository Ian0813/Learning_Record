/*
 * =====================================================================================
 *
 *       Filename:  calculator.c
 *
 *    Description:  implement a primitive calculator by c
 *
 *        Version:  1.0
 *        Created:  2021年10月02日 12時14分41秒
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

#define READ_NUMBER 100


int main(){


	ssize_t size = READ_NUMBER ;
	char str[READ_NUMBER] = {0}, *num;
	int sum = 0;


	while(getline(&num, &size, stdin) != -1){
		strcpy(str, num);
	    printf("str : %s", str);
		sum += (int) atof(str);
	}

	printf("Sum : %d\n", sum);

	free(num);

	return 0;
}

