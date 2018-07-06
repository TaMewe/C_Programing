/*
** EPITECH PROJECT, 2017
** str_to_word_array
** File description:
** str_to_word_array
*/

#include <stdlib.h>
#include <stdio.h>

char **copying(char **fin, char *str)
{
	int i = 0;
	int y = 0;
	int x = 0;

	for (; str[i] != '\0'; y++) {
		x = 0;
		for (; str[i] != ':' && str[i] != '\0'; i++, x++) {
			fin[y][x] = str[i];
		}
		fin[y][x] = '\0';
		for (; str[i] == ':'; i++);
	}
	return (fin);
}

char **mal_dimension(char **fin, char *str)
{
	int i = 0;
	int y = 0;
	int mal = 0;

	for (; str[i] != '\0'; y++, i++) {
		mal = 0;
		for (; str[i] != ':' && str[i] != '\0'; i++)
			mal++;
		fin[y] = malloc(sizeof(char) * (mal + 1));
	}
	fin = copying(fin, str);
	return (fin);
}

char **str_to_word_array(char *str)
{
	int mal = 0;
	char **fin;

	if (str == NULL) {
		return (NULL);
	}
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == ':')
			mal++;
	}
	if (str[0] == '\0') {
		fin = malloc(sizeof(char *) * (mal + 1));
		fin[0] = NULL;
		printf("LOOOOL\nLOOOL");
		return (fin);
	}
	fin = malloc(sizeof(char *) * (mal + 2));
	fin[mal + 1] = NULL;
	fin = mal_dimension(fin, str);
	return (fin);
}
