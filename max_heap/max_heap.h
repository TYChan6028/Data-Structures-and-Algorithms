#ifndef MAX_HEAP_H
#define MAX_HEAP_H

typedef struct heap Heap;

Heap *heap_create(int a[], int length);
void Heapsort(int a[], int length);
int heap_get_size(Heap *h);
int heap_get_max(Heap *h);
int heap_pop_max(Heap *h);
void heap_increase_key(Heap *h, int i, int key);
void heap_insert_key(Heap *h, int key);
void heap_delete(Heap *h);
void print_heap(Heap *h);

#endif
