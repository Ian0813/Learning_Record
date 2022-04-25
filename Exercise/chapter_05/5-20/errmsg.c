#include <stdlib.h>
#include <stdio.h>
#include "dcl_parser.h"
#include <unistd.h>

/*  errmsg : print error message and indicate available token  */
void errmsg(char *msg){
	printf("%s, %d\n", msg, tokentype);
	prevtoken = YES;
	sleep(1);
}
