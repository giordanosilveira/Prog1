#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_palindromo (char *p,int t) {
	printf ("%c %c\n", *p, p[t]); 
	if (*p != p[t])
		return 0;
	if (t>0) {			 /*if ??*/	
		if (check_palindromo(p+1,t-2)) /*-2 pq a diferença entre o inicio e o final é igual a 2*/
			return 1;
	} 	
}
int main () {
	char *palavra;
        int tam,tam_str;
 
        scanf ("%d", &tam);
        palavra=(char *)malloc(tam*sizeof(char));
 
        if (palavra != NULL) {
                scanf ("%s", palavra);
		tam_str=strlen(palavra);
                if (check_palindromo (palavra,tam_str-1))
                         printf ("SIM\n");
                else
                         printf ("NÃO\n");
        }
 
        return 0;

}

	
