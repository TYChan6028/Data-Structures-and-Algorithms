#ifndef STACK_H
#define STACK_H

typedef struct stack Stack;

Stack *stack_create(int max_stack_size);
void stack_delete(Stack *S);


#endif
