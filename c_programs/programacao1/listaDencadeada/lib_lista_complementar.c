#include "lib_lista_complementar.h"
#include "lib_lista.h"
#include <stdio.h>
#include <stdlib.h>

void imprime_lista (t_lista *l) {

	int i,tam,item;

	inicializa_atual_inicio (l);
	
	tamanho_lista (&tam);

	if (lista_vazia(l))
		return 0;

	for (i = 0; i < tam; i++) {
		if (consulta_item_atual (&item,l))
			printf ("%d ", item);
		incrementa_atual (l);
	}	
	return 1;
}

int copia_lista (t_lista *l, t_lista *c) {

	t_nodo *new;
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
}
int intercala_listas () {





}











