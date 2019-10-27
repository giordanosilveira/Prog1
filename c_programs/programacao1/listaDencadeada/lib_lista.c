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
void destroi_lista(t_lista *l);
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
int insere_ordenado_lista(int item, t_lista *l);
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
//int remove_item_lista(int chave, int *item, t_lista *l)
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
//int inicializa_atual_inicio(t_lista *l);
//int inicializa_atual_fim(t_lista *l);
//void incrementa_atual(t_lista *l);
//void decrementa_atual(t_lista *l);
//int consulta_item_atual(int *item, t_lista *atual);
//int remove_item_atual(int *item, t_lista *l);
