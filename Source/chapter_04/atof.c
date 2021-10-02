/*
 * =====================================================================================
 *
 *       Filename:  atof.c
 *
 *    Description:  Convert a string s to its double-precision floatingpoint equivalent. 
 *
 *        Version:  1.0
 *        Created:  2021年09月29日 07時20分12秒
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

/* convert string s to double */
double atof2(char *s){
	
	double val, power;
	int i, sign;

	for(i = 0; isspace(s[i]); i++) /* skip white space */ 
			;

	sign = (s[i] == '-')? -1 : 1;

	if(s[i] == '+' || s[i] == '-'){
		i++;
	}

	for(val = 0.0; isdigit(s[i]); i++){
		val = 10 * val + (s[i] - '0'); 
	}
	if(s[i] == '.'){
		i++;
	}

	for(power = 1; isdigit(s[i]); i++){
		val = 10 * val + (s[i] - '0');
		power *= 10;
	}

	return sign * val / power;
}



int main(int argc, char *argv[]){

	
	if(argc > 1){
		printf("Thr convert result : %f\n", atof2(argv[1]));
	}

	return 0;

}






