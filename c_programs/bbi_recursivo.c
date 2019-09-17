#include<stdio.h>
#define MAX 100

int bbi_recursivo (int x, int * v, int ini, int tam)
{
	if (x==v[(ini+tam)/2])
		return (ini+tam)/2+1;
	if (ini>=tam)
		return 0;
	if (x>v[(ini+tam)/2])
		return bbi_recursivo (x,v,ini=(ini+tam)/2 +1,tam);
	else
		return bbi_recursivo (x,v,ini,tam=(ini+tam)/2 -1);
}

void ler_vetor (int *v,int tam)
{
	int i=0;
	for (i=0; i<tam; i++)
		scanf ("%d", &v[i]);
}

int main (void)
{
	int vetor[MAX], tam, x, i, achou;
	
	scanf ("%d" "%d", &tam, &x);
	ler_vetor (vetor,tam);

	for (i=0; i<tam; i++)
		printf ("%d ", vetor[i]);

	achou=bbi_recursivo (x,vetor,0,tam-1);
	if (achou == 0)
		printf ("Não existe esse número no vetor\n");
	else
		printf ("O número esta na posição %d do vetor\n", achou);
	return 0;
}
