/*
** EPITECH PROJECT, 2018
** put_form
** File description:
** put_form
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <curses.h>
#include <stdlib.h>
#include "../my.h"

int random_tetrimino()
{
	int random = rand() % 5;
	int fd;

	switch(random) {
	case 0:
		fd = open("tetrimino/5.tetrimino", O_RDONLY);
		break;
	case 1:
		fd = open("tetrimino/6.tetrimino", O_RDONLY);
		break;
	case 2:
		fd = open("tetrimino/bar.tetrimino", O_RDONLY);
		break;
	case 3:
		fd = open("tetrimino/inverted-L.tetrimino", O_RDONLY);
		break;
	case 4:
		fd = open("tetrimino/square.tetrimino", O_RDONLY);
		break;
	}
	return (fd);
}

int put_tetrimino(char **ini_interface, char **interface)
{
	int fd = random_tetrimino();
	char buffer[50];
	int k = 0;

	interface[1] = my_strcpy(ini_interface[1]);
	interface[2] = my_strcpy(ini_interface[2]);
	interface[3] = my_strcpy(ini_interface[3]);
	interface[4] = my_strcpy(ini_interface[4]);
	read(fd, buffer, 50);
	for (int i = 1; i != 5; i++, k++) {
		for (int j = 43; j != 45; j++, k++) {
			if (buffer[k] == '*')
				interface[i][j] = buffer[k];
		}
	}
	clear();
	for (int i = 0; i != 22; i++)
		printw("%s\n", interface[i]);
	return (0);
}
