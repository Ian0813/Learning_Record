/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  The main function tests function in a specific order. 
 *
 *        Version:  1.0
 *        Created:  2021年12月19日 21時11分42秒
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
#include "string_sort.h"

//#define FILE_NAMES "../test/texts.txt"

extern int line_index;
extern char *linesptr[5000];


int main(int argc, char *argv[]){

	RetrieveLine(argv[1]);

	PrintLines(line_index);
	QuickSortString(linesptr, 0, line_index - 1);
	PrintLines(line_index);
	WriteOrderTexts(linesptr, line_index);
	MemoryFreed();

	return 0;
}
