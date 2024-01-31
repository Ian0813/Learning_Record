/*
 * =====================================================================================
 *
 *       Filename:  150_evaluate_reverse_polish_notation.c
 *
 *    Description:  Evaluate reverse polish notation  
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
#include <ctype.h>

#define MAX 10001
#define CHECK_OPERATOR(op) strchr(operators, op)

typedef enum { false, true } bool;

static char operators[] = "*/+-";
static int stack[MAX];
int top = 0;

bool push(int val) {

    bool rc = false;

    if (top < MAX) {
        stack[top++] = val;
        rc = true;
    }
    return rc;
}

bool pop(int *val) {

    bool rc = false;

    if (top > 0) {
        *val = stack[--top];  
        rc = true;
    }
    return rc;
}

void get_value(int *n1, int *n2) {
    
    bool rc = false;
    rc = pop(n1);
    rc = pop(n2);

    return;
}

int convert_int(char *str) {

    int number = 0;
    int sign = 0;

    if (*str == '-') {
        sign = 1;    
    }

    for (int i = sign; i < strlen(str); i++) {
        number = number * 10 + (str[i]-48);
    }
    number = sign == 0 ? number : (-number); 
    fprintf(stdout, "[%s] %d\n", __func__, number);
    return number;
}

int calculation(char **expre, int size) {

    bool rc = false;
    int value = 0, num1 = 0, num2 = 0;
    int number = 0;

    for (int i = 0; i < size; i++) {
        if (isdigit(*expre[i]) || isdigit(*(expre[i]+1))) {
            number = convert_int(expre[i]);   
            rc = push(number); 
        } else if (CHECK_OPERATOR(*expre[i])) {
            switch (*expre[i]) {
                case '+': {
                    get_value(&num1, &num2);
                    value = num1 + num2;
                }
                break; 
                case '-': {
                    get_value(&num1, &num2);
                    value = (num2 - num1); 
                }
                break;
                case '*': {
                    get_value(&num1, &num2);
                    value = (num1 * num2); 
                }
                break;
                case '/': {
                    get_value(&num1, &num2);
                    value = (num2 / num1); 
                }
                break;
                default: 
                break;
            }
            push(value);
        }
    }
    pop(&value);
    return value;
}

int evalRPN(char** tokens, int tokensSize) {

    //char str[MAX] = {0};  
    //int index = 0;

    printf("size: %d\n", tokensSize);

    //for (int i = 0; i < tokensSize; i++) {
    //    str[index++] = *tokens[i];  
    //}
    //str[index] = '\0';
    //fprintf(stdout, "%s\n", str);

    return calculation(tokens, tokensSize);
}


int main(void) {

    char *tokens[] = {"2","1","+","3","*"};
    char *tokens2[] = {"4","13","5","/","+"};
    char *tokens3[] = {"3", "-4", "+"};
    int value = 0;

    value = evalRPN(tokens, sizeof(tokens)/sizeof(char *));

    printf("value: %d\n", value); 

    value = evalRPN(tokens2, sizeof(tokens2)/sizeof(char *));

    printf("value: %d\n", value); 

    value = evalRPN(tokens3, sizeof(tokens3)/sizeof(char *));

    printf("value: %d\n", value); 

    return EXIT_SUCCESS;
}

