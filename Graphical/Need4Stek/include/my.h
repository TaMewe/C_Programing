/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include <unistd.h>
#include <stdlib.h>
#ifndef _MY_
# define _MY_

void my_putchar(char c);
void my_putstr(char *str);
void my_puterr(char *str);
int my_getnbr(const char *str);
int my_strlen(char *str);
int my_put_nbr(int nb);
void move(char *s, char **env, char **parse);
void move_2(char *path);
void env_com(char **env);
char **system_command(char **env);
char **char_path(char **env, int i);
char **path_completion(char **path, char **env, int i);
void exe_ls(char **path, char *s, char **parse);
char **ls_conv(char **path, char *str, char **parse);
char **pwd_conv(char **path);
char **complete_copy(char **env, char **copy, char *s, char *var);
char **set_var(char **env, char *s);
char *var_complete(char *s);
char **new_env(char **env, char **copy, int lo, int la);
char *home_sweet_home(char **env);
char *home_reached(char *home, char **env, int line);
void exe_pwd(char **path, char *s, char **parse);
int old_folder(char *s, char **env, char **parse);
char *old_pwd(char **env);
char *old_reached(char *old, char **env, int line);
char *option_ls(char *s);
int compare(char *str1, char *str2);
void exe_exe(char *s, char **parse);
void commands(char *s, char **env, char **parse);
void minishell(char **env);
char **tab(char *s);
char **fill_tab(char **tab, char *s, int nb);
char **git_conv(char **path);
void exe_git(char **path, char *s, char **parse);
int nb_lines(char *s);
int next_commands(char *s, char **env, char **parse);
int next_next_commands(char *s, char **env, char **parse);
char **emacs_conv(char **path);
void exe_emacs(char **path, char *s, char **parse);
char **old_ls_conv(char **path);
char **my_parser(char *str);
int print_prompt(char *pwd);
char ***parse_command(char **d_str);
void clean_semicolons(char ***end);
int some_more_commands(char *s, char **env, char **parse);
char *get_next_line(int fd);
char **str_to_word_array(char *str);
char *my_get_str_nbr(int nb);
char *my_revstr(char *str);

#endif
