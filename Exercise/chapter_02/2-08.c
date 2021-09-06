/*
 * =====================================================================================
 *
 *       Filename:  2-8.c
 *
 *    Description:  Return the value of the integer x rotated to the right by n bit
 *    				positions.
 *
 *        Version:  1.0
 *        Created:  2021年09月06日 22時38分45秒
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


#define INT_BIT ((sizeof(int)/sizeof(char)) * CHAR_BIT)



int rightrot(int x, int n){

	return x >> n | x << (INT_BIT - n);
}

int leftrot(int x, int n){

	return x << n | x >> (INT_BIT - n);
}



int main(int argc, char *argv[]){
    
	int result;
    printf("INT_BIT = %ld\n", INT_BIT);

	if(argc > 1){
		result = rightrot(atoi(argv[1]), atoi(argv[2]));
	    printf("This number x rotated to the right by n bit positions\n");
	    printf("result : %d\n", result);   	
	}else{
		printf("Please enter the correct arguments.\n");
	}

    return 0;
}

