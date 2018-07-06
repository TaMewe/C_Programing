/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "../include/my.h"

elem_t *add_path(elem_t *elem)
{

}

char **get_info()
{
	char **info = malloc(sizeof(char *) * 100);
        char *s;
	int i = 0;

        for (;(s = get_next_line(0)) != NULL; i++) {
                info[i] = s;
	}
        info[i] = NULL;
	return (info);
}

int main(int argc, char **argv)
{
	char **info = get_info();

	for (int j = 0; info[j] != NULL; j++) {
		my_putstr(info[j]);
		my_putchar('\n');
	}
	analyse_room_path(info);
	return (0);
}
