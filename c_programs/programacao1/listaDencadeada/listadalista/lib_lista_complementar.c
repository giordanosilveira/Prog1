#include <stdio.h>
#include <stdlib.h>

#include "lib_lista_complementar.h"

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

	int i,item,tam;

	if (lista_vazia(l))
		return 0;

	inicializa_atual_inicio (l);

	tamanho_lista (&tam,l);	

	for (i = 0; i < tam; i++) {
		if (consulta_item_atual(&item,l))
			if ( ! insere_fim_lista (item,c))
				return 0;
		incrementa_atual (l);
	}

	return 1;
}
int concatena_listas (t_lista *l, t_lista *c) {


	int i,item,tam;

	if (lista_vazia(l) && lista_vazia(c))
		return 0;

	inicializa_atual_inicio (c);

	tamanho_lista (&tam,c);

	for (i = 0; i < tam; i++) {
		if (consulta_item_atual(&item,c))
			if ( ! insere_fim_lista (item,l))
				return 0;
		incrementa_atual (c);	
	}	
	destroi_lista (c);

	return 1;
}
int intercala_listas (t_lista *l, t_lista *m, t_lista *i) {

	int j,item1,item2;
	int tam1, tam2;

	if (lista_vazia(l) && lista_vazia(m))
		return 0;

	tamanho_lista (&tam1,l);
	tamanho_lista (&tam2,m);

	ordena_lista (l);
	ordena_lista (m);
	
	inicializa_atual_inicio (l);
	inicializa_atual_inicio (m);

	if (tam1 > tam2) {
		for (j = 0; j < tam2; j++) {
			consulta_item_atual (&item1,l);
			consulta_item_atual (&item2,m);
			if (item1 > item2) {
				insere_fim_lista (item2,i);
				insere_fim_lista (item1,i);
			}
			else {
				insere_fim_lista (item1,i);
				insere_fim_lista (item2,i);
			}
			incrementa_atual (l);
			incrementa_atual (m);
		}
		for (j = tam2; j < tam1; j++) {
			consulta_item_atual (&item1,l);
			insere_fim_lista (item1,i);
			incrementa_atual (l);
		}
	}
	else {
		for (j = 0; j < tam1; j++) {
			consulta_item_atual (&item1,l);
			consulta_item_atual (&item2,m);
			if (item1 > item2) {
				insere_fim_lista (item2,i);
				insere_fim_lista (item1,i);
			}
			else {
				insere_fim_lista (item1,i);
				insere_fim_lista (item2,i);
			}
			incrementa_atual (l);
			incrementa_atual (m);
		}
		for (j = tam1; j < tam2; j++) {
			consulta_item_atual (&item1,m);
			insere_fim_lista (item1,i);
			incrementa_atual (m);
		}
	}
	return 1;
}
int ordena_lista (t_lista *l) {

	t_lista aux;
	int i,item,tam;


	if (lista_vazia(l))
		return 0;

	tamanho_lista (&tam,l);
	inicializa_lista (&aux);	
	inicializa_atual_inicio (l);
	
	for (i = 0; i < tam; i++) {
		consulta_item_atual (&item,l);
		insere_ordenado_lista (item,&aux);
		incrementa_atual (l);
	}
	
	destroi_lista (l);
	inicializa_lista (l);
	copia_lista (&aux,l);
	destroi_lista (&aux);
	
	return 1;
}
