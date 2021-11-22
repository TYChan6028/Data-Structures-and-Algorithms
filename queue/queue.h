#ifndef QUEUE_H
#define QUEUE_H


#include <stdbool.h>

typedef struct
{
    int *values;
    int front;
    int rear;
    int max_size;
} Queue;

Queue *queue_create(int max_queue_size);
void queue_delete(Queue *Q);
bool queue_is_empty(Queue *Q);
int enqueue(Queue *Q, int x);


#endif
