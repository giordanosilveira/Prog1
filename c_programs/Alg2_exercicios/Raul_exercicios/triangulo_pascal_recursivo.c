#include <stdio.h>
/*linhas do triangulo*/
/**/
void varia_coluna (int linha, int coluna, long coef) {
		if (coluna<=linha){
			if (coluna == 0 || linha == 0) {
				coef=1;
				printf ("%ld ", coef);
			}
			else {
				coef=coef*(linha-coluna+1)/coluna;
				printf ("%ld ", coef);
			}
			varia_coluna (linha,coluna+1,coef);
		}
}
/*varia as linhas de modo crescente de 0..n-1*/
void pascal (int linha, int coluna, long coef) {
		if (linha>=0) {
			pascal (linha-1,0,1);	
			printf ("\n");
			varia_coluna (linha,0,1);
		}
}
int main () {
	
	int linha;

	scanf ("%d",&linha);
	pascal(linha-1,0,1);

	printf ("\n");
	return 0;
}
