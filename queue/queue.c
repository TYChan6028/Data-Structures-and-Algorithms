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
