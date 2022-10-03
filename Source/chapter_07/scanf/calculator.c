/*
 * =====================================================================================
 *
 *       Filename:  calculator.c
 *
 *    Description:  rudimentary calculator
 *
 *        Version:  1.0
 *        Created:  2022年08月24日 01時48分43秒
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

void main(void) {

    double sum, v;

	sum = 0;

	while (scanf("%lf", &v) == 1) {
        printf("\t%.2f\n", sum += v);
	}
	return ;
}

