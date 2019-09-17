#include<stdio.h>

void decrescente_recursivo (int n) {

	if (n>=1) {
		printf ("%d ", n);
		decrescente_recursivo (n-1);
	}
}

int main (void) {

	int n;

	scanf ("%d", &n);

	decrescente_recursivo (n);
	printf ("\n");

	return 0;
}
