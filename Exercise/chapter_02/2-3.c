/*
 * =====================================================================================
 *
 *       Filename:  2-3.c
 *
 *    Description:  Convert a hexdecimal string to an integer 
 *
 *        Version:  1.0
 *        Created:  2021年08月30日 22時58分56秒
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


int htoi(char *hex_str){

	int total = 0, base = 1, convert_val = 0;

	for(int i = strlen(hex_str) - 1; hex_str[i] != 'x' && hex_str[i] != 'X' && i >= 0; i--){
		if(hex_str[i] >= 'A' && hex_str[i] <= 'F'){
			convert_val = hex_str[i] - 'A' + 10;
		}else if(hex_str[i] >= 'a' && hex_str[i] <= 'f'){
			convert_val = hex_str[i] - 'a' + 10;
		}else {
			convert_val = hex_str[i] - '0';
		}
		total += convert_val * base;
		base *= 16;		
	}

	return total;	

}


int main(int argc, char *argv[]){
	
	int num;

	if(argc > 1){
		printf("Converting...\n");
		num = htoi(argv[1]);
		printf("Result : %d\n", num);
	}else {
		printf("Please enter an correct argument.\n");
	}

}




