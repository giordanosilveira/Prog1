struct t_nodo {
	int id;
	struct t_nodo *prox;
	struct t_nodo *prev;
}
typedef struct t_nodo t_nodo;
struct tipo_fila {
	t_nodo *ini;
	t_nodo *fim;
	int tam;
}

int inicializafila(tipo_fila F);
/*retorna 1 se inicializou com sucesso a fila ou zero caso contrário*/

int filavazia(tipo_fila F);
/*retorna 1 se a fila está vazia ou zero caso contrário;*/

int tamanho(tipo_fila F);
/*retorna o tamanho da fila.  Se a fila não existe retorna -1; */

int enfileira(int id, int t, tipo_fila F);
/*retorna 1 se inseriu com sucesso o id com autonomia de t UT’s no final da fila ou zero caso contrário; */

int desenfileira(int *id, int *t, tipo_fila F);
/*retorna 1 se desenfileirou com sucesso o id com autonomia de t UT’s que estava no início da fila ou zero caso contrário;*/

int removefila(int *id, int *t, tipo_fila F);
/*retorna 1 se removeu com sucesso o id que tinha autonomia de t UT’s da fila, não importa a posição que este id ocupa na fila, ou zero caso contrário;*/

void imprimefila(tipo_fila F); 
/*imprime a fila caso ela exista, senão não imprime nada.
