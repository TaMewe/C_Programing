/*
** EPITECH PROJECT, 2018
** tetris
** File description:
** tetris
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <curses.h>
#include <stdlib.h>
#include "../my.h"

int help(char *str)
{
	int len = my_strlen(str);
	int fd;
	char *help;

	if (len != 2)
		return (0);
	if (str[0] == '-' && str[1] == 'h') {
		fd = open("help", O_RDONLY);
		if (fd == -1) {
			my_putstr("Could not find the help file.\n");
			return (0);
		}
		help = malloc(sizeof(char) * 1000);
		read(fd, help, 1000);
		my_putstr(help);
		my_putchar('\n');
		return (1);
	}
}

int debug(char *str)
{
	int len = my_strlen(str);
	int fd;
	char *help;

	if (len != 2)
		return (0);
	if (str[0] == '-' && str[1] == 'd') {
		fd = open("debug", O_RDONLY);
		if (fd == -1) {
			my_putstr("Could not find the debug file.\n");
			return (0);
		}
		help = malloc(sizeof(char) * 1000);
		read(fd, help, 1000);
		my_putstr(help);
		my_putchar('\n');
		return (1);
	}
}

int game()
{
	int key;
	int end = 0;
	char **interface = create_interface();
	char **ini_interface = create_interface();

	refresh();
	noecho();
	keypad(stdscr, TRUE);
	for (int i = 0; i != 22; i++)
		printw("%s\n", interface[i]);
	while(end != 1) {
		switch(key = getch()) {
		case 32:
			end = 1;
			break;
		case KEY_UP:
			put_tetrimino(ini_interface, interface);
			break;
		}
	}
	endwin();
	return (1);
}

int main(int argc, char **argv)
{
	if (argc == 2) {
		if (help(argv[1]) == 1)
			return (0);
		if (debug(argv[1]) == 1) {
			initscr();
			getchar();
			game();
			return (0);
		}
		my_putstr("Bad argument.\n");
		return (0);
	}
	initscr();
	game();
	return (0);
}
