/*
 * =====================================================================================
 *
 *       Filename:  2-7.c
 *
 *    Description:  invert(x, p, n) - Returns x with the n bits that begin at position p 
 *    								  inverted.
 *
 *        Version:  1.0
 *        Created:  2021年09月03日 22時02分28秒
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


int invert(int x, int p, int n){

	int shift_num = (p + 1) - n;

	return x ^ (~(~0 << n) << shift_num);	
}


int main(int argc, char *argv[]){

	int result;

	if(argc > 3){
		printf("Inverting ...\n");
		result = invert(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
		printf("result : %d\n", result);
	}else {
		printf("Please enter the correct arguments.\n");
	}

	return 0;
}

