/*
** EPITECH PROJECT, 2017
** putstr
** File description:
** putstr
*/

#include <unistd.h>

int my_strlen(char *str);

void my_putstr(char *str)
{
	if (str == NULL) {
		write(1, "(null)", 6);
		return;
	}
	write(1, str, my_strlen(str));
	return;
}
