/*
welcome - welcome.c
(ↄ) 2012 Lee
Released under the WTFPL

Compiles with "gcc -lncurses welcome.c -std=c99 -Wall -Wshadow -Wextra"

*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // Sleep function

#include <ncurses.h>

int main()
{
	char msg[64];
	char *username = getenv("USER");
	if (username == NULL) return 1;
	strcpy(msg, "Welcome, ");
	strcat(msg, username);
	strcat(msg, ".");

	int rows, cols;

	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
	getmaxyx(stdscr, rows, cols);

	if(has_colors())
	{
		start_color();

		init_pair(1, COLOR_WHITE, COLOR_BLACK);
		for(int i = 0; i < rows; i++)
		{
			for(int j = 0; j < cols; j++)
			{
				attron(COLOR_PAIR(1));
				mvprintw(i,j," ");
				attroff(COLOR_PAIR(1));
			}
		}
	}

	mvprintw(rows/2,(cols-strlen(msg))/2,msg);
	refresh();
	sleep(2);

	endwin();
	return 0;
}
