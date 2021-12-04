/*
 * =====================================================================================
 *
 *       Filename:  alloc.c
 *
 *    Description:  Use alloc() and afree() to implement a rudimentary storage allocator. 
 *
 *        Version:  1.0
 *        Created:  2021年11月28日 12時56分01秒
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


#define ALLOCSIZE 10000 /* size of avaliable space */

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf;  /* next free partiton */


char *alloc(int n){

	if(allocbuf + ALLOCSIZE - allocp >= n){
		allocp += n;
		return allocp - n;
	}else{
		return 0; /*  not enough room */
	}
}


/*  free storage pointed to by p */
void afree(char *p){

	if(p >= allocbuf && p < allocbuf + ALLOCSIZE){
		allocp = p;
	}

}


