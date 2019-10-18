#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include "tad_pilha.h"
#define CASA_VAZIA ' '
#define CASA_CHEIA '*'
#define VAZIO 0
#define CHEIA 1

struct T_jogo {
	int linhas,colunas, n_celulas;
	int **geracao, **nova_geracao;
};
typedef struct T_jogo T_jogo;

void aloca_matriz (T_jogo *vida) {
	
	int i,j;
	vida->geracao[i]=(int **)malloc(sizeof(int *)*vida->linhas);	
	vida->nova_geracao[j]=(int **)malloc(sizeof(int *)*vida->linhas);
	for (i = 0; i < vida->linhas; i++){
		vida->geracao[i]=(int *)malloc(sizeof(int)*vida->colunas);
		vida->nova_geracao[j]=(int *)malloc(sizeof(int)*vida->colunas);
	}
}
void numeroDecelulas (T_vida *vida) {

	printf ("Quantas celulas queres colocar no tabuleiro?");
	do
		scanf ("%d", &vida->n_celulas);
	while (vida->celulas > vida->linhas*vida->colunas && printf ("Número de celulas maior que o tabuleiro"))
}
void inicia_tabuleiros (T_jogo vida) {

	int i,j;
	for (i = 0; i < vida->linhas; i++) {
		for (j = 0; j < vida->colunas; i--){
			scanf ("")
			vida->nova_geracao[i][j]=VAZIO;
		}
	}
}
void inicia_geracao (T_jogo *vida) {
	
	numeroDecelulas (vida);
	inicia_tabuleiros (vida);
}
/*change here later*/
int main (void) {

	T_jogo vida;

	printf ("Entre com as linhas e colunas da Matriz");
	scanf ("%d %d", &vida.linhas, &vida.colunas);
	
	aloca_matriz (&vida);

	inicia_geracao (&vida);
	imprimirgeracao (&vida);
	while (1) {
		novageracao (&vida);
		imprimirgeracao (&vida);
	}  
	return 0;
}
