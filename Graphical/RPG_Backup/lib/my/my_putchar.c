/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/
#include <unistd.h>

void my_putchar(char c)
{
	write(1, &c, 1);
}

void my_put_error(char c)
{
	write(2, &c, 1);
}
