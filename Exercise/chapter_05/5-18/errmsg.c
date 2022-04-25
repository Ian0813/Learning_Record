#include <stdlib.h>
#include <stdio.h>
#include "dcl_parser.h"

/*  errmsg : print error message and indicate available token  */
void errmsg(char *msg){
	printf("%s", msg);
	prevtoken = YES;
}
