#ifndef STACK_H
#define STACK_H


#include <stdbool.h>

typedef struct
{
    int *values;
    int top;
    int max_size;
} Stack;

Stack *stack_create(int max_stack_size);
void stack_delete(Stack *S);
bool stack_is_empty(Stack *S);
int stack_push(Stack *S, int x);
int *stack_pop(Stack *S);


#endif
