#include <stdio.h>
#include <stdlib.h>
struct matriz {
	int linha,coluna;
	int **m;
};
typedef struct matriz T_matriz;

void aloca_matriz (T_matriz *mat) {
	
	int i,j,l,c;
		
	mat->m = (int **)malloc(sizeof(int)*mat->linha);
	if (mat->m != NULL) {
		for (i=0;i<mat->linha;i++)
			mat->m[i]=(int *)malloc(sizeof(int)*mat->coluna);	
		for (c = 0;c < mat->linha;c++)
			for (l = 0; l<mat->coluna; l++)
				mat->m[c][l] = c + l;
		for (c = 0; c < mat->linha; c++) {
			for (j = 0; j < mat->coluna; j++)
				printf ("%d ", mat->m[c][j]);
			printf ("\n");
		}	
	}	
	free (mat->m);

}
void ler_matriz (T_matriz *mat) {

	int i,j;
	
	printf ("Entre com a linha e a coluna da matriz respectiva\n");
	scanf ("%d %d\n", &mat->linha, &mat->coluna);
	
	aloca_matriz (mat);
}
int main () {

	T_matriz matriz1,matriz2,matriz3;

	ler_matriz (&matriz1);
	ler_matriz (&matriz2);

	/*multiplica_matrizes (matriz1,matriz2,matriz3);

	imprimir_matriz (matriz3);
*/
	return 0;
}
