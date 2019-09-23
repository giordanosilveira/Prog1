#include <stdio.h>
#define MAX 100
int palindromo (char *p,int t) {
	printf ("%c %c\n", *p, p[t]); 
	if (*p != p[t])
		return 0;
	if (t>0) {			 /*if ??*/	
		if (palindromo(p+1,t-2)) /*-2 pq a diferença entre o inicio e o final é igual a 2*/
			return 1;
	} 	
}
int main () {

	char palavra[MAX];
	int t,cont;

	scanf ("%s", palavra);
	t=0;
	while (*(palavra+t) != '\0'){
		t++;
		cont++;
	}
	if (palindromo (palavra,cont-1) == 1) /*menos 1 pq a última casa é '\0'*/
		printf ("É palindromo\n");
	else
		printf ("Não é palíndromo");
}

	
