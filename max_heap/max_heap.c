#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "max_heap.h"

#define ALLOC_LENGTH 256
#define ROOT 0
#define PARENT (int)((i - 1) / 2)
#define LEFT_CHILD (int)(2 * i + 1)
#define RIGHT_CHILD (int)(2 * i + 2)

#define FAIL_IF(EXP,MSG)({if(EXP){printf(MSG "\n");exit(EXIT_FAILURE);}})
#define EXCHANGE(A,B)({A-=(B=(A+=B)-B);})


struct heap
{
    int size;
    int reserved_size;
    int *values;
};


void max_heapify(Heap *h, int i)
{
    FAIL_IF(i < ROOT || i >= h->size, "IndexError (max_heapify): index out of bounds");
    
    int max = (LEFT_CHILD < h->size) && (h->values[LEFT_CHILD] > h->values[i]) ? LEFT_CHILD : i;
    if (RIGHT_CHILD < h->size && h->values[RIGHT_CHILD] > h->values[max])
        max = RIGHT_CHILD;
    
    if (max != i)
    {
        EXCHANGE(h->values[max], h->values[i]);  // swap keys
        max_heapify(h, max);  // heapify until path obeys max-heap property
    }
}


Heap *heap_create(int a[], int length)
{
    Heap *h;

    FAIL_IF(!(h = malloc(sizeof(Heap))), "MallocFailure: could not allocate heap");
    h->size = length;
    h->reserved_size = ALLOC_LENGTH * (length / ALLOC_LENGTH + 1);
    FAIL_IF(!(h->values = malloc(sizeof(int) * h->reserved_size)), "MallocFailure: could not allocate heap array");

    memcpy(h->values, a, sizeof(int) * length);

    for (int i = (h->size - 1) / 2; i >= ROOT; --i)
        max_heapify(h, i);

    return h;
}


void Heapsort(int a[], int length)
{
    Heap *h = heap_create(a, length);
    
    for (int i = h->size - 1; i > ROOT; --i)
    {
        EXCHANGE(h->values[ROOT], h->values[i]);
        (h->size)--;
        max_heapify(h, ROOT);
    }

    memcpy(a, h->values, sizeof(int) * length);

    heap_delete(h);
}


int heap_get_size(Heap *h)
{
    return h->size;
}


int heap_get_max(Heap *h)
{
    return h->values[ROOT];
}


int heap_pop_max(Heap *h)
{
    int max_key = h->values[ROOT];
    EXCHANGE(h->values[ROOT], h->values[h->size - 1]);
    (h->size)--;
    max_heapify(h, ROOT);

    return max_key;
}


void heap_increase_key(Heap *h, int i, int key)
{
    FAIL_IF(i < ROOT || i >= h->size, "IndexError (heap_increase_key): index out of bounds");
    FAIL_IF(key < h->values[i], "ValueError (heap_increase_key): entered key has to be greater than current key");

    h->values[i] = key;

    while (i > ROOT && h->values[PARENT] < h->values[i])
    {
        EXCHANGE(h->values[PARENT], h->values[i]);
        i = PARENT;
    }
}


void heap_insert_key(Heap *h, int key)
{
    if (h->size >= h->reserved_size)
    {
        void *tmp;
        
        h->reserved_size += ALLOC_LENGTH;
        
        if ((tmp = realloc(h->values, sizeof(int) * h->reserved_size)))
            h->values = tmp;
        else
        {
            printf("ReallocFailure: could not allocate new heap size");
            exit(EXIT_FAILURE);
        }
    }

    (h->size)++;
    h->values[h->size - 1] = INT_MIN;
    heap_increase_key(h, h->size - 1, key);
}


void heap_delete(Heap *h)
{
    free(h->values);
    h->values = NULL;
    free(h);
    h = NULL;
}


void print_heap(Heap *h)
{
    for (int i = 0; i < h->size; ++i)
    {
        printf("Node %d: %d\n", i, h->values[i]);
        if (LEFT_CHILD < h->size)
            printf("Left child: %d\n", h->values[LEFT_CHILD]);
        if (RIGHT_CHILD < h->size)
            printf("Right child: %d\n", h->values[RIGHT_CHILD]);
        printf("\n");
    }
}

