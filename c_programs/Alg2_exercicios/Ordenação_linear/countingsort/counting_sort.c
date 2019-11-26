#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define RANGE 60

void buildarray (int *array) {

    int i;
    for (i = 0; i < MAX; i++)
        array[i] = rand () % RANGE + 1;
}

void printarray (int *array) {

    int i;

    for (i = 0; i < MAX; i++)
        printf ("%d ", array[i]);
    printf ("\n");

}

int findMAX (int *array) {

    int i, max = -1;

    for (i = 0; i < MAX; i++) {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}
void counting_sort (int *array, int k) {

    int c[k], b[MAX], i;

    for (i = 0; i <= k; i++)
        c[i] = 0;

    for (i = 0; i < MAX; i++) 
        c[array[i]] = c[array[i]] + 1;

    for (i = 1; i <= k; i++) {
        c[i] = c[i] + c[i - 1];
    }

    for (i = MAX - 1; i >= 0; i--) {
        c[array[i]] = c[array[i]] - 1;
        b[c[array[i]]] = array[i];
    }

    for (i = 0; i < MAX; i++)
        array[i] = b[i];
    
}
int main () {

    int array[MAX];
    int k;

    srand(time(NULL));

    buildarray (array);
    printarray (array);

    k = findMAX (array);

    counting_sort (array,k);

    printarray (array);

    return 0;
}
