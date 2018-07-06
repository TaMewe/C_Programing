/*
** EPITECH PROJECT, 2017
**
** File description:
** strlen
*/

int my_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i = i + 1;
	return (i);
}
