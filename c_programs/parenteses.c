#include <stdio.h>
#include "tad_pilha.h"

int comparaparenteses (char open, char close) {
	if  (open == '(' && close == ')' )  return 1;
	else if ( open == '['  && close == ']'  ) return 1;
	else if ( open == '{'  && close == '}' ) return 1;
	return 0;
}
int main () {

	char x,y;
	tad_pilha p;

	inicializa_pilha (&p);
	
	scanf ("%c %c",&x, &y);	
	if ( comparaparenteses (x,y) != 1 ) {
		empilha (x,&p);
		empilha (y,&p);
	}
	scanf (" %c",&x);
	while (x != '0') {
		if (pilha_vazia(&p) == 1) {
			scanf (" %c",&y);
			if (comparaparenteses(x,y) != 1) {
				empilha (x,&p);
				empilha (y,&p);
			}
		}
		else {
			if (desempilha (&y,&p) == 1)
				if (comparaparenteses(y,x) != 1){
					empilha (y,&p);
					empilha (x,&p);
				}
		}
		scanf (" %c", &x);
	}
	if (pilha_vazia(&p) == 1)
		printf ("SIM\n");
	else
		printf ("NÃO\n");
	return 0;	
}

