#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "tad_pilha_coord.h"

#define CASA_VAZIA ' '
#define CASA_CHEIA '*'
#define MORTE 0
#define VIDA 1
#define BORDA -1

struct T_jogo {
	int linhas,colunas,n_geracoes;
	int **geracao, **nova_geracao;
};
typedef struct T_jogo T_jogo;

void aloca_matriz (T_jogo *vida) {
	
	int i;
	vida->geracao=(int **)malloc(sizeof(int *)*(vida->linhas+2));	
	vida->nova_geracao=(int **)malloc(sizeof(int *)*(vida->linhas+2));
	for (i = 0; i < vida->linhas+2; i++){
		vida->geracao[i]=(int *)malloc(sizeof(int)*(vida->colunas+2));
		vida->nova_geracao[i]=(int *)malloc(sizeof(int)*(vida->colunas+2));
	}
}
int eh_borda (T_jogo *vida, int linha, int coluna) {

	if (linha==0 || coluna == 0 || linha == vida->linhas + 1 || coluna == vida->colunas + 1) 
		return 1;
	return 0;
}
void inicia_geracao (T_jogo *vida) {

	int i,j;
	for (i = 0; i <= vida->linhas+1; i++) {
		for (j = 0; j <= vida->colunas+1; j++){
			if (eh_borda(vida,i,j)) {
				vida->geracao[i][j]=BORDA;
				vida->nova_geracao[i][j]=BORDA;
			}
			else {
				vida->geracao[i][j]=MORTE;
				vida->nova_geracao[i][j]=MORTE;
			}
		}
	}
}
void imprimir_tabuleiro (T_jogo *vida) {

	int i,j;
	for (i = 1; i < vida->linhas + 1; i++) {
		for (j = 1; j < vida->colunas + 1; j++)
			if (vida->geracao[i][j]==MORTE)
				printf ("%c ", CASA_VAZIA);
			else
				printf ("%c ", CASA_CHEIA);
		printf ("\n");
	}
}
int conta_vizinhos (T_jogo *vida, int i, int j) {

	int l,c,cont;
	
	cont=0;	
	for (l = i-1; l <= i+1; l++) {
		for (c = j-1; c <= j+1; c++) {
			if (eh_borda (vida,l,c) == 0) {
				if (l != i || c != j){
					if (vida->geracao[l][c] != MORTE) 
						cont++;
				}
			}
		}	
	}
	return cont;

}
void atualiza_geracao (T_jogo *vida, tad_pilha *p){
	T_coord c;
	
	if (desempilha(&c,p));
	while (pilha_vazia(p) == 0) {
		vida->geracao[c.x][c.y]=vida->nova_geracao[c.x][c.y];
		if (desempilha(&c,p));
	}
}
void novageracao (T_jogo *vida, int i, int j, int cont) {
	
	if (cont < 2 || cont > 3) 
		vida->nova_geracao[i][j] = MORTE;
	else if (cont == 2)
		vida->nova_geracao[i][j] = vida->geracao[i][j];
	else if (cont == 3)
		vida->nova_geracao[i][j] = VIDA;
		
}
void vidaoumorte (T_jogo *vida) {

	int i,j,cont; 
	tad_pilha posicoes;
	T_coord coord;
	
	inicializa_pilha (&posicoes);
	for (i = 1; i <= vida->linhas; i++) {
		for (j = 1; j <= vida->colunas; j++) {
				cont = conta_vizinhos (vida,i,j);
				if (cont != 0) {
					novageracao (vida,i,j,cont);
					coord.x=i;
					coord.y=j;
					if (empilha(coord,&posicoes));
				}
		}
	}
	atualiza_geracao (vida,&posicoes);
}
void  ler_celulas (T_jogo *vida) {

	int i,j;
	scanf ("%d %d", &i, &j);
	while (i > 0 && j > 0 && i <= vida->linhas && j <= vida->colunas) {
		vida->geracao[i][j] = VIDA;
		scanf ("%d %d", &i,&j);
	}

}
/*change here later*/
int main (void) {

	T_jogo vida;
	
	printf ("Entre com as linhas e colunas da Matriz\n");
	scanf ("%d %d", &vida.linhas, &vida.colunas);
	printf ("Quantas gerações ?\n");
	scanf ("%d ", &vida.n_geracoes);

	aloca_matriz (&vida);

	if (vida.geracao != NULL && vida.nova_geracao != NULL) {

		inicia_geracao (&vida);
		ler_celulas (&vida);
		imprimir_tabuleiro (&vida);
		printf ("\n");
		while (vida.n_geracoes--) {
			printf("\e[1;1H\e[2J");
			vidaoumorte (&vida);
			imprimir_tabuleiro (&vida);
			usleep (800000);
		}  
	
	}
	return 0;
}
