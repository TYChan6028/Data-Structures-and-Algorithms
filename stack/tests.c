#include "stack.h"
#include "unity.h"

#define STACK_SIZE 3

Stack *S;

void setUp(void)
{
    S = stack_create(STACK_SIZE);
}

void tearDown(void)
{
    stack_delete(S);
}

void test_stack_is_empty(void)
{
    TEST_IGNORE();
}

void test_stack_is_full(void)
{
    TEST_IGNORE();
}

void test_stack_push(void)
{
    TEST_IGNORE();
}

void test_stack_push_to_full(void)
{
    TEST_IGNORE();
}

void test_stack_pop(void)
{
    TEST_IGNORE();
}

void test_stack_pop_from_empty(void)
{
    TEST_IGNORE();
}
