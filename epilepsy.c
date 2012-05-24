/*
epilepsy - epilepsy.c
(ↄ) 2012 Lee
Released under the WTFPL
*/

#include <ncurses.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
	int ch;
	int rows, cols;
	int curr_col = 0;
	int pair_num;

	if (argc >= 2)
	{
		if (strcmp(argv[1], "-v") == 0)
		{
			printf("epilepsy 0.0.1 - (ↄ) 2012 Lee\nReleased under the WTFPL\n\n");
			exit(0);
		}
	}

	initscr();
	if(has_colors() == 0)
	{
		endwin();
		printf("Your terminal does not support colors\n");
		exit(1);
	}
	start_color();		
	raw();
	keypad(stdscr, TRUE);
	noecho();
	getmaxyx(stdscr, rows, cols);

	srand(time(NULL));

	init_pair(1, COLOR_BLACK, COLOR_BLACK);
	init_pair(2, COLOR_BLACK, COLOR_GREEN);
	init_pair(3, COLOR_BLACK, COLOR_YELLOW);
	init_pair(4, COLOR_BLACK, COLOR_BLUE);
	init_pair(5, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(6, COLOR_BLACK, COLOR_CYAN);
	init_pair(7, COLOR_BLACK, COLOR_WHITE);
	init_pair(8, COLOR_BLACK, COLOR_GREEN);
	init_pair(9, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(10, COLOR_BLACK, COLOR_WHITE);

	timeout(10);
	
	while(1)
	{
		ch = getch();
		if(ch == KEY_UP)
		{
			endwin();
			break;
		}
		for(int i = 0; i < rows; i++)
		{
			pair_num = rand() % 10 + 1;
			attron(COLOR_PAIR(pair_num));
			mvprintw(i,curr_col," ");
			attroff(COLOR_PAIR(pair_num));

			for(int j = 0; j < cols; j++)
			{
				pair_num = rand() % 10 + 1;
				attron(COLOR_PAIR(pair_num));
				mvprintw(i,j," ");
				attroff(COLOR_PAIR(pair_num));
			}
		}
		refresh();
	}
	return 0;
}