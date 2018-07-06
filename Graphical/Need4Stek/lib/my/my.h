/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include <stdlib.h>
#ifndef _MY_
# define _MY_

void my_putchar(char c);
int my_putstr(char *str);
int my_strlen(char *str);
int my_put_nbr(int nb);
void move(char *s, char **env);
void move_2(char *path);
void env_com(char **env);
char **system_command(char **env);
char **char_path(char **env, int i);
char **path_completion(char **path, char **env, int i);
void exe_ls(char **path, char *s);
char **ls_conv(char **path);
char **pwd_conv(char **path);
char **complete_copy(char **env, char **copy, char *s, char *var);
char **set_var(char **env, char *s);
char *var_complete(char *s);
char **new_env(char **env, char **copy, int lo, int la);
char *home_sweet_home(char **env);
char *home_reached(char *home, char **env, int line);
void exe_pwd(char **path, char *s);
int old_folder(char *s, char **env, int i, char *path);
char *old_pwd(char **env);
char *old_reached(char *old, char **env, int line);
char *option_ls(char *s);
int compare(char *str1, char *str2);
void exe_exe(char *s);
void commands(char *s, char **env);
void minishell(char **env);
char **tab(char *s);
char **fill_tab(char **tab, char *s, int nb);
char **git_conv(char **path);
void exe_git(char **path, char *s);
int nb_lines(char *s);
int next_commands(char *s, char **env);
int next_next_commands(char *s, char **env);
char **emacs_conv(char **path);
void exe_emacs(char **path, char *s);

#endif
