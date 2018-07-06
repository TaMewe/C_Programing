/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** my_getnbr
*/

int my_getnbr(char const *str)
{
	int i = 0;
	int a = 0;
	int b = 0;
	int multiplier = 1;

	for (; str[i] != '\0'; i++){
		for (; str[i] >= 48 && str[i] <= 57; i++){
			b = 1;
		}
		if (b == 1)
			i = i - 1;
		for (; str[i] >= 48 && str[i] <= 57; i--) {
			a = a + (str[i] - 48) * multiplier;
			multiplier = multiplier * 10;
		}
		if (b == 1) {
			return(a);
		}
	}
}
