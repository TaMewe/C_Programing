/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#ifndef _MY_
#define _MY_

#include "lib/my/get_next_line.h"

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
int my_swap(int *a, int *b);
int my_putstr(char *str);
int my_strlen(char *str);
int my_getnbr1(char *str);
void my_sort_int_tab(int *tab, int size);
int my_power_rec(int nb, int power);
int my_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strncpy(char *dest, char *src);
char *my_revstr(char *str);
char *my_strstr(char *str, char *to_find);
int my_strcmp(char *s1, char *s2);
int my_strncmp(char *s1, char *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char *str);
int my_str_isnum(char *str);
int my_str_islower(char *str);
int my_str_isupper(char *str);
int my_str_isprintable(char *str);
int my_showstr(char *str);
int my_showmem(char *str, int size);
char *my_strcat(char *dest, char *src);
char *my_strncat(char *dest, char *src, int nb);
int sum_stdarg(int i, int nb, ...);
int disp_stdarg(char *s, ...);
unsigned int my_base_10_to_2(unsigned int nb);
unsigned int my_base_10_to_8(unsigned int nb);
unsigned int my_base16(unsigned int nb);
unsigned int my_base16x(unsigned int nb);
int my_put_nbr_unsigned(unsigned int nb);
char * my_ret_base16(unsigned int nb);
int fs_open_file(char const *);
int my_getnbr(char *);
int put_tab(int **array, int lon, int lar);
void algo(char *str, int **tab, int lon, int lar);
int compare(int up, int up_l, int left);
void x_print(char *str, int **tab, int lon, int lar);
void x_print_next(char *str, int **tab, int *stock, int h_val);
void change_str(int h_val, char *str, int lon, int lar);
char *buffer_creation(char *buffer, char const *filepath);
int **filling_tab(char *str, int **tab);
int my_strlen_bsq(char *buffer);
char *get_next_line(int fd);
char **take_off_match(char **board, int line, int matches, int lines);
int check_win(char **board, int lines);
int error_line(char **board, int line, int matches, int lines);
int error_match(char **board, int line, int matches, int maxi);
char **display_player(int matches, int line, char **board, int lines);
char **ai(char **board, int lines, char *max);
char **display_ai(int m, int l, char **board, int lines);
char **create_interface();
char **interface_second_part(char **interface);
int random_tetrimino();
int put_tetrimino(char **ini_interface, char **interface);
char *my_strcpy(char *str);

#endif
