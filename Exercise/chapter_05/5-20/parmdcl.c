/*
 * =====================================================================================
 *
 *       Filename:  dcl.c
 *
 *    Description:  parse a declarator
 *
 *        Version:  1.0
 *        Created:  2022年04月01日 22時08分22秒
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
#include "dcl_parser.h"

/* parmdcl : parse a parameter declarator */
void parmdcl(void) {
	printf("[%s] entered.\n", __func__);
	do {
		dclspec();
	} while (tokentype == ',');

	if (tokentype != ')') {
		errmsg("missing ) in parameter declaration.\n");
	}
}


/* dclspec : declaration  */
void dclspec(void) {
	
	char temp[MAXTOKEN];

	memset(temp, 0, sizeof(char) * MAXTOKEN);
	temp[0] = '\0';
	printf("[%s] tokentype : %d\n", __func__, tokentype);
	gettoken();
	printf("[%s] tokentype : %d\n", __func__, tokentype);
	printf("[%s] token : %s\n", __func__, token);
	do {
		if (tokentype != NAME) {
			prevtoken = YES;
			dcl();
		} else if (typespec() == YES) {
			strcat(temp, " ");
			strcat(temp, token);
			printf("[%s] token : %s, %d\n", __func__, token, __LINE__);
			memset(token, 0, MAXTOKEN);
			gettoken();
		} else if (typequal() == YES) {
			strcat(temp, " ");	
			strcat(temp, token);
			memset(token, 0, MAXTOKEN);
			gettoken();
		} else {
			errmsg("unknown type in parameter list.  ");
		}
	} while (tokentype != ',' && tokentype != ')');
	strcat(out, temp);
#if 1	
	if (tokentype == ',') {
		strcat(out, ",");
	}
#endif
	return;
}

void *binary_search(void *key, void *base, long int amount, long int size, int (*comp)(const void *, const void *)) {

	void *temp[amount];
	char **str;

	memcpy(temp, base, sizeof(char *) * amount);
	memcpy(str, key, sizeof(char **));

	if (sizeof(key) != size || (*comp) == NULL) {
		printf("Invalid argument.\n");
		return NULL;
	}

	int index = amount/2, ret;
	while (index > -1 && index < amount) {
		printf("key : %s, temp[%d] : %s\n", *str, index, temp[index]);
		if ((ret = (*comp)(*str, temp[index])) == 0) {
			return temp[index]; 
		} else if (ret > 0) {
			index++;
		} else {
			index--; 
		}
	}

	return NULL;
}

/*  typespec : return YES if token is a type-specifier */
int typespec(void) {
	
	printf("[%s] entered.\n", __func__);
	static char *types[] = {
		"char",
		"int",
		"void"
	};
	char *pt = token;

	for (int i = 0; i < 3; i++) {
		if (strcmp(pt, types[i]) == 0) {
			printf("Matching, pt : %s, types : %s\n", pt, types[i]);
		}
	}

	printf("amount : %ld, size : %ld\n", sizeof(types)/sizeof(char *), sizeof(char *));

	if (bsearch(&pt, types, sizeof(types)/sizeof(char *), sizeof(char *), compare) == NULL) {
		printf("[%s] Not found.\n", __func__);
		return NO;
	} else {
		return YES;
	}
}


/*  typequal : return YES if token is a type-qualifier */
int typequal(void) {
	static char *typeq[] = {
		"const",
		"volatile"
	};

	char *pt = token;

	if (bsearch(&pt, typeq, sizeof(typeq)/sizeof(char *), sizeof(char *), compare) == NULL) {
		return NO;
	} else {
		return YES;
	}
}

/* compare : compare two strings for binary search */
int compare(const void *s1, const void *s2) {

	return strcmp((const char *)s1, (const char *)s2);
}
