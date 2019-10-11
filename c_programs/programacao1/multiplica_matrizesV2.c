#include <stdio.h>
#include <stdlib.h>
struct T_matriz {
	int linha,coluna;
	int **matriz;
};
typedef struct T_matriz T_matriz;

int ** aloca_matriz (T_matriz mat) {
	
	int i;
	int ** mat_aux;

	mat_aux= (int**)malloc (sizeof(int)*mat.linha);
	for (i=0;i<mat.linha;i++)
		mat_aux[i]=(int *)malloc (sizeof(int) * mat.coluna);
	return mat_aux;

}
void ler_matriz (T_matriz *mat) {
	
	int i,j;
	printf ("Entre com os valores da matriz\n");
	for (i=0;i<mat->linha;i++)
		for (j=0;j<mat->coluna;j++)
			scanf ("%d", &mat->matriz[i][j]);

}
void imprimir_resultado (T_matriz mat) {

	int i,j;

	for (i=0;i<mat.linha;i++){
		for (j=0;j<mat.coluna;j++)
			printf ("%d ", mat.matriz[i][j]);
		printf ("\n");
	}
}

int main () {

	T_matriz mat1, mat2, mat3;

	printf ("Entre com o números das linhas e colunas da primeira matriz\n");
	scanf ("%d %d", &mat1.linha, &mat1.coluna);
	mat1.matriz = aloca_matriz (mat1);

	printf ("Entre com os números das linhas e colunas da segunda matriz\n");
	scanf ("%d %d", &mat2.linha, &mat2.coluna);	
	mat2.matriz = aloca_matriz (mat2);

	printf ("matriz1\n");
	ler_matriz (&mat1);

	printf ("matriz2\n");
	ler_matriz (&mat2);

	/*if (mat2.matriz != NULL && mat1.matriz != NULL) {

		if (multiplica_matriz (mat1,mat2,mat3))
			imprime_resultado (mat3);
		else
			printf ("NÃO DEU CERTO");
	}
	else
		printf ("MEMORIA CHEIA BRO");*/
	
	return 0;
}
