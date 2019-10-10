#include <stdio.h>
#define MAX 1000
void gera_vetor (int *e, int t) {
	
	int i;
	for (i=0;i<t;i++)
		e[i] = rand() % MAX;

}
void merge (int *e, int ini, int meio, int fim) {

	int tmp[fim-ini+1];
	int j,k,l;
	j=ini;
	k=meio+1;
	l=0;
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
void MergeSort (int *e, int i, int f) {

	int meio;
	meio = (i+f)/2;
	if (i<f) {
		MergeSort (e,i,meio);
		MergeSort (e,meio+1,f);
		merge (e,i,meio,f);
	}
}
void imprime_vetor (int *e,int tam) {
	
	int i;
	for (i=0;i<tam;i++)
		printf ("%d ", e[i]);
	printf ("\n");

}
int main (void) {

	int *entrada, tam;

	printf ("vector length\n");
	scanf ("%d", &tam);

	gera_vetor (entrada,tam);
	
	MergeSort (entrada,0,tam);

	imprime_vetor (entrada,tam); 

	return 0;
}
