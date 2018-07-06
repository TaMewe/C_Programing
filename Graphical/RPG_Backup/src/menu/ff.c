/*
** EPITECH PROJECT, 2018
** ff.c
** File description:
** LORIS
*/

#include "rpg.h"

void ini_ff(ff_t *ff)
{
	ff->pos.x = 1060;
	ff->pos.y = 220;
	ff->sca.x = 0;
	ff->sca.y = 0;
	ff->o.x = 1000;
	ff->o.y = 300;
	ff->o_l.x = 280;
	ff->o_l.y = 40;
	ff->pos_l.x = 850;
	ff->pos_l.y = 320;
	ff->sca_l.x = 0;
	ff->sca_l.y = 0;
	ff->c.r = 255;
	ff->c.b = 255;
	ff->c.g = 255;
	ff->c.a = 255;
}

int final_fantasy(ff_t *ff)
{
	ini_ff(ff);
	if ((ff->t = ini_tex("Sprite/menu/f.png")) == NULL)
		return (84);
	if ((ff->t_l = ini_tex("Sprite/menu/light.png")) == NULL)
		return (84);
	ff->s = ini_sprite(ff->t, ff->pos, ff->sca, ff->o);
	ff->l = ini_sprite(ff->t_l, ff->pos_l, ff->sca_l, ff->o_l);
 	return (0);
}

void ff_clock(ff_t *ff)
{
	static int i = 0;

	i = i + 1;
	if (i >= 30) {
		ff->sca.x = ff->sca.x + 0.06;
		ff->sca.y = ff->sca.y + 0.06;
		ff->sca_l.x = ff->sca_l.x + 0.06;
		ff->sca_l.y = ff->sca_l.y + 0.06;
		sfSprite_setScale(ff->s, ff->sca);
		sfSprite_setScale(ff->l, ff->sca_l);
		sfSprite_setColor(ff->l, ff->c);
		if (ff->c.a <= 2)
			ff->c.a = 2;
		if (ff->sca_l.x >= 1) {
			ff->sca_l.y = 1;
			ff->c.a = ff->c.a - 2;
		}
		if (ff->sca.x >= 0.6) {
			ff->sca.x = 0.6;
			ff->sca.y = 0.6;
		}
	}
}
