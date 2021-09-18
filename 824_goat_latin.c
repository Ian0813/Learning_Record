/*
 * =====================================================================================
 *
 *       Filename:  824_goat_latin.c
 *
 *    Description:  Goat latin 
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
 *
 *         Author:  Ian
 * =====================================================================================
 */

/*
 * Example 1:
 *
 * Input: sentence = "I speak Goat Latin"
 *
 * Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
 *
 * Example 2:
 *
 * Input: sentence = "The quick brown fox jumped over the lazy dog"
 *
 * Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"*
 *          heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa
 *
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define APPEND(str) strcat(str, "a")

typedef unsigned int bool;
enum BOOL {false, true};

const char *vowels = "aeiouAEIOU";
const char *tail = "ma";

bool isvowel(char ch) {

    for (int i = 0; i < strlen(vowels); i++) {
        if (!(ch^vowels[i])) {
            return true;
		}	
	}
	return false;
}

void remake(char *str, int append, char *result) {

    fprintf(stdout, "[%s] %s, %ld\n", __func__, str, strlen(str));

    if (!isvowel(*str)) {
	    memcpy(result+strlen(result), str+1, strlen(str)-1);
		result[strlen(result)] = *str;
    } else {
        strcat(result, str);
	}
    strcat(result, tail);

	while (append) {
        APPEND(result);
		append--;
	}
	strcat(result, " ");

	return;
}

char* toGoatLatin(char* sentence) {

    char *result = (char *) malloc(BUFSIZ * sizeof(char));
	char *part = NULL;
	int append = 1;

	memset(result, 0, BUFSIZ * sizeof(char));

	part = strtok(sentence, " ");

	while (part != NULL) {
        remake(part, append, result);
		part = strtok(NULL, " ");
		append++;
	}
    result[strlen(result)-1] = '\0';

	return result;
}

 
int main(void) {

    char test_str[BUFSIZ] = "The quick brown fox jumped over the lazy dog";
	char *result = NULL;

	result = toGoatLatin(test_str);

    fprintf(stdout, "result:%s\n", result);
	free(result);

	return 0;
}

