
int cria_lista(t_lista *l){
	l->ini = NULL;
	l->tam = 0;
	return 1;
}

int lista_vazia(t_lista *l) {
	if (l->tam == 0)
		return 1;
	return 0;
}

void destroi_lista(t_lista *l) {
}

int insere_inicio_lista(int x, t_lista *l) {
	
	t_nodo *new_no;

	new_no=(t_nodo *)malloc(sizeof(t_nodo));
	if (new_no != NULL) {
		new_no->elemento = x;
		new_no->prox= l->ini;
		l->ini = new_no;
		l-tam++;
		return 1;
	}
	return 0;
}
int insere_fim_lista(int x, t_lista *l) {

	t_nodo *new, *p;
	
	if (lista_vazia(l)) {
		insere_inicio_lista (x,l);
		return 1;
	}

	new=(t_nodo *) malloc (sizeof(t_nodo));
	if (new==NULL)
		return 0;

	l->tam++;
	new->prox=NULL;
	
	p = l->ini;
	while (p->prox != NULL) {
		p = p->prox;
	}	
	p->prox=new;
}

int insere_ordenado_lista(int x, t_lista *l); 
int remove_primeiro_lista(int *item, t_lista *l) {


	if (lista_vazia(l))
		return 0;
	
	*item = l->ini->chave;
	l->tam--;

	/*caso especial se a lista tem só um elemento*/
	if (l->ini->prox == NULL) {
		free(l->ini);
		l->ini = NULL;
		return 1;
	}
	
	l->ini = l->ini->prox;
	return 1;
	
	
}
int remove_ultimo_lista(int *item, t_lista *l) {

	t_nodo *p;
	
	if (lista_vazia(l))
		return 0;

	l->tam--;

	/*se a lista tem somente um elemento*/
	p=(t_nodo *)malloc(sizeof(t_nodo));
	if (p == NULL)
		return 0;

	if (l->ini->prox == NULL){
		return remove_primeiro_lista (item,l);
	}

	/*caso geral*/
	p=l->ini;
	while (p->prox->prox != NULL) {
		p=p->prox;
	}
	free (p->prox);
	p->prox=NULL;
	return 1;
}
int remove_item_lista(int chave, int *item, t_lista *l) {

	if (lista_vazia(l))
		return 0;
	
	t_nodo *p, *q;
	if (l->ini->chave == chave) {
		l->tam--;
		return (remove_primeiro_lista(item,l));
	}
	
	/*caso geral*/
	p = l->ini;
	while (p->prox != NULL && p->chave != chave){
		q = p;
		p = p->prox;
	}
	if (p->chave == chave){
		l->tam--;
		q->prox = p->prox;
		free (p);
	}
	printf ("Elemento não encontrado\n");
	return 0;
}
int pertence_lista(int chave, t_lista *l) {

	if (lista_vazia(l))
		return 0;
	
	t_nodo *p;
	p = l->ini;
	while (p->prox != NULL && p->chave != chave)
		p = p->prox;
	if (p->chave == chave)
		return 1;
	printf ("Elemento não encontrado");

}
int concatena_listas(t_lista *l, t_lista *m) {

	if (lista_vazia(l)) {
		l->ini = m->ini;
		m->ini = NULL;
		l->tam = m->tam; 
		cria_lista (m);
		return 1;
	}
	
	/*caso geral*/
	t_nodo *p;
	p = p->ini;
	while (p->prox != NULL)
		p = p->prox;
	p->prox = m->ini;
	m->ini = NULL;
	l->tam = l->tam + m->tam;
	cria_lista (m);
	return 1;
}
int copia_lista(t_lista *l, t_lista *m) {

	if (lista_vazia (l))
		return 0;

	m->tam = l->tam;

	t_nodo *p;

	p = l->ini;
	while (p->prox != NULL) {
		insere_fim_lista (p->chave,m);
		p = p->prox;
	}
	insere_fim_lista (p->chave,m);

}

