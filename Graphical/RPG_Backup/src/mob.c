/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** C GRAPH PROG
*/

#include "rpg.h"

mob_t *ini_mob()
{
	mob_t *mob = malloc(sizeof(mob_t));
	int xp = 50;
	int gold = 50;

	mob->sprite = sfSprite_create();
	mob->texture = sfTexture_createFromFile("Sprite/Mob/Chevalier_Mage.png", NULL);
	mob->position = set_vector(700, 100);
	mob->scale = set_vector(4, 4);
	mob->rect = set_rect(0, 0, 96, 96);
	mob->hp = malloc(sizeof(int) * 2);
	mob->xp = xp;
	mob->gold = gold;
	mob->stat = mage_stat();
	mob->next = NULL;
	mob->hp[0] = 20;
	mob->hp[1] = 20;
	mob->turn = 0;
	mob->fight_theme = sfMusic_createFromFile("audio/fight/fight_theme.ogg");
        if (!mob->fight_theme)
                my_puterror("ERROR: failed to load fight music.\n");
        sfMusic_setLoop(mob->fight_theme, sfTrue);
	sfSprite_setTexture(mob->sprite, mob->texture, sfTrue);
	sfSprite_setPosition(mob->sprite, mob->position);
	sfSprite_setScale(mob->sprite, mob->scale);
	return (mob);
}

void set_mob_life(window_t window, mob_t *mob)
{
	static sfFont *font = NULL;
	static sfText *text = NULL;
	char *life = my_get_str_nbr(mob->hp[0]);

	if (text == NULL && font == NULL) {
		font = sfFont_createFromFile("Sprite/Font/font.ttf");
		text = sfText_create();
	}
	set_text(text, life, set_vector(900, 120), sfWhite);
	sfText_setScale(text, set_vector(2.5, 2.5));
	sfRenderWindow_drawText(window.window, text, NULL);
}
