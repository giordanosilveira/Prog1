#include <stdio.h>
#include "tad_pilha.h"

int main () {

	char x;
	tad_pilha p;

	scanf ("%c", &x);
	printf ("%c", x);

	while (x != '0') {
		//empilha (x,&p);
		scanf ("%c", &x);
		printf ("%c", x);
	}
	return 0;	
}
