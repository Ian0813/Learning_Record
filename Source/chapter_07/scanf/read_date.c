/*
 * =====================================================================================
 *
 *       Filename:  read_date.c
 *
 *    Description:  Read a date depending on the form of input. 
 *
 *        Version:  1.0
 *        Created:  2022年08月24日 22時53分14秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void main(void) {

    int day, year, month;
	size_t size = 0;
	char *str = NULL;
	char monthname[20] = {0};
		

    while (getline(&str, &size, stdin) != 1) {

		if (sscanf(str, "%d %s %d", &day, monthname, &year) == 3) {
			printf("valid: %d %s %d\n", day, monthname, year);	
		} else if (sscanf(str, "%d/%d/%d", &month, &day, &year) == 3) {
			printf("valid: %02d/%02d/%4d\n", month, day, year);
		} else {
            printf("invalid: %s\n", str);
		}
	}

	return;
}

