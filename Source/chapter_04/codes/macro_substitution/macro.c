/*
 * =====================================================================================
 *
 *       Filename:  macro.c
 *
 *    Description:  macro substitution
 *
 *        Version:  1.0
 *        Created:  2021年11月16日 16時27分00秒
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


/*
 * notation use
 *
 * # : the pound sign can use in a macro function to expand a passed argument into a quoted string.
 *
 * ## : the double pound signs provides a way to cancatenate actual argument during macro expansion. 
 * 
 */


#define exp_1(x, y) printf("Test # : " #x " - " #y " = %d\n", x - y)
#define exp_2(x, y) printf("Test ## : "#x " ## " #y " = %d\n", x ## y)
#define swap(t, x, y) { t val; val = x; x = y; y = val;} 


int main(void){

	int x = 2, y = 3;

	printf("before swap...\n");
	exp_1(x, y);
	exp_2(2, 3);
	swap(int, x, y);	
	printf("After swap...\n");
	exp_1(x, y);

	return 0;

}


