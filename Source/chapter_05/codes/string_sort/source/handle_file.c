/*
 * =====================================================================================
 *
 *       Filename:  handle_file.c
 *
 *    Description:  To handle a file.
 *
 *        Version:  1.0
 *        Created:  2021年12月16日 22時52分52秒
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
#include <errno.h>
#include <string.h>
#include <malloc.h>

#define MAX_LINES 5000 /* max #lines to be sorted. */
char *linesptr[MAX_LINES];
int line_index; 


void RetrieveLine(char *file_name){

	FILE *fp = NULL;
	size_t len = 0, nread;
	char *lines = NULL;

	fp = fopen(file_name, "r");
	if(fp == NULL){
		perror("fp ");
	}
	memset(linesptr, 0, sizeof(linesptr));

	while(1){

	    nread = getline(&lines, &len, fp);

	    if(nread == -1){
	    	free(lines);
			break;
	    	//perror("getline ");
	    	//exit(EXIT_FAILURE);
	    }
		//puts(lines);
		//printf("lines : %p\n", lines);
		linesptr[line_index] = lines;
		//printf("index %d : %s\n", line_index, linesptr[line_index]);
		line_index++;
		lines = NULL;
		len = 0;
	    //printf("Retrieved line of length : %ld\ntext : \n%s", nread, lines);

	}
	//printf("\n");

	//free(lines);
	fclose(fp);
}

void WriteToFile(char ch){

	FILE *fp = NULL;
	
	fp = fopen("texts.txt", "a");
	if(fp == NULL){
		perror("fopen ");
		exit(EXIT_FAILURE);
	}

	if(fputc(ch, fp) == -1){
		perror("fputc ");
		exit(1);//EXIT_FAILURE == 1 
	}
	
	fclose(fp);
}

void WriteOrderTexts(char *lines[], int number){

	FILE *fp = NULL;

	fp = fopen("./test/order.txt", "w");
	if(fp == NULL){
		perror("fopen ");
	}

	for(int i = 0; i < number; i++){
		fputs(lines[i], fp);
	}

	fclose(fp);
}

void PrintLines(int number){
	printf("[%s] number : %d\n", __func__, number);
	for(int i = 0; i < number; i++){
		if(linesptr[i] != NULL){
			printf("[%d] : %s\n", i, linesptr[i]);
		}
	}
	putchar(10);
}

void MemoryFreed(void){
	//printf("[%s] number : %d\n", __func__, number);
	for(int i = 0; i < MAX_LINES; i++){
		if(linesptr[i] != NULL){
			//printf("i : %d ", i);
			free(linesptr[i]);
			linesptr[i] = NULL;
		}	
	}
}


static void
display_mallinfo(void)
{
    struct mallinfo mi;

    mi = mallinfo();

    printf("Total non-mmapped bytes (arena):       %d\n", mi.arena);
    printf("# of free chunks (ordblks):            %d\n", mi.ordblks);
    printf("# of free fastbin blocks (smblks):     %d\n", mi.smblks);
    printf("# of mapped regions (hblks):           %d\n", mi.hblks);
    printf("Bytes in mapped regions (hblkhd):      %d\n", mi.hblkhd);
    printf("Max. total allocated space (usmblks):  %d\n", mi.usmblks);
    printf("Free bytes held in fastbins (fsmblks): %d\n", mi.fsmblks);
    printf("Total allocated space (uordblks):      %d\n", mi.uordblks);
    printf("Total free space (fordblks):           %d\n", mi.fordblks);
    printf("Topmost releasable block (keepcost):   %d\n", mi.keepcost);
}

#if 0

int main(int argc, char *argv[]){
    //FILE *fp;
	//char ch;
	//char read_bucket[10000] = {0};
	//int index = 0;

	//fp = fopen("lorem.txt", "r");


	//if(!fp){
	//    perror("fopen ");
	//	exit(EXIT_FAILURE);
	//}

	//while((ch = fgetc(fp)) != EOF){
	//		if(ch >= 65 && ch <= 90 || ch >= 97 && ch <= 122){
    //            //putchar(ch);
	//			WriteToFile(ch);
	//		}else if(ch == 32){
	//			//putchar(10);
	//			WriteToFile(10);
	//		}
	//}
	
    RetrieveLine(argv[1]);
	printf("Read %d lines from a file.\n", line_index);
	PrintLines(line_index);
	MemoryFreed();

#if 0 
	for(int i = 0; i < MAX_LINES; i++){
		if(linesptr[i] != NULL){
			printf("%d, linesptr : %p\n", i, linesptr[i]);
			free(linesptr[i]);
			linesptr[i] = NULL;
			printf("%d, linesptr : %p\n", i, linesptr[i]);
		}
	}
#endif

	return 0;	
}

#endif
