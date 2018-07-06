/*
** EPITECH PROJECT, 2018
** my_strcmp
** File description:
** my_strcmp
*/

int my_strlen(char *str);

int my_strcmp(char *str1, char *str2)
{
	int len1 = my_strlen(str1);
	int len2 = my_strlen(str2);
	int i = 0;
	int j = 0;

	if (len1 == len2) {
		while (i != len2) {
			if (str1[j] == str2[i]) {
				i++;
				j++;
			}
			else
				return (0);
		}
		return (1);
	}
	else {
		return (0);
	}
}
