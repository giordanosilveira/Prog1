#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int check_palindromo (char *palavra) {

	int tam,i;

	tam = strlen (palavra);
	for (i=0;i<tam;i++) { 
		if (palavra[i] != palavra[tam-i-1]) 
			return 0;
		printf (" %c = %c\n ",palavra[i], palavra[tam-i-1]);
	}
	return 1;
}
int main () {

	char *palavra;
	int tam;

	scanf ("%d", &tam);
	palavra=(char *)malloc(tam*sizeof(char));

	if (palavra != NULL) {
		scanf ("%s", palavra);
		if (check_palindromo (palavra))
			printf ("SIM\n");
		else
			printf ("NÃO\n");
	}

	return 0;
}
