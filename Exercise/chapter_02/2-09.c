/*
 * =====================================================================================
 *
 *       Filename:  2-9.c
 *
 *    Description:  A faster version of bitcount, using x &= (x - 1).
 *
 *        Version:  1.0
 *        Created:  2021年09月05日 22時38分44秒
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


// Reason : 

int bitcount(unsigned int x){

	int count;

	for(count = 0; x != 0; x &= (x - 1), count++);

	return count;
}


int main(int argc, char *argv[]){

	int result; 
    if(argc > 1){
    	result = bitcount(atoi(argv[1]));	
		printf("This number has %d bits of 1.\n", result);
	}else{
		printf("Please enter the correct argument.\n");
	}

	return 0;

}
