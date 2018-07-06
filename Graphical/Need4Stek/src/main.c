/*
** EPITECH PROJECT, 2017
** main
** File description:
** main
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/my.h"

void turn_left_right(char *str, size_t size, int less)
{
	if (less < 0) {
		my_putstr("WHEELS_DIR:-0.2\n");
		getline(&str, &size, stdin);
		my_putstr("CAR_FORWARD:0.2\n");
		getline(&str, &size, stdin);
	}
	if (less > 200) {
		my_putstr("WHEELS_DIR:0.2\n");
		getline(&str, &size, stdin);
		my_putstr("CAR_FORWARD:0.2\n");
		getline(&str, &size, stdin);
	}
}

void ia(void)
{
	char *str = NULL;
	char **parse = NULL;
	int less = 0;
	size_t size = 0;

	my_putstr("CAR_FORWARD:0.5\n");
	getline(&str, &size, stdin);
	while (1) {
		my_putstr("GET_INFO_LIDAR\n");
		getline(&str, &size, stdin);
		parse = str_to_word_array(str);
		if (parse[3] != NULL && parse[34] != NULL)
			less = atoi(parse[3]) - atoi(parse[34]);
		turn_left_right(str, size, less);
		if (less > 0 && less <= 200) {
			my_putstr("WHEELS_DIR:0\n");
			getline(&str, &size, stdin);
			my_putstr("CAR_FORWARD:0.5\n");
			getline(&str, &size, stdin);
		}
	}
}

int main(void)
{
	char *str = NULL;
	size_t size = 0;

	my_putstr("START_SIMULATION\n");
	getline(&str, &size, stdin);
	free(str);
	ia();
	return (0);
}
