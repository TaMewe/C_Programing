/*
** EPITECH PROJECT, 2017
** realloc
** File description:
** realloc
*/

char *re_alloc(char *result, int size)
{
	char *new_res;
	int i = 0;

	new_res = malloc(sizeof(char) * (size + 1));
	if (result != NULL) {
		while (result[i] != '\0') {
			new_res[i] = result[i];
			i++;
		}
		new_res[i] = '\0';
	}
	free(result);
	return (new_res);
}
