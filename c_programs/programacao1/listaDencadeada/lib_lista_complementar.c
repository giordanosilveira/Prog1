#include "lib_lista_complementar.h"
#include <stdio.h>
#include <stdlib.h>

void imprime_lista (t_lista *l) {

	int i,tam,item;

	inicializa_atual_inicio (l);
	
	tamanho_lista (&tam,l);

	if (! lista_vazia(l)) {
		for (i = 0; i < tam; i++) {
			if (consulta_item_atual (&item,l))
				printf ("%d ", item);
			incrementa_atual (l);
		}
	}	
}

int copia_lista (t_lista *l, t_lista *c) {

	int i,item;

	if (lista_vazia(l))
		return 0;

	inicializa_atual_inicio (l);

	for (i = 0; i < l->tamanho; i++) {
		if (consulta_item_atual(&item,l))
			return insere_fim_lista (item,c);
		incrementa_atual (l);
	}

	return 1;
}
int concatena_listas (t_lista *l, t_lista *c) {


	int i,item;

	if (lista_vazia(l) && lista_vazia(c))
		return 0;

	inicializa_atual_inicio (c);

	for (i = 0; i < l->tamanho; i++) {
		if (consulta_item_atual(&item,c))
			return insere_fim_lista (item,l);
		incrementa_atual (c);	
	}	
	destroi_lista (c);

	return 1;
}
int intercala_listas (t_lista *l, t_lista *m, t_lista *i) {

	int j,item1,item2;

	if (lista_vazia(l) && lista_vazia(m))
		return 0;

	inicializa_atual_inicio (l);
	inicializa_atual_inicio (m);

	if (l->tamanho > m->tamanho) {
		for (j = 0; j < m->tamanho; j++) {
			consulta_item_atual (&item1,l);
			consulta_item_atual (&item2,m);
			if (item1 > item2) {
				return insere_fim_lista (item1,i);
				return insere_fim_lista (item2,i);
			}
			else {
				return insere_fim_lista (item2,i);
				return insere_fim_lista (item1,i);
			}
			incrementa_atual (l);
			incrementa_atual (m);
		}
		for (j = m->tamanho; j < l->tamanho; j++) {
			consulta_item_atual (&item1,l);
			return insere_fim_lista (item1,l);
			incrementa_atual (l);
		}
	}
	else {
		for (j = 0; j < l->tamanho; j++) {
			consulta_item_atual (&item1,l);
			consulta_item_atual (&item2,m);
			if (item1 > item2) {
				return insere_fim_lista (item1,i);
				return insere_fim_lista (item2,i);
			}
			else {
				return insere_fim_lista (item2,i);
				return insere_fim_lista (item1,i);
			}
			incrementa_atual (l);
			incrementa_atual (m);
		}
		for (j = l->tamanho; j < m->tamanho; j++) {
			consulta_item_atual (&item1,m);
			return insere_fim_lista (item1,i);
			incrementa_atual (m);
		}
	}
	return 1;
}
void troca (int *a, int *b){

	int aux;
	aux=*a;
	*a=*b;
	*b=aux;
}

int particiona (int *ent, int ini, int fim) {
/*particiona pivo final*/
	
	int i,barreira,pivo;
	barreira=ini-1;
	pivo=ent[fim];
	for (i=ini;i<fim;i++) {
		if (ent[i]<pivo) {
			barreira++;
			troca (&ent[i],&ent[barreira]);
		}
	}
	troca (&ent[fim],&ent[barreira+1]);
	return barreira+1;
}
void quicksort (int *ent, int ini, int fim) {

	int pivo;
	if (ini<fim) {
		pivo=particiona(ent,ini,fim);
		quicksort (ent,ini,pivo-1);
		quicksort (ent,pivo+1,fim);
	}
}
int ordena_lista (t_lista *l) {

	int *v;
	int i,item;


	if (lista_vazia(l))
		return 0;
	
	v = (int *)malloc(sizeof(int)*l->tamanho);

	if (v == NULL)
		return 0;

	inicializa_atual_inicio (l);
	
	for (i = 0; i < l->tamanho; i++) {
		consulta_item_atual (&item,l);
		v[i] = item;
		remove_item_atual (&item,l);
	}
	
	quicksort (v,0,l->tamanho);

	inicializa_atual_inicio (l);

	for (i = 0; i < l->tamanho; i++) {
		return insere_fim_lista (v[i],l);
	}
	
	return 1;
}
