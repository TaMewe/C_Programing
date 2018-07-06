/*
** EPITECH PROJECT, 2017
** my_strcpy
** File description:
** my_strcpy
*/

#include <stdlib.h>

int my_strlen(char *str);

char *my_strcpy(char *str)
{
	int len = my_strlen(str);
	char *ok = malloc(sizeof(char) * len + 1);

	for (int i = 0; i != len; i++)
		ok[i] = str[i];
	ok[len] = '\0';
	return (ok);
}
