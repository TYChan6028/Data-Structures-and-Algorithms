#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define FAIL_IF(EXP, MSG){if(EXP){fprintf(stderr,MSG"\n");exit(EXIT_FAILURE);}}

struct stack
{
    int *values;
    int top;
    int max_size;
};

Stack *stack_create(int max_stack_size)
{
    Stack *S;
    FAIL_IF(!(S = malloc(sizeof(Stack))), "Stack pointer malloc failure.");
    FAIL_IF(!(S->values = malloc(sizeof(int) * max_stack_size)), "Stack memory malloc failure.");
    S->top = -1;
    S->max_size = max_stack_size;

    return S;
}

void stack_delete(Stack *S)
{
    free(S->values);
    S->values = NULL;
    free(S);
    S = NULL;
}

bool stack_is_empty(Stack *S)
{
    return (S->top == -1);
}

int stack_push(Stack *S, int x)
{
    if (S->top == S->max_size - 1) return -1;

    S->values[++(S->top)] = x;
    
    return 0;
}
