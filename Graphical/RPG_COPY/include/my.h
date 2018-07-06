#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "struct.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#ifndef __MY_H__
#define __MY_H__

int my_strlen(char *str);
char *my_strcpy(char *str);
int my_strcmp(char *str1, char *str2);
window_t create_window(int width, int height, int bitsPerPixel);
int window_is_open();
map_t *ini_map();
void add_to_hero_list(hero_t *list, hero_t *add, int type);
hero_t take_to_hero_list(hero_t *list, int type);
void draw_hero_list(sfRenderWindow *window, hero_t *list);
void event_rpg(window_t window, map_t *map);
void key_pressed(sfEvent event, window_t window, map_t *map);
void map_creation(map_t *map_s);
sfSprite ***alloc_item(char **map, const char *filepath);
char **map_filling(const char *filepath);
char **alloc_map(char **map, const char *filepath);
int get_lar(const char *filepath);
void draw_map(map_t *map, sfRenderWindow *window);
void fill_sprite(sfSprite ***map_item, char **map, int *axe, sfTexture ***text);
void choose_text(char *filepath, sfSprite ***map_item, int *axe, sfTexture ***text);
void fill_sprite_2(sfSprite ***map_item, char **map, int *axe, sfTexture ***text);
void text_fire(map_t *map);
void destroy_map(char **, char **);
sfTexture ***alloc_text(char **map, const char *filepath);

#endif
