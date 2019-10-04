#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "tad_pilha.h"

int eh_numero (char *str, int t) {
	
	char caracter;
	
	caracter = str[t-1];
	if (caracter == '+') return -4;
	if (caracter == '-') return -3;
	if (caracter == '*') return -2;
	if (caracter == '/') return -1;
	if (caracter == 'p') return 0;
	if (isdigit(caracter))
		return 1;
	return -5;
}
void efetua_operacao (char *str, long t, tad_pilha *p) {

	double var1,var2,res;

	switch (eh_numero(str,t)) {
		case -4 : 
		if (desempilha(&var2,p)) {
			if (desempilha(&var1,p)) {
				res = var2 + var1;
				empilha (res,p);
			}
			else { 
				res = var2 + var2;
				empilha(res,p);
			}
		}
		printf (">  %f\n", res);
		break;
				
		case -3 : 
		if (desempilha(&var2,p)) {
			if (desempilha(&var1,p)) {	
				res = var2 - var1;
				empilha (res,p);
			}
			else {
				res = var2 - var2;
				empilha (res,p);
			}
		}	
		printf ("> %f\n", res);
		break;
				
		case -2 : 
		if (desempilha(&var2,p)) {
			if (desempilha(&var1,p)) {
				res = var2 * var1;
				empilha (res,p);
			}
			else {
				res = var2*var2;
				empilha (res,p);
			}
		}
		printf ("> %f\n", res);
		break;			
					
		case -1 : 
		if (desempilha(&var2,p)) {
			if (desempilha(&var1,p)) {
				if (var2 == 0)
					printf ("ERRO: divisão por 0\n");
				else {
					res = var1 / var2;
					empilha (res,p);
				}
				
			}
			else {
				if (var2 == 0)
					printf ("ERRO: divisão por 0\n");
				else {
					res = var2/var2;
					empilha (res,p);
				}
			}
		}	
		printf ("> %f\n", res);
		break;
						
		case -5 : printf ("Entrada inválida\n");

	}
}
void le_string (char *s, long *t) {

	scanf ("%s", s);
	*t = strlen (s);
}


int main () {

	char str[MAX];
	long tam;
	double valor,resultado; 
	tad_pilha p;

	inicializa_pilha (&p);
	do { 
		le_string (str,&tam);
	} while (eh_numero (str,tam) != 1 && eh_numero(str,tam) != 0 && printf ("Entrada inválida\n"));
		
	if (eh_numero(str,tam) == 0)
		printf ("Resultado = 0\n");
	else if (eh_numero(str,tam) == 1) {
		valor = atof (str);
		empilha (valor,&p);

		while (eh_numero(str,tam) != 0) {
			le_string (str,&tam);
			if (eh_numero(str,tam) == 1) {
				valor = atof (str);
				empilha (valor,&p);
			}
			else 
				efetua_operacao (str,tam,&p);				
		}
		if (desempilha(&resultado,&p))
			printf ("Resultado = %f\n", resultado);
	}	
} 
