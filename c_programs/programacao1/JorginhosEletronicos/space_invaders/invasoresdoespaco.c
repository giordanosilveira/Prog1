#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <string.h>

#include "defstr_si.h"
#define DELAY 80000
#define MAX_X 38
#define MAX_Y 100
void initalins (t_aliens *et1, t_aliens *et2, t_aliens *et3) {
/*inicializa a struct aliens*/

	strcpy (et1->corpo1,ET11);
	strcpy (et1->corpo2,ET12);
	strcpy (et1->corpo3,ET13);
	et1->status = 1;
	et1->versao = 1;
	
	strcpy (et2->corpo1,ET21);
	strcpy (et2->corpo2,ET22);
	strcpy (et2->corpo3,ET23);
	et2->status = 1;
	et2->versao = 1;

	strcpy (et3->corpo1,ET31);
	strcpy (et3->corpo2,ET32);
	strcpy (et3->corpo3,ET33);
	et3->status = 1;
	et3->versao = 1;
}
void prnalienspsatual (t_aliens *et1, t_aliens *et2, t_aliens *et3, int coluna, int linha) {

	int i,j;

	for (i = 0; i < 5 ; i++) {	
		for (j = 0; j < 11; j++) {
			if (i == 0) {
				mvprintw (linha+4*i,coluna+7*j,et1->corpo1); 
				mvprintw (linha+4*i+1,coluna+7*j,et1->corpo2); 
				mvprintw (linha+4*i+2,coluna+7*j,et1->corpo3);
			}
			else if (i > 0 && i < 3) {
				mvprintw (linha+4*i,coluna+7*j,et2->corpo1); 
				mvprintw (linha+4*i+1,coluna+7*j,et2->corpo2); 
				mvprintw (linha+4*i+2,coluna+7*j,et2->corpo3);
			}
			else {
				mvprintw (linha+4*i,coluna+7*j,et3->corpo1);
				mvprintw (linha+4*i+1,coluna+7*j,et3->corpo2); 
				mvprintw (linha+4*i+2,coluna+7*j,et3->corpo3); 
			}
		}
	}
}
int main () {

  	t_aliens alien1, alien2, alien3;

        int pos_x, pos_y; /*Aonde eu printo na tela*/
        int max_x,max_y;
        int prox_x = 0,direcao = 1;

	initalins (&alien1,&alien2,&alien3);

        initscr ();
        noecho ();
        curs_set (FALSE);
        getmaxyx (stdscr, max_y, max_x);
		
	pos_x = 5;
	pos_y = 5;


        while (1) {
		
		clear ();

		prnalienspsatual (&alien1,&alien2,&alien3,pos_x,pos_y);

               	refresh ();
 
               	usleep (DELAY);

		prox_x = pos_x + direcao;
 
                if (prox_x >= 100 - 77|| prox_x < 0) {
			pos_y++;
                   	direcao *= -1;
		}
	        else
                        pos_x += direcao;
         }
         endwin ();
	 return 0;
 }
