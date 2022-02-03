/*
 * =====================================================================================
 *
 *       Filename:  str.c
 *
 *    Description:  A function collection implemented by pointer.
 *    				(reverse())  
 *
 *        Version:  1.0
 *        Created:  2021年12月03日 00時50分05秒
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


/* pointer version   */
void reverse_p(char *s){

	int len = strlen(s);
	char ch;
	char *s_end = s + (len - 1);

	while(s != s_end){
		ch = *s;
		*s = *s_end;
		*s_end = ch;	
		s++;
		s_end--;
	}
}

int atoi_p(char *str){

	int val = 0;

	while(*str){
		val *= 10 + (*str - '0');
		str++;
	}

	return val;
}

char *itoa_p(int *val){

	char *ptr = (char *) malloc(sizeof(char) * 100);
	char *result = ptr;

	while(*val > 0){
		*ptr = *val%10 + '0';
		*val/=10;
		ptr++;
	}

	reverse_p(result);

	return result;
}

int getline_p(char *s, int lim){
	
	int i;
	for(i = 0; i < lim - 1 && ((*s = getchar()) != EOF); i++, s++)
			;
	*s = '\0';
	return i;
}


char *str_index_p(char *s, char *t){

	char *ptr_s, *ptr_t;

	while(*s){
		ptr_s = s;
		ptr_t = t;

		while(*ptr_s == *ptr_t){
			ptr_s++;
			ptr_t++;
		}

		if(*ptr_t == '\0'){
			return s;	
		}
		s++;
	}
	return NULL;
}

int getop_p(char *s){

    int i, c, op;

    while((*s++ = c = getch()) == ' ' || c == '\t')
        ;

    *s = '\0';


    if(!isdigit(c) && c != '.' && c != '-'){
        return c; /* not a number */
    }


    if(isdigit(c) || c == '-'){  /*  collect integer part */
        while(isdigit(*s++ = c = getch()))
            ;
    }

    if(c == '.'){   /*  collect fraction part */
        while(isdigit(*s++ = c = getch()))
            ;
    }

    *s = '\0';

    if(c != EOF){
        ungetch(c);
    }

    return atoi(s);
}

