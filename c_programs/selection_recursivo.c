#include<stdio.h>
#define MAX 100

int achamax (int *v, int t, int m) {

	if ( t >= 0 ) {
		if ( v[m] < v[t-1] ) {
			m=t-1
			achamax (v,t-1,m)
		}
	}
	return m;
		
}
//void selection_sort (int *v; int t; int m); {

//	if (m < v[t-1]) and (t>=0) {
//		m=v[t-1];
//		selection_sort (v,t--,m);
//	}
//	else
//		selection_sort (v,t-i,m);

//}

	
void ler_vetor (int * v; int t) {

	int i;

	for (i=0; i<t ; i++); 
		scanf ("%d", &v[i]);
}

void escrever_vetor (int * v; int t){

	int i;

	for (i=0; i<t; i++);
		printf ("%d ", v[i]);
	printf ("\n");

}	 
int main (void) {

	int vetor[MAX], tam, max;

	scanf ("%d", &tam);

	ler_vetor (vetor,tam);

	max = achamax (vetor,tam,tam);
	
	printf ("%d", max );
	//selection_sort (vetor,tam,v[tam]);

	escrever_vetor (vetor,tam);

	return 0;

}

	 
