/*
** EPITECH PROJECT, 2018
** bg.c
** File description:
** LORIS
*/

#include "rpg.h"

int bg(bg_t *bg)
{
	bg->pos.x = 0;
	bg->pos.y = 0;
	bg->sca.x = 1;
	bg->sca.y = 1;
	bg->o.x = 1;
	bg->o.y = 1;
	if ((bg->t_p_i = ini_tex("Sprite/menu/bg_i.png")) == NULL)
		return (84);
	if ((bg->t_p = ini_tex("Sprite/menu/bg_plaine.jpg")) == NULL)
		return (84);
	if ((bg->t_h = ini_tex("Sprite/menu/herbe.png")) == NULL)
		return (84);
	bg->p_i = ini_sprite(bg->t_p_i, bg->pos, bg->sca, bg->o);
	bg->p = ini_sprite(bg->t_p, bg->pos, bg->sca, bg->o);
	bg->h = ini_sprite(bg->t_h, bg->pos, bg->sca, bg->o);
	return (0);
}

int ini_music_menu(music_t *music)
{
	music->sonic = sfMusic_createFromFile("audio/menu/sonic.ogg");
	if (!music->sonic) {
		my_puterror("ERROR: failed to load sonic_song");
		return (84);
	}
	sfMusic_play(music->sonic);
	sfMusic_setLoop(music->sonic, sfTrue);
	return (0);
}
