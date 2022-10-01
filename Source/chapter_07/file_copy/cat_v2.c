/*
 * =====================================================================================
 *
 *       Filename:  cat_v2.c
 *
 *    Description:  Concatenate multiple files' contents, then print out them. 
 *
 *        Version:  1.0
 *        Created:  2022年10月01日 16時11分53秒
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

/* cat: concatenate files, version 2 */
int main(int argc, char *argv[]) {

    FILE *fp;
	void filecopy(FILE *, FILE *);
	char *prog = argv[0];    /* program name for errors */ 

	if (argc == 1) {
        filecopy(stdin, stdout);
	} else {
        while (--argc > 0) {
            if ((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "%s: can't open %s\n", prog, *argv);    
				exit(EXIT_FAILURE);
			} else {
                filecopy(fp, stdin);
				fclose(fp);
			}
		}
	}

	if (ferror(stdout)) {
        fprintf(stderr, "%s: error writing stdout.\n", prog);
		exit(EXIT_FAILURE);
	}
			
    exit(EXIT_SUCCESS);
}

