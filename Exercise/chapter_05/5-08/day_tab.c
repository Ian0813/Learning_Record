/*
 * =====================================================================================
 *
 *       Filename:  day_tab.c
 *
 *    Description:  a table of calendar info.
 *                  Add an error handler to correct the behavior of the function.
 *
 *        Version:  1.0
 *        Created:  2021年12月21日 00時59分55秒
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

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year : set day of year from month & day */
int day_of_year(int year, int month, int day){
	
	int i, leap;
	
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	for(i = 1; i < month && i < 13; i++){
		day += daytab[leap][i];
	}

	if(i == 13){
		printf("Invalid parameter !!!\n");
		exit(EXIT_FAILURE);
	}

	return day;
}

/* month_day : set month & day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday){

	int i, leap;

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

	for(i = 1; yearday > daytab[leap][i] && i < 13; i++){
		yearday -= daytab[leap][i];
	}

	if(i == 13){
		printf("Invalid parameter !!!\n");
		exit(EXIT_FAILURE);
	}

	*pmonth = i;
	*pday = yearday;
}

/* month-name : return n of the n-th month. */
char *month_name(int n){


	static char *name[] = {"Illegal month", "January", "February", "March", "April", 
						 "May", "June", "July", "August", "September", "October", 
						 "November", "December"};
	return (n < 1 || n > 12) ? name[0] : name[n];
}

