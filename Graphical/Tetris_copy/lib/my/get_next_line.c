/*
** EPITECH PROJECT, 2018
** get_next_line.c
** File description:
** getnextline
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
# define READ_SIZE 10

int my_strlen7(char *c)
{
	int a = 0;

	while (c[a])
		a++;
	return (a);
}

char *re_malloc(char *only_line, int read_size)
{
	char *only_line2 = malloc(sizeof(char) *
				  (my_strlen7(only_line) + read_size));
	int x = 0;

	if (only_line2 == NULL)
		return (NULL);
	while (only_line[x]) {
		only_line2[x] = only_line[x];
		x++;
	}
	only_line2[x] = '\0';
	return (only_line2);
}

char get_next_line_char(int fd)
{
	static char *more;
	static int equal;
	char c;

	if (equal == 0)
	{
		more = malloc(sizeof(char) * READ_SIZE + 1);
		equal = read(fd, more, READ_SIZE);
		if (equal <= 0)
			return (0);
	}
	c = *more;
	equal--;
	more = more + 1;
	return (c);
}

char *get_next_line(int fd)
{
	char *only_line;
	char c;
	int i;

	i = 0;
	only_line = malloc(sizeof(char) * (READ_SIZE + 1));
	if (!only_line)
		return (NULL);
	c = get_next_line_char(fd);
	if (c == '\0')
		return (NULL);
	while (c != '\0' && c != '\n')
	{
		if (i % READ_SIZE == 0) {
			only_line = re_malloc(only_line, READ_SIZE);
			if (only_line == NULL)
				return (NULL);
		}
		only_line[i] = c;
		i = i + 1;
		c = get_next_line_char(fd);
	}
	only_line[i] = '\0';
	return (only_line);
}
