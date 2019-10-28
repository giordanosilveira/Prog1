#include <stdio.h>
#include <stdlib.h>
#include "lib_lista.h"
int inicializa_lista(t_lista *l) {

	t_nodo *ini, *fim;
	
	ini = (t_nodo *)malloc(sizeof(t_nodo));
	if (ini == NULL)
		return 0;

	fim = (t_nodo *)malloc(sizeof(t_nodo));
	if (fim == NULL) {
		free (ini);
		return 0;
	}

	l->ini = ini;
	l->fim = fim;

	ini->prox = fim;
	ini->prev = NULL;

	fim->prev = ini;
	fim->prox = NULL;
	
	l->atual = NULL;

	l->tamanho = 0;
	
	return 1;
}

int lista_vazia(t_lista *l) {

	if (l->tamanho == 0)
		return 0;
	return 1;
}
//void destroi_lista(t_lista *l);
int insere_inicio_lista(int item, t_lista *l) {

	t_nodo *new;

	new = (t_nodo *)malloc(sizeof(t_nodo));
	if (new == NULL)
		return 0;

	l->tamanho++;

	new->chave = item;
	new->prox = l->ini->prox;
	new->prev = l->ini;

	new->prox->prev = new;
	l->ini->prox = new;

	return 1;

}
int tamanho_lista(int *tam, t_lista *l) {

	*tam = l->tamanho;
	return 1;
}
int insere_fim_lista(int item, t_lista *l){

	t_nodo *new;

	new = (t_nodo *)malloc(sizeof(t_nodo));
	if (new == NULL)
		return 0;

	l->tamanho++;

	new->chave = item;
	new->prox = l->fim;
	new->prev = l->fim->prev;

	new->prev->prox = new;
	l->fim->prev = new;

	return 1;
}
//int insere_ordenado_lista(int item, t_lista *l);
int remove_inicio_lista(int *item, t_lista *l) {

	t_nodo *aux;
	
	if (lista_vazia (l))
		return 0;
	
	aux = l->ini->prox;

	*item = l->ini->prox->chave;
	l->ini->prox = aux->prox;
	aux->prox->prev = l->ini;
	free (l->ini->prox);

	l->tamanho--;
	
	return 1;
}
int remove_fim_lista(int *item, t_lista *l) {

	t_nodo *aux;
	
	if (lista_vazia (l))
		return 0;

	*item = l->fim->prev->chave;

	aux = l->fim->prev;

	aux->prev->prox = l->fim;
	l->fim->prev = aux->prev;
	
	free (l->fim->prev);

	l->tamanho--;

	return 1;
}
int remove_item_lista(int chave, int *item, t_lista *l) {

	t_nodo *aux;

	if (lista_vazia(l))
		return 0;

	/*se o elemento esta em primeiro da lista*/
	if (chave == l->ini->prox->chave) {
		return (remove_inicio_lista(item,l));
	}

	/*se o elemento esta em ultimo da lista*/
	if (chave == l->fim->prev->chave)
		return (remove_fim_lista(item,l));

	/*caso geral*/
	int i;
	
	aux = l->ini->prev->prev;
	for (i = 2; i < l->tamanho; i++) {
		if (chave == aux->chave) {
			*item = aux->chave;
			l->tamanho--;
			return 1;
		}
		aux = aux->prev;
	}
	return 0;
}
int pertence_lista(int chave, t_lista *l) {

	t_nodo *aux;
	
	if (lista_vazia (l))
		return 0;

	aux = l->ini->prox;
	while (aux->prox != l->fim) {
		if (chave == aux->chave)
			return 1;
		aux = aux->prox;
	}
	if (aux->chave == chave)
		return 1;
	return 0;
}
int inicializa_atual_inicio(t_lista *l) {

	if (lista_vazia(l))
		return 0;

	l->atual = l->ini->prox;
	return 1;
}
int inicializa_atual_fim(t_lista *l) {

	if (lista_vazia(l))
		return 0;

	l->atual = l->fim->prev;
	return 1;

}
void incrementa_atual(t_lista *l) {

	t_nodo *aux;
	/*se a lista não estiver vazia*/
	if (! lista_vazia(l)) {
		if (l->tamanho > 1) { /*se a lista tiver mais de um elemento*/
			aux = l->atual;
			l->atual = aux->prox;	
		}
	}
}
void decrementa_atual(t_lista *l) {

	t_nodo *aux;
	/*se a lista não estiver vazia*/
	if (! lista_vazia(l)) {
		if (l->tamanho > 1) { /*se a lista tiver mais de um elemento*/
			aux = l->atual;
			l->atual = aux->prev;
		}
	}
}
/*int consulta_item_atual(int *item, t_lista *atual) {

	if (lista_vazia(l))
		return 0;

	
}*/
//int remove_item_atual(int *item, t_lista *l);
