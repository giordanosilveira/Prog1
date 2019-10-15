#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000
void gera_vetor (int *e, int t) {
	
	int i;
	srand (time(NULL));
	for (i=0;i<t;i++)
		e[i] = rand() % MAX;

}
void merge (int *e, int *tmp, int ini, int meio, int fim) {

	int j,k,l;
	j=ini;
	k=meio+1;
	l=0;
	if (e[meio]>e[meio+1]) {
		while (j<=meio && k<=fim) {
			if (e[j] <= e[k]) {
				tmp[l]=e[j];
				j++; l++;
			}
			else {
				tmp[l]=e[k];
				k++; l++;
			}
		}
		while (j<=meio) {
			tmp[l]=e[j];
			j++; l++;
		}
		while (k<=fim) {
			tmp[l]=e[k];
			k++; l++;
		}
		for (l=ini;l<=fim;l++)
			e[l] = tmp[l-ini];
	}
}
void MergeSort (int *e, int *t,int i, int f) {

	int meio;
	meio = (i+f)/2;
	if (i<f) {
		MergeSort (e,t,i,meio);
		MergeSort (e,t,meio+1,f);
		merge (e,t,i,meio,f);
	}
}
void imprime_vetor (int *e,int tam) {
	
	int i;
	for (i=0;i<tam;i++)
		printf ("%d ", e[i]);
	printf ("\n");

}
int main (void) {

	int *entrada,*temporario, tam;

	printf ("vector length\n");
	scanf ("%d", &tam);
	
	entrada=(int *)malloc(sizeof(int)*tam);
	temporario=(int *)malloc(sizeof(int)*tam);

	gera_vetor (entrada,tam);
	
	MergeSort (entrada,temporario,0,tam);

	imprime_vetor (entrada,tam); 

	return 0;
}
