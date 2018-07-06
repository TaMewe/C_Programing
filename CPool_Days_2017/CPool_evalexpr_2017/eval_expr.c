/*
** EPITECH PROJECT, 2017
** eval_expr
** File description:
** 
*/
#include <stdlib.h>

char	*my_getnbr_char_star(int d, char const *str)
{
        int i = 0;
        int a = 0;
        int b = 0;
        int c = 0;
	char *result;
        int multiplier = 1;

        while (str[d] != '\0') {
                while (str[d] >= 48 && str[d] <= 57) {
                        if (str[d - 1] == '-') {
                                result[i] = '-';
				i = 1;
                        }
                        d = d + 1;
                        b = 1;
                }
                if (b == 1) {
                        d = d - 1;
                }
                while (str[d] >= 48 && str[d] <= 57) {
			result[i] = str[d];    
                        d = d - 1;
			i = i + 1;
                }
                if (b == 1) { 
                        return(result);
                }
                d = d + 1;
        }
}

char	*priority(int i, char *str)
{
	int a = 0;
	int i = 0;
	int j = 0;
	int end_if = 0;
	int len = my_strlen(str);
	int len_value1 = 0;
	int len_value2 = 0;
	char operator;
	char *value1;
	char *value2;
	char *both_values;

	value1 = malloc(sizeof(char) * len + 1);
	value2 = malloc(sizeof(char) * len + 1);
	both_values = malloc(sizeof(char) * len * 2 + 1); 
	if (str[i] == '(') {                        //Parenthèses
		value1 = my_getnbr_char_star(i, str);
		i = i + 1;
		while (str[i] >= 48 && str[i] <= 57) {
			i = i + 1;
			len_value1 = len_value1 + 1;
		}
		if (str[i] == '+' || '-' || '*' || '/' || '%' ) {
			operator = str[i];
			i = i + 1;
			value2 = my_getnbr_char_star(i, str);
			while (str[i] >= 48 && str[i] <= 57) {
				i = i + 1;
				len_value2 = len_value2 + 1;
				end_if = 1;
			}
		}
		if (end_if == 1) {
			while (j != len_value1) {
				both_values[j] = value1[j];
				j = j + 1;
			}
			both_values[j] = operator;
			while (a != len_value2) {
				both_values[j] = value2[a];
				j = j + 1;
				a = a + 1;
			}
			both_values[j] = '\0';
			return(both_values);					
		}
	}
	if (str[i] == '*' || '/' || '%' ) { //Multiplication ...
		operator = str[i];
		value2 = my_getnbr_char_star(i, str);
		i = i - 1;
		while (str[i] >= 48 && str[i] <= 57) {
			i = i - 1;
			len_value1 = len_value1 + 1;
		}
		i = i + 1;
		value1 = my_getnbr_char_star(i, str);
		while (str[i] != operator) {
			i = i +1;
		}
		while (str[i] >= 48 && str[i] <= 57) {
			len_value2 = len_value2 + 1;
			i = i + 1;
			end_if = 1;
		}
		if (end_if == 1) {
			while (j != len_value1) {
	                        both_values[j] = value1[j];
		                j = j + 1;
                        }
			both_values[j] = operator;
                        while (a != len_value2) {
                                both_values[j] = value2[a];
				j = j + 1;
		                a = a + 1;
	                }
                        both_values[j] = '\0';
			return(both_values);
                }
	}
}

char	*eval_expr(char *str)
{
	int i = 0;
	int j = 0;
	int parentheses = 0;
	char *both_values;
	char *result;
	
	while (str[i] != '\0') {
		if (str[i] == '(') {
			parentheses = parentheses + 1;
		}
	}
	if (parentheses != 0) {
		while (j != parentheses) {
			while (str[i] != '\0') {
				if (str[i] == ')') {
					while (str[i] != '(') {
						i = i - 1;
					}
					both_values = priority(i, str);
					//Calcul
				}
				i = i + 1;
			}
			j = j + 1;
		}
		if (str[i] == '*' || '/' || '%' ) {
			result = priority(i, str);
			//Calcul
		}
	}

	int	main(int ac, char **av)
	{
		if (ac == 2) {
			my_putstr(eval_expr(av[1]));
			my_putchar('\n');
			return(0);
		}
		return(84);
	}
