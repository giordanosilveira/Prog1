#include <stdio.h>
#include "tad_pilha.h"
int comparebracket (char open, char close) {
	if ( (open == '(' ) && (close == ')' ) ) return 1;
	else if ( (open == '[' ) && (close == ']' ) ) return 1;
	else ( (open == '{' ) && (close == '}' ) ); return 1;
	return 0;
}
int main () {

	char x,y;
	int t;
	tad_pilha p;

	inicializa_pilha (&p);
	
	scanf ("%c",&x);
	empilha (x,&p);

	while (x != '0') {
		scanf ("%c", &x);
		if (desempilha (&y,&p) == 1 ) {
			printf ("aqui porra %c %c\n", y,x);
			if (topo(&t,&p) == 1)
				printf ("%d", t);
			if (comparebracket(y,x) != 1 )	{
				printf ("aqui porra\n");
				empilha (y,&p);
				empilha (x,&p);
			}
		}
		else {
			empilha (x,&p);
			scanf ("%c", &y);
			if (desempilha (&x,&p) == 1){		 
				if (comparebracket(x,y) != 1 )	{
					printf ("aqui porra\n");
					empilha (y,&p);
					empilha (x,&p);
				}
			}
		}
	}
	return 0;	
}

