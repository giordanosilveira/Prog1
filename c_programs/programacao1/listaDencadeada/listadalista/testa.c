#include <stdlib.h>
#include <stdio.h>

#include "lib_lista_complementar.h"

int ler_listas (t_lista *l) {

	int num;

	printf ("Escreva a até digitar um 0\n");
	scanf ("%d", &num);
	while (num != 0) {
		if (insere_fim_lista (num,l));
		scanf ("%d", &num);
	}
	
	return 1;
}

int main () {

	t_lista lst1, lst2, lst3, lst4, lst5;

	if (! inicializa_lista (&lst1)) return 1;
		printf ("Criando a primeira lista\n");	
	if (! inicializa_lista (&lst2)) return 1;
		printf ("Criando a segunda lista\n");	
	if (! inicializa_lista (&lst3)) return 1;	
		printf ("Criando a terceira lista\n");	
	if (! inicializa_lista (&lst4)) return 1;	
		printf ("Criando a quarta lista\n");	
	if (! inicializa_lista (&lst5)) return 1;	
		printf ("Criando a quinta lista\n");	

	printf ("Primeira lista\n");
	if (! ler_listas (&lst1)) return 1;	
	printf ("Segunda lista\n");
	if (! ler_listas (&lst2)) return 1;
	printf ("Terceira lista\n");
	if (! ler_listas (&lst3)) return 1;
	
	printf ("Tamanho da lista 1 %d\n", lst1.tamanho);
	imprime_lista (&lst1);	
	printf ("\n");

	printf ("Tamanho da lista 2 %d\n", lst2.tamanho);
	imprime_lista (&lst2);	
	printf ("\n");

	printf ("Tamanho da lista 3 %d\n", lst3.tamanho);
	imprime_lista (&lst3);	
	printf ("\n");

	printf ("Copiando a lista 1 para a lista 4\n");
	if (! copia_lista(&lst1,&lst4)) return 1;
		
	printf ("Tamanho da lista 4 %d\n", lst4.tamanho);
	imprime_lista (&lst4);
	printf ("\n");
	
	printf ("Concatenando a lista 2 para a lista 1\n");
	if (! concatena_listas (&lst1,&lst2)) return 1;
	
	printf ("Tamanho lista 1 %d\n", lst1.tamanho);
	imprime_lista (&lst1);
	printf ("\n");

	printf ("Ordenando a terceira lista\n");
	if (! ordena_lista(&lst3)) return 1;
	printf ("Tamanho lista 3 %d\n", lst3.tamanho);
	imprime_lista (&lst3);
	printf ("\n");
 	
	printf ("Ordenando a quarta lista\n");
	if (! ordena_lista(&lst4)) return 1;
	printf ("Tamanho lista 4 %d\n", lst4.tamanho);
	imprime_lista (&lst4);
	printf ("\n");

	printf ("Intercalando a lista3 e a lista4 na lista5\n");
	if (! intercala_listas(&lst3,&lst4,&lst5)) return 1;
	printf ("Tamanho lista 5 %d\n", lst5.tamanho);
	imprime_lista (&lst5);
	printf ("\n");

	printf ("Destuindo a lista 1\n");
	destroi_lista (&lst1);
	printf ("Tamanho da lista 1 %d ->", lst1.tamanho);
	imprime_lista (&lst1);
	printf ("\n");

	printf ("Destuindo a lista 2\n");
	destroi_lista (&lst2);
	printf ("Tamanho da lista 2 %d ->", lst2.tamanho);
	imprime_lista (&lst2);
	printf ("\n");

	printf ("Destuindo a lista 3\n");
	destroi_lista (&lst3);
	printf ("Tamanho da lista 3 %d ->", lst3.tamanho);
	imprime_lista (&lst3);
	printf ("\n");

	printf ("Destuindo a lista 4\n");
	destroi_lista (&lst4);
	printf ("Tamanho da lista 4 %d ->", lst4.tamanho);
	imprime_lista (&lst4);
	printf ("\n");

	printf ("Destuindo a lista 5\n");
	destroi_lista (&lst5);
	printf ("Tamanho da lista 5 %d ->", lst5.tamanho);
	imprime_lista (&lst5);
	printf ("\n");

	return 0;
}
