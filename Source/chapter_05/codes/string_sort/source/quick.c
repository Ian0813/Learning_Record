/*
 * =====================================================================================
 *
 *       Filename:  quick.c
 *
 *    Description:  Quick sort
 *
 *        Version:  1.0
 *        Created:  2021年12月16日 23時39分26秒
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

void swap(char *[], int, int);
/*   
void QuickSort(int *val, int head, int end){

	if(head < end){
		//  sign : Use to mark a location which must exchange with the head value after a round. 
		int sign = head, op = head + 1;

		while(op <= end){

			if(val[op] < val[head]){
				sign++;
				swap(&val[sign], &val[op], sizeof(int));
		    }
			op++;
		}

		swap(&val[head], &val[sign], sizeof(int));
		QuickSort(val, head, sign - 1);
		QuickSort(val, sign + 1, end);
	}

}
*/
void QuickSortString(char *lines[], int head, int end){

	if(head < end){

		int sign = head, op = head + 1;

		while(op <= end){
			
			if(strcmp(lines[head], lines[op]) > 0){
				//printf("%s\n", lines[op]);
				sign++;
				swap(lines, sign, op);
			}
			op++;
		}

		swap(lines, head, sign);
		QuickSortString(lines, head, sign - 1);
		QuickSortString(lines, sign + 1, end);
	}
}

void swap(char *line[], int loc1, int loc2){


	char *temporary;
	temporary = line[loc1];
	line[loc1] = line[loc2];
	line[loc2] = temporary;

/*  
	if(sizeof(char) == type){
		char *c;
		char *t1 = (char *) a,*t2 = (char *) b; 
		printf("before :t1 : %s, t2 : %s\n", t1, t2);

		c = t1;
		t1 = t2;
    	t2 = c;
		printf("t1 : %s, t2 : %s\n", t1, t2);
	}else{
		int c;
		int *t1 = (int *) a, *t2 = (int *) b;
		c = *t1;
		*t1 = *t2;
		*t2 = c;
	}
*/

}
