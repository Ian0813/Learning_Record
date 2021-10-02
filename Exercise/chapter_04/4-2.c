/*
 * =====================================================================================
 *
 *       Filename:  4-2.c
 *
 *    Description:  Extend atof to handle scientific of thr form e.g. 123.45e-6
 *
 *        Version:  1.0
 *        Created:  2021年10月02日 15時10分57秒
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
#include <string.h>

/* convert string s to double */
double atof2(char *s){
	
	double val, power;
	int i = 0, sign, position = 0, ch, offset = 0, move_sign;
	int len = strlen(s);
	//printf("%d\n", len);

	for(int i = 0; i < len; i++){
		if(s[i] == 'e' || s[i] == 'E'){
			position = i;
			break;
		}
	}
	
	//printf("position : %d\n", position);
	move_sign = (s[position + 1] == '-') ? -1 : 1 ;

	for(int i = position + 2, mul = 1; isdigit(s[i]); i++, mul *= 10){
		offset *= mul;
		offset += (s[i] - '0'); 
	}

	for(int i = position; i < len; i++){
		s[i] = '\0';
	}
	
	//printf("%s\n", s);
	//printf("i : %d\n", i);
	
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
		//printf("s[%d] : %c\n", i, s[i]);
		power *= 10;
	}

	//printf("offset : %d, move_sign : %d, power : %f\n", offset, move_sign, power);

	if(move_sign == 1){
		for(int x = 1; x <= offset; power /= 10.0, x++)
			;	
	}else{
		for(int x = 1; x <= offset; power *= 10.0, x++)
			;
	}

	//printf("power : %f\n", power);

	return sign * val / power;
}



int main(int argc, char *argv[]){

	
	if(argc > 1){
		printf("Thr convert result : %lf\n", atof2(argv[1]));
	}

	return 0;

}






