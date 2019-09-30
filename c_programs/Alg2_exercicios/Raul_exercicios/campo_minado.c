#include <stdio.h>

#define MAX 12
#define BOMBA -1
#define VAZIO 0
#define BORDA -5
#define ACABOU 0
/*is for status only*/
#define DERROTA -1
#define ANDAMENTO 0
#define VITORIA 1

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
struct coordenada {
	int linha;
	int coluna;
};
typedef struct coordenada T_coordenada;


void imprimir_tabuleiro (T_campominado *);
void zerar_tabuleiro (T_campominado *);
void colocar_bombas (T_campominado *);
int check_vizinhos (T_campominado *,int ,int );
void inicializa_campo (T_campominado *);
void vizinhos_com_bombas (T_campominado *);
void ler_jogada (T_campominado *,T_coordenada *);


void imprimir_tabuleiro (T_campominado *jogo) {
/*print the board*/

	int i,j;
	for (i=1;i<=jogo->tam_tab;i++) { 
		for (j=1;j<=jogo->tam_tab;j++) {
			if (jogo->tabuleiro[i][j].revel != 0)
				printf ("%d ", jogo->tabuleiro[i][j].info);
		}
		printf ("\n");
	}

}
void ler_jogada (T_campominado *jogo, T_coordenada *jogada) {
	/*the player choose a line and column to make a move, but in diferent location */
	printf ("Choose a line and the column\n");
	do 
		scanf ("%d %d", &jogada->linha, &jogada->coluna);
	while (jogo->tabuleiro[jogada->linha][jogada->coluna].revel == 1);
	
}
void inicializa_campo (T_campominado *jogo) {

	printf ("choose game board size: ");
	scanf ("%d", &jogo->tam_tab);
	printf ("choose the number of bombs: ");
	scanf ("%d", &jogo->n_bombas);
	jogo->falta_abrir = jogo->tam_tab*jogo->tam_tab - jogo->n_bombas; /*falta_abrir receive the number house from board minus the number of bombs*/
	jogo->status = ANDAMENTO; 
	zerar_tabuleiro (jogo); /*clear the board*/
	colocar_bombas (jogo); /*put the bombs in the board*/
	vizinhos_com_bombas (jogo); /*this location gets the number of neighboring bombs*/

}
void zerar_tabuleiro (T_campominado *jogo) {
/*this function starts the board with zeros and put a border around the board*/
	int i,j;
	for (i=0;i<=jogo->tam_tab+1;i++){
		for (j=0;j<=jogo->tam_tab+1;j++) {
			if (i==0 || j==0 || i==jogo->tam_tab+1 || j==jogo->tam_tab+1) 
				jogo->tabuleiro[i][j].info = BORDA;
			else 
				jogo->tabuleiro[i][j].info = VAZIO;
			jogo->tabuleiro[i][j].revel = 0;
		}
	}	
 
}
void colocar_bombas (T_campominado *jogo) {
/*this function puts, ramdomly, bombs in the board*/
	int bomba,i,j;
	bomba=1;
	while (bomba<=jogo->n_bombas) {
		i = 1 + rand () % jogo->tam_tab;
		j = 1 + rand () % jogo->tam_tab;
		if (jogo->tabuleiro[i][j].info != BOMBA) {
			bomba++;	
			jogo->tabuleiro[i][j].info = BOMBA;
		}
	}
}
void vizinhos_com_bombas (T_campominado *jogo) {

	int i,j;
	for (i=1;i<=jogo->tam_tab;i++){
		for (j=1;j<=jogo->tam_tab;j++){
			if (jogo->tabuleiro[i][j].info == VAZIO)
				jogo->tabuleiro[i][j].info = check_vizinhos (jogo,i,j);
		}
	}

}
int check_vizinhos (T_campominado *jogo, int i, int j) {

	int cont,l,c;
	cont=0;
	for (l=i-1;l<=i+1;l++) {
		for (c=j-1;c<=j+1;c++) {
			if (jogo->tabuleiro[l][c].info == BOMBA)
				cont++;
		}
	}
	return cont++;
}
void executar_jogada (T_campominado *jogo, T_coordenada jogada) {

	T_coordenada coord;
	int cont;
	Tad_pilha p;
	
	if (jogo->tabuleiro[jogada.linha][jogada.coluna].info == BOMBA) {
		jogo->status = DERROTA;
		revelar_jogo (jogo);
	}
	else {
		cont = 1;
		jogo->tabuleiro[jogada.linha][jogada.coluna].revel = 1;
		if (jogo->tabuleiro[jogada.linha][jogada.coluna].info == VAZIO) {
			coord.linha=jogada.linha;
			coord.coluna=jogada.coluna;
			inicializa_pilha (p);
			empilha (coord,p);
			/*cont = expande_vizinhos (,p);*/
		}
		jogo->falta_abrir = jogo->falta_abrir - cont;
		if (jogo->falta_abrir == ACABOU) {
			jogo->status = VITORIA;
		}
	}

}
void main () {

	T_campominado jogo;
	T_coordenada jogada;

	inicializa_campo(&jogo);
	imprimir_tabuleiro (&jogo);

	/*do*/
		ler_jogada(&jogo,&jogada);
		executar_jogada(&jogo,jogada);
	/*while ((ganhou(jogo)) || (perdeu(jogo)))
	if (perdeu(jogo)) 
		printf ("Tente outra vez amigo");
	else
		pritnf ("Você é um campeão meu amigo");*/
}
