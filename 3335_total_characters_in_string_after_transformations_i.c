/*
 * =====================================================================================
 *
 *       Filename:  3335_total_characters_in_string_after_transformations_i.c
 *
 *    Description:  total characters in string after transformations i
 *
 *       Compiler:  gcc (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
 *
 *         Author:  Ian
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define RETURN_MODULO(num) (int)((num)%1000000007)
#define ALPHABET_SIZE 26
#define CH_TO_INT(ch) ((ch)-'a')
#define INT_TO_CH(val) ((val)+'a')

#define ALPHABET_TRANSFORM(table, record, num, amount) \
if (INT_TO_CH(num) == 'z' ) {record[0] += RETURN_MODULO(amount); record[1] +=  RETURN_MODULO(amount); table[num] = 0;} \
else {record[num+1] = RETURN_MODULO(amount); table[num] = 0;}

static void count_occurrences(char *s, unsigned long int *counting) {

    for (int i = 0; i < strlen(s); i++) {
        counting[CH_TO_INT(s[i])]++;
    }
    return;
}

static unsigned long int transformation(unsigned long int *counting, unsigned long int *record, int t) {

    unsigned long int count = 0;

    for (int i = 0; i < t; i++) {
        for (int j = 0; j < ALPHABET_SIZE; j++) {
            if (counting[j]) {
                ALPHABET_TRANSFORM(counting, record, j, counting[j]);
            }
        }
        memcpy(counting, record, sizeof(unsigned long int) * ALPHABET_SIZE);
        memset(record, 0UL, sizeof(unsigned long int) * ALPHABET_SIZE);
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        count += counting[i];    
    }
    return count;
}    

int lengthAfterTransformations(char* s, int t) {

    unsigned long int counting[ALPHABET_SIZE] = {0UL}, record[ALPHABET_SIZE] = {0UL};
    unsigned long int result = 0UL; 

    count_occurrences(s, counting);

    result = transformation(counting, record, t);

    return RETURN_MODULO(result); 
}
