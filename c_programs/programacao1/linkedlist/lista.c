
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

	t_nodo *ant;

	if (lista_vazia(l))
		return 0;
	
	*item = l->ini->chave;
	l->tam--;

	/*caso especial se a lista tem só um elemento*/
	if (l->ini->prox==NULL) {
		free(l->ini);
		l->ini = NULL;
		return 1;
	}
	
	l->ini = l->ini->prox;
	
	
}
int remove_ultimo_lista(t_item *item, t_lista *l);
int remove_item_lista(int chave, t_item *item, t_lista *l);
int pertence_lista(int chave, t_lista *l);
int concatena_listas(t_lista *l, t_lista *m);
int copia_lista(t_lista *l, t_lista *m);

