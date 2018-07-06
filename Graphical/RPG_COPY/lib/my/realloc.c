/*
** EPITECH PROJECT, 2018
** realloc
** File description:
** realloc
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int my_strlen(char *str);

char *re_alloc(char *result, int size)
{
        char *new_res;
        int i = 0;

        new_res = malloc(sizeof(char) * (my_strlen(result) + size));
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
