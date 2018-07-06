#ifndef __STRUCT_H__
#define __STRUCT_H__

/**************************** INCLUDES *************************/

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

/**************************** STRUCTS *************************/

enum GUI_type {
	HUD_type,
	button_type,
	button_attack,
	button_guard,
	button_item,
	button_magic,
	button_flee,
	button_resume,
	button_save,
	button_settings,
	button_quit,
};

enum inv_tupe {
	contour_hud,
	inv_item,
	inv_magic,
	inv_stat,
};

typedef struct stat_s {
	int atk_p;
	int def_p;
	int atk_m;
	int def_m;
	int vit;
} stat_t;

typedef struct hero_s {
	int type;

	sfSprite *sprite;
	sfTexture *texture;
	sfVector2f position;
	sfVector2f scale;
	sfIntRect rect;
	int *hp;
	int *mp;
	int *xp;
	int lvl;
	stat_t *stat;
} hero_t;

typedef struct mob_s {
	sfSprite *sprite;
	sfTexture *texture;
	sfVector2f position;
	sfVector2f scale;
	sfIntRect rect;
	int *hp;
	int xp;
	int gold;
	int turn;
	stat_t *stat;
	sfMusic *fight_theme;

	struct mob_s *next;
} mob_t;

typedef struct window_s {
        sfRenderWindow *window;
        sfVideoMode mode;
	sfClock *clock;
	sfFont *font;
	sfText *text;
	int use;
	int pause;
} window_t;

typedef struct GUI_s
{
	int type;
	int button;
	sfSprite *sprite;
	sfTexture *texture;
	sfTexture *survol;
	sfIntRect rect;
	sfVector2f position;
	sfVector2f scale;

	struct GUI_s *next;
} GUI_t;

typedef struct inv_s
{
	int type;
	sfSprite *spr;
	sfTexture *text;
	sfIntRect rect;
	sfVector2f vec;
	sfVector2f sca;

	struct inv_s *next;
} inv_t;

typedef struct map_s
{
	char *map_1d;
        char *map_2d;
	char *map_coli;
        char **colision;
	char **map_c;
        char **map_d;
        sfSprite ***blocks_1d;
	sfSprite ***blocks_2d;
        sfTexture ***text_tab;
	sfTexture ***rem_text;
	sfTexture ***for_text;
        int lar;
        sfIntRect rect;
        sfSprite **bg;
        sfTexture *text;
        sfClock *clock;
        float seconds;
	int x;
	int y;
	sfMusic *Town;
	int play;
} map_t;

typedef struct exit_s
{
	//RectangleShape	*huge;
	int type;
	int button;
	sfSprite *sprite;
	sfTexture *texture;
	sfTexture *survol;
	sfIntRect rect;
	sfVector2f position;
	sfVector2f scale;

	struct exit_s *next;

}               exit_t;

/**************************** STRUCTS FOR MENU *************************/

typedef struct bg_s {
	sfSprite *p;
	sfSprite *h;
	sfSprite *p_i;
	sfTexture *t_p_i;
	sfTexture *t_h;
	sfTexture *t_p;
	sfVector2f pos;
	sfVector2f sca;
	sfVector2f o;

}bg_t;

typedef struct leaf_s {
	sfSprite *l;
	sfSprite *l_b;
	sfSprite *l_c;
	sfSprite *l_d;
	sfSprite *l_e;
	sfSprite *l_f;
	sfSprite *l_g;
	sfTexture *t_l;
	sfVector2f pos_g;
	sfVector2f sca_g;
	sfVector2f pos_f;
	sfVector2f sca_f;
	sfVector2f pos_e;
	sfVector2f sca_e;
	sfVector2f pos_d;
	sfVector2f sca_d;
	sfVector2f pos_c;
	sfVector2f sca_c;
	sfVector2f pos_b;
	sfVector2f sca_b;
	sfVector2f pos;
	sfVector2f sca;
	sfVector2f o;
	sfIntRect rect;
	int rand;

}leaf_t;

typedef struct cloud_s {
	sfSprite *a;
	sfSprite *b;
	sfSprite *c;
	sfSprite *c_b;
	sfSprite *c_c;
	sfTexture *t_a;
	sfVector2f pos_c_b;
	sfVector2f pos_c_c;
	sfVector2f pos_c;
	sfVector2f sca_c;
	sfVector2f pos_b;
	sfVector2f sca_b;
	sfVector2f pos_a;
	sfVector2f sca_a;
	sfVector2f o;

}cloud_t;

typedef struct ff_s {
	sfSprite *s;
	sfTexture *t;
	sfSprite *l;
	sfTexture *t_l;
	sfVector2f pos_l;
	sfVector2f sca_l;
	sfVector2f o_l;
	sfVector2f pos;
	sfVector2f sca;
	sfVector2f o;
	sfIntRect r;
	sfColor c;

}ff_t;

typedef struct music_s {
	sfMusic *sonic;
}music_t;

typedef struct menu_s {
	int on_menu;
	sfClock *clock;
	sfTime time;
	float seconds;
	bg_t bg;
	ff_t ff;
	cloud_t cloud;
	leaf_t leaf;
	music_t music;
}menu_t;

typedef struct object_s
{
	hero_t *hero;
	mob_t *mob;
	map_t *map;
	menu_t *menu;
	inv_t *inv;
	int pause;
} object_t;

#endif
