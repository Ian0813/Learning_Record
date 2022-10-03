/*
 * =====================================================================================
 *
 *       Filename:  miniprintf.c
 *
 *    Description:  minimal printfwith variable argumrnt list. 
 *
 *        Version:  1.0
 *        Created:  2022年08月22日 01時34分06秒
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
#include <stdarg.h>


int main(void) {

    void miniprintf(char *fmt, ...);

	char *str = "Hello, world.\n";

	miniprintf(str);

	return 0;
}


void miniprintf(char *fmt, ...) {

    va_list ap;    /* points to each unnamed arg in turn. */
	char *p, *sval;
	int ival;
	double dval;

	va_start(ap, fmt);    /* make ap point to 1st unnamed arg. */

	for (p = fmt; *p; p++) {
        
        if (*p != '%') {
            putchar(*p);
			continue;
		}

		switch(*++p) {
		    case 'd':
                ival = va_arg(ap, int);
				printf("%d", ival);
				break;
			case 'f':
				dval = va_arg(ap, double);
				printf("%f", dval);
				break;
			case 's':
				for (sval = va_arg(ap, char *); *sval; sval++) {
			        putchar(*sval);	
				}
				break;
			default:
				putchar(*p);
				break;
		}
	}
	
	va_end(ap);    /* cleanup when done. */

	return;
}

