/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#ifndef _MY_
#define _MY_

#include "lib/my/get_next_line.h"
#include "tetris.h"

void my_putchar(char c);
int my_put_nbr(int nb);
int my_swap(int *a, int *b);
int my_putstr(char *str);
int my_strlen(char *str);
int my_getnbr1(char *str);
void my_sort_int_tab(int *tab, int size);
char *my_strncpy(char *dest, char *src);
char *my_revstr(char *str);
char *my_strstr(char *str, char *to_find);
int my_strcmp(char *s1, char *s2);
int my_strncmp(char *s1, char *s2, int n);
char *my_strcat(char *dest, char *src);
char *my_strncat(char *dest, char *src, int nb);
int my_getnbr(char *);
char *get_next_line(int fd);
char **create_interface();
char **interface_second_part(char **interface);
int random_tetrimino();
int put_tetrimino(char **ini_interface, char **interface, int *map_size);
char *my_strcpy(char *str);
int debug(char *str);
int game(keys_t *key, int *map_size, int next);
int help(char *str);
int manage_arg(int argc, char **argv, keys_t *key, int *map_size);
void keys(char **argv, int i, keys_t *key);
int without_next(char *str);
char **info_score();
char **map_create(int lar, int lon, int next);
char **map_fill(char **map, int lar, int lon);
int map_dimensions(char *str, int *map_size);
char *copy_begin(char *str);
char **next_tetri();
char **game_name();
char **shifting(char **str, int lar, char **info);
void disp_interface(char **interface, int *map_size);
char **shifting_next(char **str, int lar, char **info, char **next_tet);
void debug_display(keys_t *key, int next, int *map_size);
void fill_debug(char **debug, keys_t *key, int next, int *map_size);
char *bind_key_debug(char *debug, int key);
char *re_alloc(char *result, int size);
int special_key(char *debug, int key, int i);
char **key_part(char **debug, keys_t *key);
char *size_line(char *str, int *map_size, int i);
char *assembling(char *str, int i, char *nb1, char *nb2);
char *get_nb1(int nb_size, char *nb1, int unity);
void count_manage(keys_t *key, int next, int *map_size);
char **get_file_name();
void display_files(char **files);
void display_name_size(char **files, int i);

#endif
