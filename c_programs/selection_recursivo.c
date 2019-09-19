#include<stdio.h>
#define MAX 100

void troca (int * v, int t, int m) {
	int aux;

	aux=v[t];
	v[t]=v[m];
	v[m]=aux;
}

void achamax (int *v, int t, int *m) {	
	if ( t >= 0 ) {
		if ( v[*m] < v[t] ) 
			*m=t;
		achamax (v,t-1,m);
	}	
}
void selection_sort (int *v, int t, int * m) {
	if (t>=1) {

		/*achando o maior*/
		*m=t;
		achamax (v,t-1,m);
		printf ("%d %d %d %d\n", *m, v[*m], t, v[t]);

		/*trocando*/
		troca (v,t,*m);

		selection_sort (v,t-1,m);
		 
	}
}	
void ler_vetor (int * v, int t) {

	int i;

	for (i=0;i<t;i++) 
		scanf ("%d", &v[i]);
}

void escrever_vetor (int * v, int t){

	int i;

	for (i=0; i<t; i++)
		printf ("%d ", v[i]);
	printf ("\n");

}	 
int main (void) {

	int vetor[MAX], tam, maior, max;

	scanf ("%d", &tam);

	ler_vetor (vetor,tam);
	max=tam-1;

	achamax (vetor,tam-2,&max);
	printf ("O posição do maior é: %d\n", max );
	
	selection_sort (vetor,tam-1,&max);

	escrever_vetor (vetor,tam);

	return 0;

}

	 
