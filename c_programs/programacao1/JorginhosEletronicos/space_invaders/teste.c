#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <string.h>

#include "defstr_si.h"
#define DELAY 30000
#define MAX_X 38
#define MAX_Y 100

int main () {

	aliens et;
	int x = 0,y = 5;
	int max_x,max_y;
	int prox_x = 0,direcao = 1;

	strcpy (et.corpo1,ET11);
	strcpy (et.corpo2,ET12);
	strcpy (et.corpo3,ET13);

	initscr ();
	noecho ();
	curs_set (FALSE);
	getmaxyx (stdscr, max_y, max_x);

	while (1) {
		clear ();

		
		mvprintw (y,x,et.corpo1);
		mvprintw (y+1,x,et.corpo2);
		mvprintw (y+2,x,et.corpo3);
		refresh ();

		usleep (DELAY);

		prox_x = x + direcao;

		if (prox_x >= max_x || prox_x < 0)
			direcao *= -1;
		else
			x += direcao;

	}
	endwin ();
}
