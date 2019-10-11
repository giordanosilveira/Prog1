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

	mat_aux= (int**)malloc (sizeof(int*)*mat.linha);
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
void multiplica_matrizes (T_matriz mat1, T_matriz mat2, T_matriz *mat3) {

	int i,j,k,soma;
	
	soma=0;
	for (i = 0;i < mat1.linha;i++) {
		for (j=0;i < mat1.coluna;j++){
			for (k=0; k < mat2.linha; k++)
				soma = soma + mat1.matriz[i][j]*mat2.matriz[k][j];
			mat3->matriz[i][j]=soma;	
		}
	}
}
int main () {

	T_matriz mat1, mat2, mat3;

	printf ("Entre com o números das linhas e colunas da primeira matriz\n");
	scanf ("%d %d", &mat1.linha, &mat1.coluna);

	printf ("Entre com os números das linhas e colunas da segunda matriz\n");
	scanf ("%d %d", &mat2.linha, &mat2.coluna);	

	if (mat1.coluna != mat2.linha) {
		printf ("Matrizes inválidas\n");
	}
	else {
		mat1.matriz = aloca_matriz (mat1);
		mat2.matriz = aloca_matriz (mat2);
	
		if ((mat2.matriz != NULL) && ((mat1.matriz) != NULL)) {
			printf ("matriz 1 !?\n");
			ler_matriz (&mat1);

			printf ("matriz 2 !?\n");
			ler_matriz (&mat2);

			mat3.linha = mat1.linha; mat3.coluna=mat2.coluna;
			mat3.matriz = aloca_matriz (mat3);
				if (mat3.matriz != NULL){
					printf ("Aqui");
					multiplica_matrizes (mat1,mat2,&mat3);
					imprimir_resultado (mat3);
				}
				else
					printf ("MEMORIA CHEIA BRO");
		}
		else
			printf ("MEMORIA CHEIA BRO");
	}
	return 0;
}
