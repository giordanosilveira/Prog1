#include <stdio.h>
#define MAX 50
#define BOMBA -1
#define VAZIO 0
#define ANDAMENTO 1
#define BORDA -5

struct conteudo {
	int revel, info;
};
typedef struct conteudo T_conteudo;
struct campominado {
	T_conteudo tabuleiro[MAX][MAX]; /*board nxn*/
	int tam_tab; /*board size*/
	int n_bombas;/*number of game bombs*/
	int falta_abrir; /*number of bombs left to open*/
	int status;
};

typedef struct campominado T_campominado;
void imprimir_tabuleiro (T_campominado *jogo) {

	int i,j;
	for (i=0;i<=jogo->tam_tab+1;i++) 
		for (j=0;j<=jogo->tam_tab+1;j++)
			printf ("%d ", jogo->tabuleiro[i][j]->info) ;

}
void zera_tabuleiro (T_campominado **jogo) {

	int i,j;
	for (i=0;i<=jogo->tam_tab+1;i++){
		for (j=0;j<=jogo->tam_tab+1;j++) {
			if (jogo->tabuleiro[0][i]->info || jogo->tabuleiro[i][0]->info || jogo->tabuleiro[jogo->tam_tab][i]->info || jogo->tabuleiro[i][jogo->tam_tab]->info)
				jogo->tabuleiro[i][j]->info = BORDA;
			else
				jogo->tabuleiro[i][j]->info = VAZIO;
			jogo->tabuleiro[i][j]->revel = 0;
		}
	}	
 
}
void colocar_bombas (T_campominado **jogo) {

	int bomba,i,j;
	bomba=1;
	while (bomba<=jogo->n_bombas) {
		i = 1 + rand () % jogo->tam_tab;
		j = 1 + rand () % jogo->tam_tab;
		if (jogo->tabuleiro[i][j]->info != BOMBA) {
			bomba++;	
			jogo->tabuleiro[i][j]->info = BOMBA;
		}
	}
}
void inicializa_campo (T_campominado *jogo) {

	printf ("choose game board size: ");
	scanf ("%d", &jogo->tam_tab);
	printf ("choose the number of bombs: ");
	scanf ("%d", &jogo->n_bombas);
	jogo->falta_abrir = jogo->tam_tab*jogo->tam_tab - jogo->n_bombas; /*falta_abrir receive the number house from board minus the number of bombs*/
	jogo->status = ANDAMENTO; 
	zera_tabuleiro (&jogo); /*clear the board*/
	colocar_bombas (&jogo); /*put the bombs in the board*/
	/*vizinhos_bombas (&jogo);*/ /*this location gets the number of neighboring bombs*/

}
void main () {

	T_campominado jogo;

	inicializa_campo(&jogo);
	imprimir_tabuleiro (&jogo);

	/*do
		ler_jogada(jogo)
		executar_jogada(jogo)
	while ((ganhou(jogo)) || (perdeu(jogo)))
	if (perdeu(jogo)) 
		printf ("Tente outra vez amigo");
	else
		pritnf ("Você é um campeão meu amigo");*/

}
