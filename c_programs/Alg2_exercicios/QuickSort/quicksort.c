#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000;
void gera_vetor (int *ent,int t){

	int i;
	srand (time(NULL));
	for (i=0,i<t,i++)
		ent[i]= rand () % MAX;


}
void imprimir_vetor (int *ent, int t) {
	
	int i;
	for (i=0;i<t;i++)
		printf ("%d ", ent[i]);
	printf ("\n");
}
void quicksort ()
int main () {

	int *entrada,tam;
	scanf ("%d", &tam);

	entrada=(int *)malloc(sizeof(int)*tam);

	gera_vetor (entrada,tam);
	
	quicksort (entrada,0,tam);
	
	imprimir_vetor (entrada,tam);	
}
