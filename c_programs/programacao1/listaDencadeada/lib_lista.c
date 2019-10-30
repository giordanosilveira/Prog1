#include <stdio.h>
#include <stdlib.h>
#include "lib_lista.h"
void imprime_lista (t_lista *l) {

	t_nodo *aux;
	if (lista_vazia(l) != 1) {
		aux = l->ini->prox;
		while (aux->prox != l->fim) {
			printf ("%d ", aux->chave);
			aux = aux->prox;
		}
		printf ("%d ", aux->chave);
		printf ("\n");
	}
}
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
		return 1;
	return 0;
}
void destroi_lista(t_lista *l) {

	t_nodo *aux;

	aux = l->ini->prox;
	if (! lista_vazia(l)) {
		while (aux->prox != NULL) {
			aux = aux->prox;
			free (aux->prev);
			l->tamanho--;
		}
		free (l->fim);
		free (l->ini);
	}
}
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
int insere_ordenado_lista(int item, t_lista *l) {

	t_nodo *novo,*p;

	if (lista_vazia(l))
		return insere_inicio_lista(item,l);

	novo = (t_nodo *)malloc(sizeof(t_nodo));
	if (novo == NULL)
		return 0;

	l->fim->chave = item;
	
	p = l->ini->prox;
	while (p->chave < item)
		p = p->prox;
	
	if (p == l->fim) 
		return insere_fim_lista(item,l);
	else {
		l->tamanho++;

		novo->chave = item;		
		novo->prox = p;
		novo->prev = p->prev;
	
		p->prev = novo;
		novo->prev->prox = novo;
	}
	return 1;
}
int remove_inicio_lista(int *item, t_lista *l) {
	
	if (lista_vazia (l))
		return 0;

	*item = l->ini->prox->chave;

	l->ini->prox = l->ini->prox->prox;
	free (l->ini->prox->prev);
	l->ini->prox->prev = l->ini;

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


	if (lista_vazia(l))
		return 0;

	l->fim->chave = chave;

	t_nodo *aux;
	aux = l->ini;	
	while (aux->prox->chave != chave)
		aux = aux->prox;

	if (aux == l->fim->prev)
		return 0;

	aux->prox = aux->prox->prox;
	free (aux->prox->prev);
	aux->prox->prev = aux;
	*item = chave;

	l->tamanho--;
	return 1;
}
int pertence_lista(int chave, t_lista *l) {

	t_nodo *aux;
	
	if (lista_vazia (l))
		return 0;

	aux = l->ini->prox;
	l->fim->chave = chave;

	while (aux->chave != chave) 
		aux = aux->prox;

	if (aux == l->fim)
		return 0;
	return 1;
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
int incrementa_atual(t_lista *l) {

	/*se a lista não estiver vazia*/
	if (lista_vazia(l)) return 0;
	
	if (l->atual == l->fim->prev) return 0;

	l->atual = l->atual->prox;
	
	return 1;
}
int decrementa_atual(t_lista *l) {

	/*se a lista não estiver vazia*/
	if (lista_vazia(l)) return 0;

	if (l->atual == l->ini->prox) return 0;

	l->atual = l->atual->prev;

	return 1;
}
int consulta_item_atual(int *item, t_lista *l) {

	if (lista_vazia(l))
		return 0;

	*item = l->atual->chave;
	return 1;
}
int remove_item_atual(int *item, t_lista *l) {

	if (lista_vazia(l))
		return 0;

	t_nodo *aux;

	*item = l->atual->chave;
	aux = l->atual;

	l->atual->prox->prev = aux->prev;
	l->atual->prev->prox = aux->prox;

	if (l->atual->prox == l->fim)
		l->atual = NULL;	
	else
		l->atual = l->atual->prox;
		
	l->tamanho--;
	free (aux);

	return 1;
}
