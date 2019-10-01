#include <stdio.h>
#include "tad_pilha_coord.h"

void main () {

	T_coord coordenada,banana;
	tad_pilha p;

	coordenada.x=8;
	coordenada.y=0;

	inicializa_pilha (&p);

	empilha (coordenada,&p);

	if (desempilha (&banana,&p))
		printf ("%d %d\n", banana.x, banana.y);

	if (desempilha (&banana,&p))
		printf ("É foda lek");
	else
		printf ("Carlinhos");

} 
