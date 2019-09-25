#include <stdio.h>
#define MAX 100
void ler_vetor (int *v,int t) {
	int i;
	
	for (i=1; i<=t; i++)
		scanf ("%d", (v+i));
}
/*procura o elemento no conceito do binary heap	*/
int acha_elemento (int *v, int t, int i, int x) {
	printf ("%d %d %d\n", x, i, v[i]);
	if (x==v[i]) return i;
	if (i>t) return 0;
	return (acha_elemento (v,t,(2*i),x) || acha_elemento (v,t,(2*i+1),x));

}
int main () {

	int vetor[MAX], tam, ini, x;
	
	printf ("tamanho, elemento\n");
	scanf ("%d %d", &tam, &x);
	if (tam<=MAX){
		ler_vetor (vetor,tam);
		ini = acha_elemento (vetor,tam,1,x);
		printf ("%d\n", ini);
		if (ini)
			printf ("O elemento esta na posição %d do vetor\n", ini);
		else
			printf ("O é elemento é igual à sua namorada, não existe!\n");
	}
	return 0;
}
