/*
 * =====================================================================================
 *
 *       Filename:  convert.c
 *
 *    Description:  This program purposefully converts the uppercase to lowercase or 
 *                  lowercase to upper, depending on what argument has passed. 
 *
 *        Version:  1.0
 *        Created:  2022年08月14日 16時49分01秒
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
#include <ctype.h>


/* lower: converts upper case to lower case */
/* upper: converts lower case to upper case */
void main(int argc, char *argv[]) {

    int c;

	if (strcmp(argv[0], "lower") == 0) {
		while ((c = getchar()) != EOF) {
			putchar(tolower(c));
		}
	} else {
		while ((c = getchar()) != EOF) {
			putchar(toupper(c));
		}
	}

    return;	 
}

