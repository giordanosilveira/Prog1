#include <stdio.h>
#include <stdlib.h>
#include "tad_fila.h"

void imprime_fila (t_fila *l) {

	int i, item, tamanho, tempo;

	tamanho = tamanho_fila (f);

	if (fila_vazia(f))
		return;

	inicializa_atual_inicio (f);

	for (i = 0; i < tamanho; i++) {
		consulta_id_atual (&item,f);
		consulta_tempo_atual (&tempo,f);
		if (versao) {
			printf ("%d ", item);
		}
		else 
			printf ("%d(%d) ", item, tempo);
		incrementa_atual(f);
}
int inicializa_fila(t_fila *l) {

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

int fila_vazia(t_fila *l) {

	if (l->tamanho == 0)
		return 1;
	return 0;
}
void destroi_fila(t_fila *l) {

	int lixo, i, tam;

	tam = f->tamanho;

	for (i = 0, i < tam; i++)
		desenfileira (&lixo, f);

	if
	t_nodo *aux;

	aux = l->ini->prox;
	if (! fila_vazia(l)) {
		while (aux->prox != NULL) {
			aux = aux->prox;
			free (aux->prev);
			l->tamanho--;
		}
	}
	free (l->fim);
	free (l->ini);
}
int tamanho_fila(int *tam, t_fila *l) {

	if (f->tamanho == 0)
		return f->tamanho;
	return -1;
}
int enfileira (int id, int tempo, t_fila *l){

	t_nodo *new;

	new = (t_nodo *)malloc(sizeof(t_nodo));
	if (new == NULL)
		return 0;

	l->tamanho++;
	
	new->id = id;
	new->tempo = tempo;

	new->prox = l->fim;
	new->prev = l->fim->prev;

	new->prev->prox = new;
	l->fim->prev = new;

	return 1;
}
int desenfileira (int *item, t_fila *l) {
	
	if (fila_vazia (l))
		return 0;

	f->fim->id  = id;

	p = f->ini;
	while (p->prox->id != id)	
		p = p->prox;
	
	if (p == f->fim->prev)
		return 0;

	p->prox = p->prox->prev;
	free (p->prox->prev);
	p->prox->prev = p;

	f->tamanho--;
	
	return 1;
}
int remove_fim_fila(int *item, t_fila *l) {

	t_nodo *aux;
	
	if (fila_vazia (l))
		return 0;

	*item = l->fim->prev->chave;

	aux = l->fim->prev;

	aux->prev->prox = l->fim;
	l->fim->prev = aux->prev;
	
	free (l->fim->prev);

	l->tamanho--;

	return 1;
}
int remove_item_fila(int chave, int *item, t_fila *l) {


	if (fila_vazia(l))
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
int pertence_fila(int chave, t_fila *l) {

	t_nodo *aux;
	
	if (fila_vazia (l))
		return 0;

	aux = l->ini->prox;
	l->fim->chave = chave;

	while (aux->chave != chave) 
		aux = aux->prox;

	if (aux == l->fim)
		return 0;
	return 1;
}
int inicializa_atual_inicio(t_fila *l) {

	if (fila_vazia(l))
		return 0;

	l->atual = l->ini->prox;
	return 1;
}
int inicializa_atual_fim(t_fila *l) {

	if (fila_vazia(l))
		return 0;

	l->atual = l->fim->prev;
	return 1;

}
int incrementa_atual(t_fila *l) {

	/*se a fila não estiver vazia*/
	if (fila_vazia(l)) return 0;
	
	if (l->atual == l->fim->prev) return 0;

	l->atual = l->atual->prox;
	
	return 1;
}
int decrementa_atual(t_fila *l) {

	/*se a fila não estiver vazia*/
	if (fila_vazia(l)) return 0;

	if (l->atual == l->ini->prox) return 0;

	l->atual = l->atual->prev;

	return 1;
}
int consulta_item_atual(int *item, t_fila *l) {

	if (fila_vazia(l))
		return 0;

	*item = l->atual->chave;
	return 1;
}
int remove_item_atual(int *item, t_fila *l) {

	t_nodo *p;

	if (fila_vazia(l))
		return 0;

	*item = l->atual->chave;

	p = l->atual;	

	l->atual->prev->prox = l->atual->prox;
	l->atual->prox->prev = l->atual->prev;

	if (l->atual->prox == l->fim) {
		l->atual = l->atual->prev;
	}	
	else
		l->atual = l->atual->prox;
		
	l->tamanho--;
	free (p);

	return 1;
}
