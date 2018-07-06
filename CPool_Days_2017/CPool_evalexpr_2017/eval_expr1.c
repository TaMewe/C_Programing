/*
** EPITECH PROJECT, 2017
** eval_expr
** File description:
** 
*/
#include <stdlib.h>
/*
int     my_strtol(char *str, char *after_nbr)
{
        int i = 0;
        int result = 0;
        int b = 0;
        int a =	0;
        int multiplier = 1;

        while (str[i] != '\0') {
                while (str[i] >= 48 && str[i] <= 57) {
                        result = result + multiplier * (str[i] - 48);
			multiplier = multiplier * 10;
                        i = i + 1;
                        b = 1;
		}
                if (b == 1) {
			after_nbr = str[i];
			str = &after_nbr;
			my_put_nbr(result);
			return(result);
                }
                i = i + 1;
        }
}
*/

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

char	*priority(char *str)
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
	while (str[i] != '\0') {
		if (str[i] == '(') {                        //Parenthèses
			value1 = my_getnbr_char_star(i, str);
			i = i + 1;
			while (str[i] >= 48 && str[i] <= 57) {
				i = i + 1;
				len_value1 = len_value1 + 1;
			}
			if (str[i] == "+" || "-" || "*" || "/" || "%" ) {
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
		i = i + 1;
	}
}

int	eval_expr(char *str)
{
	int result = 0;
	int len = my_strlen(str);
	int value1;
	int value2;
	int i = 0;
	int plus = 0;
	int sub = 0;
	char operator;

	while (i != len) {
		while (str[i] >= 48 && str[i] <= 57) {
			value1 = my_strtol(str, str);
			i = i + 1;
		}
		while (str[i] < 48 && str[i] > 57) {
			if (str[i] == '+') {
				operator = str[i];
				plus = 1;		
			}
			if (str[i] == '-') {
				operator = str[i];
				sub = 1;
			}
			i = i + 1;
		}
		while (str[i] >=48 && str[i] >= 57) {
			value2 = my_strtol(str, str);
			i = i + 1;
		}
		if (plus == 1) {
			result = value1 + value2;
		}
		if (sub == 1) {
			result = value1 - value2;
		}
		i = i + 1;
	}
	return(result);
}

int	main(int ac, char **av)
{
	if (ac == 2) {
		my_put_nbr(eval_expr(av[1]));
		my_putchar('\n');
		return(0);
	}
	return(84);
}
