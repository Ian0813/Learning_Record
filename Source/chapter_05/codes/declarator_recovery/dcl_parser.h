#include <string.h>
extern int tokentype;           /* type of last token */
extern char token[];    /* last token string  */
extern char name[];     /*  identifier name   */
extern char datatype[]; /*  data type = int, char */
extern char out[];      /* ouput string */

#define MAXTOKEN 100
enum { NAME, PARENS, BRACKETS };


void dcl(void);
void dirdcl(void);
int gettoken(void);
int getch();
void ungetch(int);
