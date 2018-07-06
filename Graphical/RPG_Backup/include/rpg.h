#ifndef __RPG_H__
#define __RPG_H__

/******************* INCLUDES ****************/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "struct.h"
#include <time.h>

/******** stat.c *********/
stat_t *warrior_stat();
stat_t *mage_stat();
stat_t *archer_stat();
stat_t *assassin_stat();
stat_t *druid_stat();

/********** window.c *********/
window_t create_window(int width, int height, int bitsPerPixel);
int window_is_open();
void key_pressed(sfEvent event, map_t *map, hero_t *hero);
int poll_event(window_t window, object_t *object, GUI_t *HUD);
window_t draw_map(window_t window, object_t *object);

map_t *ini_map();

/************ tools.c ************/
sfVector2f set_vector(float x, float y);
sfIntRect set_rect(int left, int top, int width, int height);
void draw_sprite(sfRenderWindow *window, sfSprite *sprite, int use);
float create_time(sfClock *clock);
window_t window_use(window_t window, object_t *object, GUI_t *HUD);

/*********** mob.c **************/
void set_mob_life(window_t window, mob_t *mob);

/*********** list.c ************/
void add_to_hero_list(hero_t *list, hero_t *add, int type);
hero_t *take_to_hero_list(hero_t *list, int type);
void draw_hero_list(sfRenderWindow *window, hero_t *list);
void draw_button_list(sfRenderWindow *window, GUI_t *list);

/********** list2.c **********/
GUI_t *take_to_gui_list(GUI_t *list, int button);

void map_creation(map_t *map_s);
sfSprite ***alloc_item(char **map, const char *filepath, sfSprite ***item);
char **map_filling(const char *filepath, char **map);
char **alloc_map(char **map, const char *filepath);
int get_lar(const char *filepath);
void fill_sprite(sfSprite ***map_item, char **map, int *axe, sfTexture ***text);
void choose_text(char *filepath, sfSprite ***map_item, int *axe, sfTexture ***text);
void fill_sprite_2(sfSprite ***map_item, char **map, int *axe, sfTexture ***text);
void swap_1_to_tente(map_t *map, hero_t *hero, const char **zone1, const char **zone2);
void swap_tente_to_1(map_t *map, hero_t *hero, const char **zone1, const char **zone2);

/************ hero.c ***********/
hero_t *ini_hero(char *filepath);

/************ event.c ************/
int event_key_pressed(window_t window, sfEvent event, object_t *object);
int event_close_window(sfRenderWindow *window, sfEvent event);
int event_click(window_t window, sfEvent event, object_t *object, GUI_t *HUD);

/************ control.c ***********/
void key_left(hero_t *hero, map_t *map);
void key_right(hero_t *hero, map_t *map);
void key_up(hero_t *hero, map_t *map);
void key_down(hero_t *hero, map_t *map);
void move_control(hero_t *hero, map_t *map);

void destroy_map(char **, char **);
sfTexture ***alloc_text(char **map, const char *filepath, sfTexture ***item);
void text_fire(map_t *map);
void set_character(hero_t *hero, map_t *map);
void swap_1_to_2(map_t *map, hero_t *hero, const char **zone1, const char **zone2);
void swap_2_to_1(map_t *map, hero_t *hero, const char **zone1, const char **zone2);
void fight_screen(window_t window, object_t *object);
mob_t *ini_mob();

/************ map_specificities.c ***********/
void first_map_spe(window_t window, object_t *object, const char **zone_1);
void second_map_spe(window_t window, object_t *object, const char **zone_2);
void third_map_spe(window_t window, object_t *object, const char **zone_t);

/************ map_alloc.c ***********/
void free_old_text(map_t *map, int lar);
void keep_text_address(map_t *map, int lar);
void keep_other_address(map_t *map, int lar);

/*********** use.c **********/
void utility(window_t window, object_t *object, GUI_t *HUD);
int free_mode(window_t window, object_t *object);
int fight_mode(window_t window, object_t *object, GUI_t *HUD);
int menu_mode(window_t widnow, menu_t *menu);

/*********** mov_anim.c *********/
void anim_left(hero_t *hero, int x);
void anim_right(hero_t *hero, int x);
void anim_up(hero_t *hero, int y);
void anim_down(hero_t *hero, int y);
void anim_move(hero_t *hero, int x, int y);

/********** tools2.c ************/
sfIntRect set_area(GUI_t *object);
object_t *ini_object();
int check_button(sfRenderWindow *window, GUI_t *HUD, int button);
sfIntRect part_jauge(sfIntRect rect, int *percent);
void set_text(sfText *text, char *str, sfVector2f pos, sfColor color);

/******* fight_HUD.c **********/
GUI_t *create_button(char *filepath1, char *filepath2, sfVector2f position);
int survol_button(sfRenderWindow *window, GUI_t *button);
GUI_t *ini_fight_HUD();
GUI_t *ini_button_list();
int check_button(sfRenderWindow *window, GUI_t *button, int type);

/********* fight.c ********/
void fight_log(window_t window);
void ini_life_bar(window_t window, sfSprite **life_bar);
void ini_mana_bar(window_t window, sfSprite **mana_bar);
void bar_manager(window_t window, sfSprite **life, sfSprite **mana, hero_t *hero);

/********* damage_string.c ********/
char *my_strcat(char *first, char *next);
char *damage_string(int att, hero_t *hero, mob_t *mob);
int rand_attack(hero_t *hero, mob_t *mob);
char *damage_mob(int att, hero_t *hero, mob_t *mob);

/********* LIB ***********/
int my_strlen(char *str);
char *my_strcpy(char *str);
int my_strcmp(char *str1, char *str2);
char *my_get_str_nbr(int nb);

/*********** ini_sprite.c **********/
sfSprite *ini_sprite(sfTexture *path, sfVector2f pos, sfVector2f sca, sfVector2f o);
sfTexture *ini_tex(char *str);
sfIntRect ini_rect(int top, int left, int width, int height);

/****** fight_function.c *****/
window_t function_flee(window_t window);
void function_attack(window_t window, hero_t *hero, mob_t *mob, GUI_t *HUD);
void mob_attack(window_t window, hero_t *hero, mob_t *mob, GUI_t *HUD);

/****** music.c *****/
void stop_map_music(object_t *object);

/*********** menu *************/
void my_put_error(char c);
int my_puterror(char *str);
int ini_menu(menu_t *menu);
void draw_menu(menu_t *menu, sfRenderWindow *window);
void sprite_destroy_menu(menu_t *menu);
int bg(bg_t *bg);
int leaf(leaf_t *leaf);
sfVector2f leaf_clock(menu_t *menu, sfSprite *l, sfVector2f pos, float speed);
void ini_leaf(leaf_t *leaf);
sfVector2f rand_leaf(int rand, sfVector2f pos);
void ini_leaf_b(leaf_t *leaf);
int ini_music_menu(music_t *music);
int cloud(cloud_t *cloud);
sfVector2f cloud_clock(int i, sfSprite *c, sfVector2f pos, float speed);
void ini_cloud(cloud_t *cloud);
void sprite_destroy(menu_t *menu);
int final_fantasy(ff_t *ff);
void ff_clock(ff_t *ff);
void ini_ff(ff_t *ff);

/*********** inventory *************/
inv_t *ini_inventory(void);
inv_t *ini_HUD_inv(void);
inv_t *ini_button_inv(char *filepath, int type, sfVector2f vec);
void draw_inv(sfRenderWindow *window, inv_t *inv);
inv_t *take_to_inv(inv_t *list, int type);
int button_sca(sfRenderWindow *window, inv_t *button, int type);
void apply_sca(sfRenderWindow *window, inv_t *inv);
sfIntRect set_hitbox(inv_t *inv);
void wood_background_moving(sfRenderWindow *window, inv_t *inv);

/*********** Quit menu ***********/
GUI_t *sprite_on_buttons(char *path1, sfVector2f pos);
void    exit_init(exit_t *, sfVector2f pos, sfVector2f size);
void    print_success();
int     exit_is_clicked(exit_t *, sfVector2i mouse);
int     menu(sfRenderWindow *window);

#endif
