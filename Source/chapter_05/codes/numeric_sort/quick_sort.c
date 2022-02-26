#include <stdio.h>


void swap(char *lineptr[], int i1, int i2){
	
	char *p = lineptr[i1];

	lineptr[i1] = lineptr[i2];
	lineptr[i2] = p;	
}

void quick_sort(char *lineptr[], int left, int right, int (*comp)(void *, void *)){

	int last;

	if(left >= right){
		return;
	}

	last = left;

	for(int i = left; i <= right; i++){
		if(comp(lineptr[i], lineptr[left]) < 0){
			swap(lineptr, ++last, i);
		}
	}
	
	swap(lineptr, left, last);
	quick_sort(lineptr, left, last - 1, comp);
	quick_sort(lineptr, last + 1, right, comp);

	return;
}
