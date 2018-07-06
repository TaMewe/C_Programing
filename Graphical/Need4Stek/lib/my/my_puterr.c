/*
** EPITECH PROJECT, 2017
** puterr
** File description:
** puterr
*/

#include <unistd.h>

int my_strlen(char *str);

void my_puterr(char *str)
{
	if (str == NULL) {
		write(2, "(null)", 6);
		return;
	}
	write(2, str, my_strlen(str));
}
