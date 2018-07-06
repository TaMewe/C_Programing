/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

int my_swap1(char *a, char *b)
{
	char i;

	i = *a;
	*a = *b;
	*b = i;
	return (0);
}

char *my_revstr(char *str)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (str[i] != 0)
		i = i + 1;
	while (j <= i / 2)
	{
		my_swap1(&str[j - 1], &str[i - j]);
		j = j + 1;
	}
	return (str);
}
