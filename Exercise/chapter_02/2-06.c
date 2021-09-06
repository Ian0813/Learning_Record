/*
 * =====================================================================================
 *
 *       Filename:  2-6.c
 *
 *    Description:  Function setbits(x, p, n, y)
 *    			 	Returns x with the n bits that begin at position p set to the 
 *    			 	rightmost n bits of y, leaving the other bits unchanged. 	
 *
 *        Version:  1.0
 *        Created:  2021年09月
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

int setbits(int x, int p, int n, int y){

/* obsolete 
 
	int shift_num = p + 1 - n;
	int compute_result = ((((~(~0 << n)) & y) << shift_num));
	int operand = INT_MAX - compute_result; 

	if( shift_num > 0 ){
		printf("Second shift\n");
		printf("compute_rsult : %u\n", compute_result);
		compute_result |= (~(~0 << shift_num )); 
	}
	printf("compute_rsult : %d\n", compute_result);

*/

	int invert_bits;
	int shift_num = p + 1 - n;
	int op;

	// Invert the selected bits of x.
	invert_bits = ( ~(~0 << n) << shift_num) ^ x;
	
	// Just take n bits at the rightmost bits of y then place to position p.
	op = ( ( ~(~0 << n) & y) << shift_num ) | ( ~0 << p + 1);

	if(shift_num > 0){
		op |= ( ~(~0 << shift_num) );
	}

	return (x | invert_bits) & op;

}




int main(int argc, char *argv[]){
	
	int result;
	if(argc > 4){
		result = setbits(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]));
		printf("Result : %d\n", result);
	}else{
		printf("Please enter the correct arguments.\n");
	}

	return 0;
}



