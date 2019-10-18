#define MAX 100

struct coord {
	int x,y;
};
typedef struct coord T_coord;

struct pilha {
	int topo;
	T_coord vetor[MAX];
};

typedef struct pilha tad_pilha_coord;

/*inicializa pilha*/
void inicializa_pilha (tad_pilha *);

/*retorna 1 se a pilha esta vazia, caso contrário retorna 0*/
int pilha_vazia (tad_pilha *);

/*retorna o número de coordenadas da pilha*/
int tamanho_pilha (tad_pilha *);

/*empilha uma coordenada x na pilha*/
/*retorna 1 se foi bem sucedido, 0 caso contrário*/
int empilha (T_coord , tad_pilha *);

/*retorna em t a coordenada do topo da pilha*/
/*retorna 1 se a operação foi bem sucedida, 0 caso contrário*/
int desempilha (T_coord *, tad_pilha *);

/*retorna em t a coordenada do topo da pilha sem desempilhar*/
/*retora 1 se a operação foi bem sucedida, 0 caso contrário*/
int topo (T_coord *, tad_pilha *);


