/*
** EPITECH PROJECT, 2018
** leaf.c
** File description:
** LORIS
*/

#include "rpg.h"

void ini_leaf(leaf_t *leaf)
{
	leaf->pos.x = 1000;
	leaf->pos.y = 300;
	leaf->sca.x = 0.2;
	leaf->sca.y = 0.2;
	leaf->o.x = 0;
	leaf->o.y = 0;
	leaf->pos_b.x = 1200;
	leaf->pos_b.y = 280;
	leaf->sca_b.x = 0.2;
	leaf->sca_b.y = 0.2;
	leaf->pos_c.x = 1400;
	leaf->pos_c.y = 100;
	leaf->sca_c.x = 0.2;
	leaf->sca_c.y = 0.2;
	leaf->pos_d.x = 1000;
	leaf->pos_d.y = 100;
	leaf->sca_d.x = 0.2;
	leaf->sca_d.y = 0.2;
	ini_leaf_b(leaf);
}

int leaf(leaf_t *leaf)
{
	ini_leaf(leaf);
	if ((leaf->t_l = ini_tex("Sprite/menu/leaf_b.png")) == NULL)
		return (84);
	leaf->l = ini_sprite(leaf->t_l, leaf->pos, leaf->sca, leaf->o);
	leaf->l_b = ini_sprite(leaf->t_l, leaf->pos_b, leaf->sca_b, leaf->o);
	leaf->l_c = ini_sprite(leaf->t_l, leaf->pos_c, leaf->sca_c, leaf->o);
	leaf->l_d = ini_sprite(leaf->t_l, leaf->pos_d, leaf->sca_d, leaf->o);
	leaf->l_e = ini_sprite(leaf->t_l, leaf->pos_e, leaf->sca_e, leaf->o);
	leaf->l_f = ini_sprite(leaf->t_l, leaf->pos_f, leaf->sca_f, leaf->o);
	leaf->l_g = ini_sprite(leaf->t_l, leaf->pos_g, leaf->sca_g, leaf->o);
	leaf->rect = ini_rect(0, 0, 180, 83);
	sfSprite_setTextureRect(leaf->l, leaf->rect);
	sfSprite_setTextureRect(leaf->l_b, leaf->rect);
	sfSprite_setTextureRect(leaf->l_c, leaf->rect);
	sfSprite_setTextureRect(leaf->l_d, leaf->rect);
	sfSprite_setTextureRect(leaf->l_e, leaf->rect);
	sfSprite_setTextureRect(leaf->l_f, leaf->rect);
	sfSprite_setTextureRect(leaf->l_g, leaf->rect);
	return (0);
}

sfVector2f leaf_clock(menu_t *menu, sfSprite *l, sfVector2f pos, float speed)
{
	int r = 0;

	srand(time(0));
	r = rand()%7;
	sfSprite_setTextureRect(l, menu->leaf.rect);
	menu->leaf.rect.left = menu->leaf.rect.left + 180;
	if (menu->leaf.rect.left >= 2700) {
		menu->leaf.rect.left = 0;
		menu->leaf.rect.top = menu->leaf.rect.top + 88;
	}
	if (menu->leaf.rect.top >= 440) {
		menu->leaf.rect.top = 0;
	}
	sfSprite_setPosition(l, pos);
	pos.y = pos.y + speed + 0.7;
	pos.x = pos.x - speed - 0.3;
	if (pos.y >= 1080) {
		pos = rand_leaf(r, pos);
	}
	return (pos);
}

sfVector2f rand_leaf(int rand, sfVector2f pos)
{
	if (rand == 0) {
		pos.y = 0;
		pos.x = 1900;
	}
	else if (rand == 1) {
		pos.y = 0;
		pos.x = 1500;
	}
	else if (rand == 2) {
		pos.y = 0;
		pos.x = 1800;
	}
	else if (rand == 3) {
		pos.y = 0;
		pos.x = 1000;
	}
	else if (rand == 4) {
		pos.y = 0;
		pos.x = 1300;
	}
	else if (rand == 5) {
		pos.y = 0;
		pos.x = 1200;
	}
	else if (rand == 6) {
		pos.y = 0;
		pos.x = 1700;
	}
	return (pos);
}
