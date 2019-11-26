#define MAX 100
#define RANGE 1000
#include <stdio.h>
#include <stdlib.h>

void buildarray (int *array, int n) {

    int i;
    for (i = 0; i < n; i++)
        array[i] = rand () % RANGE + 1;
}

void printarray (int *array, int n) {

    int i;

    for (i = 0; i < n; i++)
        printf ("%d ", array[i]);
    printf ("\n");

}

int findMAX (int *array, int n) {

    int i, max = -1;

    for (i = 0; i < MAX; i++) {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}
void counting_sort (int *A, int n, int exp) {

    int count[10], output[MAX], i;

    for (i = 0; i < 10; i++)
        count[i] = 0;

    for (i = 0; i < n; i++) 
        count[A[i]/exp % 10] = count[A[i]/exp % 10] + 1;

    for (i = 1; i < 10; i++) {
        count[i] = count[i] + count[i - 1];
    }

    for (i = MAX - 1; i >= 0; i--) {
        count[A[i]/exp % 10] = count[A[i]/exp % 10] - 1;
        output[count[A[i]/exp % 10]] = A[i];
    }

    for (i = 0; i < MAX; i++)
        A[i] = output[i];
    
}
void radix_sort (int *A, int n) {

    int max,exp;
    
    max=findMAX (A,n);

    for (exp = 1; max/exp > 0; exp *=10)
        counting_sort (A,n,exp);

}
int main () {

    int n=100;
    int *A;
    
    A = (int *)malloc(sizeof(int)*n);
    
    buildarray (A,n);
    printarray (A,n);

    radix_sort (A,n);
    printarray (A,n);

    return 0;
}