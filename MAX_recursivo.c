#include<stdio.h>

#define MAX 100

int MAX_recursivo (int * v, int tam) {

	if (tam==0) 
		return v[tam];
	if (v[tam]>v[tam-1]) 
	{
		v[tam-1]=v[tam];
		return MAX_recursivo (v, tam-1);
	}
	else	
		return MAX_recursivo (v,tam-1);
}

void ler_vetor (int * v, int tam) {

	int i;
	
	for (i=0;i<tam;i++)
		scanf ("%d", &v[i]);
}

int main (void) {
	
	int vetor[MAX], tam, maior;
	
	scanf ("%d" , &tam);

	ler_vetor (vetor,tam);
	maior = MAX_recursivo (vetor,tam-1);

	printf ("O maior número do vetor é: %d", maior);
	printf ("\n");

	return 0;
}

	

