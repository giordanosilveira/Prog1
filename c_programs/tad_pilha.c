#include<stdio.h>
#define MAX 5
typedef struct tad_pilha
{
	int vetor[MAX-1];
	int ini;
} tad_pilha;


void inicializa_pilha (tad_pilha *p) {
	(*p).ini=-1;
}

// retorna 1 se a pilha p esta vazia e 0 caso contrario
int pilha_vazia (tad_pilha *p) {
	if ((*p).ini == -1)
		return 1;
	else
		return 0;
}


// retorna o numero de elementos da pilha p
int tamanho_pilha (tad_pilha *p) {
	if ((*p).ini==-1)
		return 0;
	else
		return (*p).ini+1;
}


// empilha o inteiro x na pilha p
// retorna 1 se a operacao foi realizada com sucesso e 0 caso contrario
int empilha (int x, tad_pilha *p) {
	if ((*p).ini==MAX-1)
		return 0;
	else
	{
		(*p).ini++;
		(*p).vetor[(*p).ini]=x;
		return 1;
	}
}
// retorna em t o elemento do topo da pilha e o desempilha
// a funcao retorna 1 se a operacao foi bem sucedida e 0 caso contrario
int desempilha (int t, tad_pilha *p) {
	if ((*p).ini==-1)
		return 0;
	else
	{
		(*p).ini--;
		return 1;
	}
}

// retorna em t o elemento do topo da pilha, sem desempilhar
//a funcao retorna 1 se a operacao foi bem sucedida e 0 caso contrario
int topo (int *t, tad_pilha *p) {
	if ((*p).ini==-1)
		return 0;
	else
	{
		(*t) = (*p).vetor[(*p).ini];
		return 1;
        }
}

/* O codigo abaixo so pode ser modificado para resolver o    */
/* problema da passagem de endereços como parâmetros!        */
/* Deixe o restante do programa inalterado!!!                */

int main() {
    tad_pilha p; 
    int i,x,t;
    
    inicializa_pilha(&p);
    printf("tamanho inicial da pilha eh: %d\n",tamanho_pilha(&p));

    for (i=0; i<=MAX; i++)
        if (! empilha(i,&p)) {
            printf("%d nao inserido: pilha cheia\n",i);
            printf("tamanho da pilha: %d\n",tamanho_pilha(&p));
        }
        else {
            printf("%d empilhado\n",i);
            printf("tamanho da pilha: %d\n",tamanho_pilha(&p));
        }

    for (i=0; i<=MAX; i++) {
        x = topo(&t,&p);
        if (! x)
            printf("pilha vazia, topo nao existe\n");
        else
            printf("topo eh: %d\n",t);

        x = desempilha(t,&p);
        if (! x)
            printf("nao desempilhou: pilha vazia\n");
        else
            printf("%d desempilhado\n",t);
    }
    
    return 0;
}

// faz a inicializa ̧c~ao do TAD pilhavoid inicializa_pilha (tad_pilha p)

