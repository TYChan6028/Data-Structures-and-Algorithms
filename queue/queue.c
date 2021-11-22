#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define FAIL_IF(EXP,MSG){if(EXP){fprintf(stderr,MSG"\n");exit(EXIT_FAILURE);}}

Queue *queue_create(int max_queue_size)
{
    Queue *Q;
    FAIL_IF(!(Q = malloc(sizeof(Q))), "Queue pointer malloc failure.");

    FAIL_IF(!(Q->values = malloc(sizeof(int) * max_queue_size)), "Queue memory malloc failure.");
    Q->front = Q->rear = max_queue_size - 1;
    Q->max_size = max_queue_size;

    return Q;
}

void queue_delete(Queue *Q)
{
    free(Q->values);
    Q->values = NULL;
    free(Q);
    Q = NULL;
}

bool queue_is_empty(Queue *Q)
{
    return (Q->front == Q->rear);
}

int enqueue(Queue *Q, int x)
{
    int new_rear = (Q->rear + 1) % Q->max_size; 
    if (Q->front == new_rear) return -1;

    Q->values[Q->rear = new_rear] = x;

    return 0;
}
