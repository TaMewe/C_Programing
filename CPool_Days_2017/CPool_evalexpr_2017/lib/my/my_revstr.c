/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

int	my_swap2(char *a, char *b)
{
  char	i;

  i = *a;
  *a = *b;
  *b = i;
}

char	*my_revstr(char *str)
{
	int	i;
	int	j;
	int a = 0;
	
	i = 0;
	j = 1;
	while (str[i] != '\0'){
		i = i + 1;
	}
	while (j <= i / 2){
		my_swap2(&str[j - 1], &str[i - j]);
		j = j + 1;
	}
	while (str[a] != '\0'){
		a = a + 1;
	}
	return (str);
}

/* int main() */
/* { */
/* 	char str[3]; */
/* 	str[0] = 'L'; */
/* 	str[1] = 'o'; */
/* 	str[2] = '\0'; */
/* 	my_revstr(str); */
/* } */
