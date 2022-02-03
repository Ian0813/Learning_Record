/*
 * =====================================================================================
 *
 *       Filename:  strlen_by_array.c
 *
 *    Description:  Compute a length of a string by an array parameter 
 *
 *        Version:  1.0
 *        Created:  2021年11月27日 22時36分13秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>


int strlenByArray(char *s){

	int n;

	for(n = 0; *s != '\0'; s++){
		n++;
	}

	return n;

}



int main(int argc, char *argv[]){


	if(argc < 2){
		puts("Please enter a string to comput its length.\n");
	}else{
		printf("The string : %s\n", argv[1]);
		printf("The string length : %d\n", strlenByArray(argv[1]));
	}

	
	return 0;
}

