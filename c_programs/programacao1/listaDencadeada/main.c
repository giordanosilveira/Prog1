#include <stdio.h>
#include "lib_lista.h"
#define MAX 7
int tinsprlist (t_lista *l) {
	
	int i;
	for (i = 0; i < MAX; i++) 
		if (! insere_inicio_lista(2*i+1,l)) return 0;
	return 1;
}
int tinsfimlist (t_lista *c) {

	int i;
	for (i = 0; i < MAX; i++) 
		if (! insere_fim_lista (2*i,c)) return 0;
	return 1;
}
int tinsordlist (t_lista *l) {

	if (! insere_ordenado_lista(15,l)) return 0;
	if (! insere_ordenado_lista(3,l)) return 0;
	if (! insere_ordenado_lista(7,l)) return 0;
	if (! insere_ordenado_lista(5,l)) return 0;
	if (! insere_ordenado_lista(1,l)) return 0;
	if (! insere_ordenado_lista(0,l)) return 0;
	return 1;
}
int tclista (t_lista *l,t_lista *c, t_lista *o, t_lista *p) {

	printf ("Teste: Cria listas\n");

	printf ("Criando lista l\n");
	if (! inicializa_lista(l)) {
		printf ("ERRO: lista não criada\n");
		return 0;
	}
	
	printf ("Criando lista c\n");
	if (! inicializa_lista(c)) {
		printf ("ERRO: lista não criada\n");
		return 0;
	}

	printf ("Criando lista o\n");
	if (! inicializa_lista(o)) {
		printf ("ERRO: lista não criada\n");
		return 0;
	}

	printf ("Criando lista p\n");
	if (! inicializa_lista(p)) {
		printf ("ERRO: lista não criada\n");
		return 0;
	}
	
	return 1;

}
int trmchvlist (t_lista *o, t_lista *p) {

	int lixo;
	if ( remove_item_lista (0,&lixo,o)) printf ("O 0 foi removido da lista o\n"); 	
	if ( remove_item_lista (2,&lixo,o)) printf ("O 2 foi removido da lista o\n"); 
	if ( remove_item_lista (3,&lixo,o)) printf ("O 3 foi removido da lista o\n"); 
	if ( remove_item_lista (4,&lixo,o)) printf ("O 4 foi removido da lista o\n"); 
	if ( remove_item_lista (5,&lixo,o)) printf ("O 5 foi removido da lista o\n"); 
	if ( remove_item_lista (0,&lixo,p)) printf ("O 0 foi removido da lista p\n"); 
	if ( remove_item_lista (1,&lixo,p)) printf ("O 1 foi removido da lista p\n"); 
	if ( remove_item_lista (5,&lixo,p)) printf ("O 5 foi removido da lista p\n"); 
	if ( remove_item_lista (7,&lixo,p)) printf ("O 7 foi removido da lista p\n"); 
	if ( remove_item_lista (9,&lixo,p)) printf ("O 9 foi removido da lista p\n"); 
	if ( remove_item_lista (9,&lixo,p)) printf ("O 9 foi removido da lista p\n"); 
	if ( remove_item_lista (10,&lixo,p)) printf ("O 10 foi removido da lista p\n"); 
	if ( remove_item_lista (12,&lixo,p)) printf ("O 12 foi removido da lista p\n"); 
	return 1;
}
int tremlista (t_lista *l, t_lista *c, t_lista *o, t_lista *p) {

	printf ("Teste: Remoção\n");

	int lixo;
	
	printf ("Remove início da lista\n");
	while (! lista_vazia(l)) {
		if (! remove_inicio_lista (&lixo,l))  return 0;
		insere_inicio_lista (lixo,o); 	
	}
	printf ("Tamanho lista l: %d\n", l->tamanho);
	
	printf ("Remove fim da lista\n");
	while (! lista_vazia(c)) {
		if (! remove_inicio_lista (&lixo,c)) return 0;
		insere_inicio_lista (lixo,p); 	
	}
	printf ("Tamanho lista c: %d\n", c->tamanho);

	printf ("Remove item\n");	
	if (! trmchvlist (o,p)) return 0;

	printf ("Tamanho lista o: %d\n", o->tamanho);
	printf ("Tamanho lista p: %d\n", p->tamanho);

	imprime_lista (o);
	imprime_lista (p);
	
	return 1;
}
int tinslista (t_lista *l, t_lista *c, t_lista *o, t_lista *p) {

	printf ("Teste: Insere nas listas\n");

	printf ("Insere no início da lista\n");
	if (! tinsprlist (l)) {
		printf ("ERRO: elemento não inserido\n");
		return 0;
	}
	printf ("Tamanho lista l: %d\n", l->tamanho);
	imprime_lista (l);

	printf ("Insere no fim da lista\n");
	if (! tinsfimlist(c)) {
		printf ("ERRO: elemento não inserido\n");
		return 0;
	}
	printf ("Tamanho lista c: %d\n", c->tamanho);
	imprime_lista (c);

	printf ("Insere ordenado na lista\n");
	if (! tinsordlist(c)) {
		printf ("ERRO: elemento não inserido\n");
		return 0;
	}
	printf ("Tamanho lista c: %d\n", c->tamanho);
	imprime_lista (c);

	return 1;
}
int main () {

	t_lista l,c,o,p;

	if (! tclista (&l,&c,&o,&p)) return 1;
	if (! tinslista(&l,&c,&o,&p)) return 1;
	if (! tremlista(&l,&c,&o,&p)) return 1;
	//if (! tatlista(&l,&c,&o,&o)) return 1;
	//if (! tperlista(&l,&c,&o,&p)) return 1;
	//if (! tdstlista(&l,&c,&o,&p)) return 1;
		
	return 0;

}
























