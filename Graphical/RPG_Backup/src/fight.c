/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** C GRAPH PROG
*/

#include "rpg.h"

void fight_screen(window_t window, object_t *object)
{
	static sfSprite *sp_background = NULL;
	static sfTexture *background = NULL;

	if (sp_background == NULL)
		sp_background = sfSprite_create();
	if (background == NULL)
		background = sfTexture_createFromFile("Sprite/fight_screen/background1.jpg", NULL);

	sfSprite_setTexture(sp_background, background, sfTrue);
	sfRenderWindow_drawSprite(window.window, sp_background, NULL);
	draw_sprite(window.window, object->mob->sprite, 1);
}

void fight_log(window_t window)
{
	static sfSprite *sprite = NULL;
	static sfTexture *texture = NULL;
	sfVector2f pos = { 545, 850 };
	sfVector2f scale = { 1.6, 1 };

	if (sprite == NULL) {
		sprite = sfSprite_create();
		texture = sfTexture_createFromFile("Sprite/fight_screen/Text_Box.png", NULL);
	}
	sfSprite_setTexture(sprite, texture, sfTrue);
	sfSprite_setPosition(sprite, pos);
	sfSprite_setScale(sprite, scale);
	draw_sprite(window.window, sprite, 1);
}

void ini_life_bar(window_t window, sfSprite **life_bar)
{
	static sfSprite *sprite = NULL;
	static sfTexture *texture = NULL;
	static sfTexture *t_life_bar = NULL;
	sfIntRect rect = {0, 185, 582, 85};

	if (*life_bar == NULL) {
		*life_bar = sfSprite_create();
		sprite = sfSprite_create();
		texture = sfTexture_createFromFile("Sprite/fight_screen/emptybar.png", NULL);
		t_life_bar = sfTexture_createFromFile("Sprite/fight_screen/fullbar.png", NULL);
	}
	sfSprite_setTexture(sprite, texture, sfTrue);
	sfSprite_setTexture(*life_bar, t_life_bar, sfTrue);
	sfSprite_setTextureRect(sprite, rect);
	sfSprite_setPosition(sprite, set_vector(575, 690));
	sfSprite_setScale(sprite, set_vector(1.6, 0.8));
	draw_sprite(window.window, sprite, 1);
}

void ini_mana_bar(window_t window, sfSprite **mana_bar)
{
	static sfSprite *sprite = NULL;
	static sfTexture *texture = NULL;
	static sfTexture *t_mana_bar = NULL;
	sfIntRect rect = {0, 0, 582, 85};

	if (*mana_bar == NULL) {
		*mana_bar = sfSprite_create();
		sprite = sfSprite_create();
		texture = sfTexture_createFromFile("Sprite/fight_screen/emptybar.png", NULL);
		t_mana_bar = sfTexture_createFromFile("Sprite/fight_screen/fullbar.png", NULL);
	}
	sfSprite_setTexture(sprite, texture, sfTrue);
	sfSprite_setTexture(*mana_bar, t_mana_bar, sfTrue);
	sfSprite_setTextureRect(sprite, rect);
	sfSprite_setPosition(sprite, set_vector(575, 775));
	sfSprite_setScale(sprite, set_vector(1.6, 0.8));
	draw_sprite(window.window, sprite, 1);
}

void bar_manager(window_t window, sfSprite **life, sfSprite **mana, hero_t *hero)
{
	static sfVector2f scale = {2.02, 0.72};
	sfIntRect life_jauge = part_jauge(set_rect(15, 365, 455, 85), hero->hp);
	sfIntRect mana_jauge = part_jauge(set_rect(15, 15, 455, 85), hero->mp);
	
	sfSprite_setPosition(*life, set_vector(580, 695));
	sfSprite_setPosition(*mana, set_vector(580, 782));
	sfSprite_setTextureRect(*life, life_jauge);
	sfSprite_setTextureRect(*mana, mana_jauge);
	sfSprite_setScale(*life, scale);
	sfSprite_setScale(*mana, scale);
	draw_sprite(window.window, *life, 1);
	draw_sprite(window.window, *mana, 1);
}
