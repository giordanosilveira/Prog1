#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100000;
void gera_vetor (int *ent,int t){

	int i;
	srand (time(NULL));
	for (i=0;i<t;i++)
		ent[i]= rand () % MAX;


}
void imprimir_vetor (int *ent, int t) {
	
	int i;
	for (i=0;i<t;i++)
		printf ("%d ", ent[i]);
	printf ("\n");
}
void troca (int *a, int *b){

	int aux;
	aux=*a;
	*a=*b;
	*b=aux;
}
int particiona (int *ent, int ini, int fim) {
/*particiona pivo inicio*/
	
	int i,j,pivo;
	i=ini+1;
	j=ini;
	pivo=ent[(ini+fim)/2];
	troca (&pivo,&ent[ini]);
	for (i = ini+1; i <= fim; i++){
		if (ent[i]<pivo) {
			troca (&ent[i],&ent[j]);
			j++;
		}
	}
	troca (&pivo,&ent[j]);
	return j;
}
void quicksort (int *ent, int ini, int fim) {

	int pivo;
	if (ini<fim) {
		pivo=particiona(ent,ini,fim);
		quicksort (ent,ini,pivo-1);
		quicksort (ent,pivo+1,fim);
	}
}
int main () {

	int *entrada,tam;
	scanf ("%d", &tam);

	entrada=(int *)malloc(sizeof(int)*tam);

	gera_vetor (entrada,tam);
	
	quicksort (entrada,0,tam);
	
	imprimir_vetor (entrada,tam);	
	
	return 0;
}
