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

int main(void)
{
    UNITY_BEGIN();
    return UNITY_END();
}
