#include <sdtio.h>
#include <stdlib.h>
struct matriz {
	int linha,coluna;
	int **m;
};
typedef struct matriz T_matriz;

void ler_matriz (T_matriz *m) {

	int i,j;
	
	printf ("Entre com a linha %d e a coluna %d da matriz respectiva\n");
}
int main () {

	T_matriz matriz1,matriz2,matriz3;

	ler_matriz (&matriz1);
	ler_matriz (&matriz2);

	multiplica_matrizes (matriz1,matriz2,matriz3);

	imprimir_matriz (matriz3);

	return 0;
}
