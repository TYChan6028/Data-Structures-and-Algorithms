#include "stack.h"
#include "unity.h"

#define STACK_SIZE 3

static Stack *S;
static int arr[] = {1, 2, 3};

void fill_stack(Stack *S)
{
    for (int i = 0; i < STACK_SIZE; ++i)
    {
        stack_push(S, arr[i]);
    }
}

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
    TEST_ASSERT(stack_is_empty(S));
    TEST_ASSERT_EQUAL_INT(-1, S->top);
}

void test_stack_is_full(void)
{
    fill_stack(S);
    TEST_ASSERT(stack_is_full(S));
    TEST_ASSERT_EQUAL_INT(STACK_SIZE - 1, S->top);
}

void test_stack_push(void)
{
    for (int i = 0; i < STACK_SIZE; ++i)
    {
        TEST_ASSERT_EQUAL_INT(0, stack_push(S, arr[i]));
        TEST_ASSERT_EQUAL_INT(i, S->top);
    }
    TEST_ASSERT_EQUAL_INT_ARRAY(arr, S->values, STACK_SIZE);
}

void test_stack_push_to_full(void)
{
    TEST_IGNORE();
}

void test_stack_pop(void)
{
    fill_stack(S);
    for (int i = STACK_SIZE - 1; i >= 0; --i)
    {
        TEST_ASSERT_EQUAL_INT(arr[i], *(stack_pop(S)));
        TEST_ASSERT_EQUAL_INT(i - 1, S->top);
    }
}

void test_stack_pop_from_empty(void)
{
    TEST_IGNORE();
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_stack_is_empty);
    RUN_TEST(test_stack_push);
    RUN_TEST(test_stack_is_full);
    RUN_TEST(test_stack_push_to_full);
    RUN_TEST(test_stack_pop);
    RUN_TEST(test_stack_pop_from_empty);

    return UNITY_END();
}
