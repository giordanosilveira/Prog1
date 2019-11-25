#define MAX 100
#define RANGE 60
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct heap
{ 
    int heapsize;
    int array [100];
};
typedef struct heap t_heap; 

void buildarray (t_heap *heap) {

    int i;
    for (i = 0; i < heap->heapsize; i++)
        heap->array[i] = rand () % RANGE + 1;
}

int left (int n) {
    return 2*n + 2;
}

int right (int n) {
    return 2*n + 1;
}

void swap (int *a, int *b) {
    
    int aux;

    aux = *a;
    *a = *b;
    *b = aux;
} 
void max_heapfy (t_heap *heap, int n) {

    int l,r,largest;

    l = left (n);
    r = right (n);
    if (l < heap->heapsize && heap->array[l] > heap->array[n])
        largest = l;
    else largest = n;

    if (r < heap->heapsize && heap->array[r] > heap->array[largest])
        largest = r;

    if (largest != n ) {
        swap (&heap->array[n],&heap->array[largest]);
        max_heapfy (heap,largest); 
    }
}
void build_maxheap (t_heap *heap) {

    int i;
    for (i = heap->heapsize/2; i >= 0; i--)
        max_heapfy (heap,i);

}

void printarray (t_heap *heap, int n) {

    int i;

    for (i = 0; i < n; i++)
        printf ("%d ", heap->array[i]);
    printf ("\n");

}

void heapsort (t_heap *heap) {

    int i,k;

    k = heap->heapsize;
    for (i = k - 1; i >= 0; i--) {
        swap (&heap->array[0],&heap->array[i]);
        heap->heapsize--;
        max_heapfy (heap,0);
    }
    heap->heapsize = k;
}

int main () {

    t_heap heap;
    heap.heapsize = 40;

    srand (time(NULL));

    buildarray (&heap);
    printarray (&heap,heap.heapsize);

    build_maxheap (&heap);
    printarray (&heap,heap.heapsize);

    heapsort (&heap);
    printf ("Vetor ordenado -> ");
    printarray (&heap,heap.heapsize);

    return 0;
}