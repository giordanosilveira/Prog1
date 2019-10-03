#define MAX 100

struct pilha {
	int topo;
	char vetor[MAX];
};

typedef struct pilha tad_pilha;

/*inicializa pilha*/
void inicializa_pilha (tad_pilha *);

/*retorna 1 se a pilha esta vazia, caso contrário retorna 0*/
int pilha_vazia (tad_pilha *);

/*retorna o número de elementos da pilha*/
int tamanho_pilha (tad_pilha *);

/*empilha o inteiro x na pilha*/
/*retorna 1 se foi bem sucedido, 0 caso contrário*/
int empilha (float , tad_pilha *);

/*retorna em t o elemento do topo da pilha*/
/*retorna 1 se a operação foi bem sucedida, 0 caso contrário*/
int desempilha (float *, tad_pilha *);

/*retorna em t o elemento do topo da pilha sem desempilhar*/
/*retora 1 se a operação foi bem sucedida, 0 caso contrário*/
int topo (float *, tad_pilha *);
