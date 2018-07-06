/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/
#include <stdlib.h>

int my_putchar(char c);
int my_putstr(char *str);
int my_revstr(char *str);
char *my_strcpy(char *str);

int negative(int nb2)
{
	if (nb2 < 0) {
		nb2 = nb2 * -1;
	}
	return(nb2);
}

char *my_get_str_nbr(int nb)
{
	int i = 0;
	char *str;
	int nb2 = nb;
	int len = 0;

	nb2 = negative(nb2);
	for (; nb != 0; len++)
		nb = nb / 10;
	str = malloc(sizeof(char) * len + 1);
	if (nb2 == 0) {
		free(str);
		str = my_strcpy("0");
		return (str);
	}
	for (int ret = 0; nb2 != 0; i++, nb2 = nb2 / 10) {
		ret = nb2 % 10;
		str[i] = ret + 48;
	}
	str[i] = '\0';
	my_revstr(str);
	return (str);
}
