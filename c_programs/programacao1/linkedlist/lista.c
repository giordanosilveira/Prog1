
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
	
	t_nodo new_no;

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

	t_nodo aux;
	
	aux=(t_nodo *) malloc (sizeof(t_nodo));
	if (aux==NULL)
		return 0;	
	if (l->ini == NULL) {
		aux->elemento = x;
		l->ini=aux;
	}
	aux=l->ini;
	while (aux->prox != NULL) 
		aux = aux->prox;

}
int insere_ordenado_lista(int x, t_lista *l); 
int remove_primeiro_lista(t_item *item, t_lista *l);
int remove_ultimo_lista(t_item *item, t_lista *l);
int remove_item_lista(int chave, t_item *item, t_lista *l);
int pertence_lista(int chave, t_lista *l);
int concatena_listas(t_lista *l, t_lista *m);
int copia_lista(t_lista *l, t_lista *m);

