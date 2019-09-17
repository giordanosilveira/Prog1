#include<stdio.h>

void crescente_recursivo (int n) {

	if (n>0) {
	        crescente_recursivo (n-1);
		printf ("%d ", n);
	}
}

int main (void) {

	int n;

	scanf ("%d", &n);

	crescente_recursivo (n);
	printf ("\n");

	return 0;
}
