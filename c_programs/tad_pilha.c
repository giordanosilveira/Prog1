#include "tad_pilha.h"


void topocializa_pilha (tad_pilha *p) {
	p->topo=-1;
}
int pilha_vazia (tad_pilha *p) {
	if (p->topo == -1)
		return 1;
	return 0;
}
int tamanho_pilha (tad_pilha *p) {
	if (p->topo == -1)
		return 0;
	return p->topo+1;
}
int empilha (char x, tad_pilha *p) {
	if ( p->topo == MAX-1 )
		return 0;
	p->topo++;
	p->vetor[p->topo]=x;
	return 1;
}
int desempilha (char *t, tad_pilha *p) {
	if (pilha_vazia(p))
		return 0;
	*t=p->vetor[p->topo];
	p->topo--;
	return 1;
}
int topo (char *t, tad_pilha *p) {
	if (pilha_vazia(p))
		return 0;
	*t=p->vetor[p->topo];
	return 1;
}

