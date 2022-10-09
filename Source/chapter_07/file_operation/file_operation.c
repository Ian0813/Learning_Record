/*
 * =====================================================================================
 *
 *       Filename:  file_operation.c
 *
 *    Description:  The basic operations on a specific file.
 *
 *        Version:  1.0
 *        Created:  2022年10月08日 02時17分56秒
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

/* ex_fgets: get at most n - 1 chars from iop */
char *ex_fgets(char *s, int n, FILE *iop) {

    register int c;
	register char *cs;

	cs = s;
	while (--n > 0 && (c = getc(iop)) != EOF) {
        if ((*cs++ = c) == '\n') {
            break;        
		}
	}
	*cs = '\0';
	printf("c: %d\n", c);
	return (c == EOF && cs == s) ? NULL : s;
}

/* ex_fputs: put string s on file iop */
int ex_fputs(char *s, FILE *iop) {

    int c;

    while (c = *s++) {
        putc(c, iop);
	}
	return ferror(iop) ? EOF : 0;
}

/* ex_getline: read a line return length */
int ex_getline(char *line, int max) {

    if (ex_fgets(line, max, stdin) == NULL) {
        return 0;
	}

	return strlen(line);
}	
