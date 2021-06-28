#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main(void)
{
    int a[] = {5, 3, 6, 8, 2, 4, 7, 1, 10, 9};

    Heap *h = heap_create(a, 10);
    print_heap(h);

    Heapsort(a, 10);
    for (int i=0; i<10; ++i)
        printf("%d ", a[i]);
    printf("\n");

    printf("heap size: %d\n", heap_get_size(h));

    printf("max key: %d\n", heap_get_max(h));

    printf("extract max key: %d\n", heap_pop_max(h));
    printf("heap size: %d\n", heap_get_size(h));

    heap_increase_key(h, 8, 11);
    print_heap(h);

    heap_insert_key(h, 10);
    printf("heap size: %d\n", heap_get_size(h));
    print_heap(h);
}
