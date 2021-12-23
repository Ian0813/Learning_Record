/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  The function called main is used to call a sort of function outside.
 *
 *        Version:  1.0
 *        Created:  2021年12月21日 20時06分19秒
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

int day_of_year(int, int, int);

void month_day(int, int, int *, int *);

int main(int argc, char *argv[]){
	
	int days;
	int m, d; 

	printf("Conversion ...\n");

	printf("year : %d, month : %02d, day : %02d\n", atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));				
	
	printf("day_of_year : %d\n", day_of_year(atoi(argv[1]), atoi(argv[2]), atoi(argv[3])));

	days =  day_of_year(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));

	month_day(atoi(argv[1]), days, &m, &d);

	printf("year : %d, month : %02d, day : %02d\n", atoi(argv[1]), m, d);

	return 0;
}

