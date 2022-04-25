
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dcl_parser.h"

/* nexttoken : get the next token and push it back */
int nexttoken(void) {
	int type;

	type = gettoken();
	prevtoken = YES;
	return type;	
}
