/*
 * =====================================================================================
 *
 *       Filename:  atoi2.c
 *
 *    Description:  Implement the atoi function by atof
 *
 *        Version:  1.0
 *        Created:  2021年10月02日 14時09分19秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ian` 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>


int atoi2(char *str){

	return (int) atof(str);
}


int main(int argc, char *argv[]){
	
	if(argc > 1){
		printf("Number : %d\n", atoi2(argv[1]));
	}else{
		printf("Please enter the correct number.\n");
	}


	return 0;
}

