#include "queue.h"
#include "unity.h"

#define QUEUE_SIZE 4

static Queue *Q;
static int arr[] = {1, 2, 3};

void setUp(void)
{
    Q = queue_create(QUEUE_SIZE);
}

void tearDown(void)
{
    queue_delete(Q);
}

void test_queue_is_empty(void)
{
    TEST_ASSERT(queue_is_empty(Q));
    TEST_ASSERT_EQUAL_INT(3, Q->front);
    TEST_ASSERT_EQUAL_INT(3, Q->rear);
}

void test_enqueue(void)
{
    TEST_ASSERT_EQUAL_INT(0, enqueue(Q, arr[0]));
    TEST_ASSERT_EQUAL_INT_ARRAY(arr, Q->values, 1);
    TEST_ASSERT_EQUAL_INT(3, Q->front);
    TEST_ASSERT_EQUAL_INT(0, Q->rear);
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_queue_is_empty);
    RUN_TEST(test_enqueue);

    return UNITY_END();
}
