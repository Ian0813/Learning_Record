/*
 * =====================================================================================
 *
 *       Filename:  3-1.c
 *
 *    Description:  binsearch(int x, int v[], int n)
 *    				Return the position if x occurs in v, and -1 if not.
 *    				Requirement : Only have one test condition in the loop.
 *
 *        Version:  1.0
 *        Created:  2021年09月09日 22時58分55秒
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
#include <time.h>
#include <sys/time.h>


void randomNum(int *v, int n){

	int temp;	
	v[0] = rand() % 1000;
	for(int i = 1; i < n; i++){
		v[i] = rand() % 1000;
		while((v[i] - v[i - 1] > 30) || (v[i] - v[i - 1]) < 0){
			v[i] = rand() % 1000;
		}
	}

	for(int i = 0; i < n; i++){
		printf("v[%d] %d ", i, v[i]);
	}
	putchar(10);
}

/*  binsearch : find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int *v, int n){

	int low, high, mid, flag;

	low = 0;
	high = n -1;
	mid = (low + high) / 2;
	flag = 0;

	while(low <= high && x != v[mid]){
		if(x < v[mid]){
			high = mid - 1;
		}else{
			low = mid + 1;	
		}
		mid = (low + high) / 2;
	}

	if(x == v[mid]){
		return mid;
	}else{
		return -1;
	}
}



int main(int argc, char *argv[]){
	
	int pos;
	struct timeval before, after;
	srand(time(NULL));

	if(argc > 2){
		int v[atoi(argv[2])];
		int size = atoi(argv[2]);
		gettimeofday(&before, NULL);
		randomNum(v, size);
		//gettimeofday(&before, NULL);
		pos = binsearch(atoi(argv[1]), v, size);
		gettimeofday(&after, NULL);
		printf("elapsed time : %ld\n", ((after.tv_sec * 1000) + (after.tv_usec / 1000)) - ((before.tv_sec * 1000) + (before.tv_usec / 1000)));
		if(pos != -1){
			printf("The position is %d\n", pos);
		}
	}else {
		printf("Please enter the correct arguments.\n");

	}

	return 0;

}

