/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include <stdlib.h>

void my_putchar(char c);
void my_put_error(char c);

int my_putstr(char *str)
{
	int i = 0;

	if (str == NULL) {
		my_putstr("(null)");
		return(0);
	}
	while (str[i] != '\0')
	{
		my_putchar(str[i]);
		i = i + 1;
	}
	return (0);
}

int my_puterror(char *str)
{
	int i = 0;

	if (str == NULL) {
		my_putstr("(null)");
		return(0);
	}
	while (str[i] != '\0')
	{
		my_put_error(str[i]);
		i = i + 1;
	}
	return (0);
}
