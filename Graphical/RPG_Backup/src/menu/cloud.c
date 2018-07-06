/*
** EPITECH PROJECT, 2018
** cloud.c
** File description:
** LORIS
*/

#include "rpg.h"

void ini_cloud(cloud_t *cloud)
{
	cloud->pos_a.x = 1300;
	cloud->pos_a.y = 400;
	cloud->sca_a.x = 1;
	cloud->sca_a.y = 1;
	cloud->pos_b.x = 200;
	cloud->pos_b.y = 100;
	cloud->sca_b.x = 2;
	cloud->sca_b.y = 2;
	cloud->pos_c.x = 600;
	cloud->pos_c.y = 0;
	cloud->sca_c.x = 0.4;
	cloud->sca_c.y = 0.4;
	cloud->pos_c_b.x = 1800;
	cloud->pos_c_b.y = 60;
	cloud->pos_c_c.x = 0;
	cloud->pos_c_c.y = 200;
	cloud->o.x = 1;
	cloud->o.y = 1;
}

int cloud(cloud_t *cloud)
{
	ini_cloud(cloud);
	if ((cloud->t_a = ini_tex("Sprite/menu/nuage_one.png")) == NULL)
		return (84);
	cloud->a = ini_sprite(cloud->t_a, cloud->pos_a, cloud->sca_a, cloud->o);
	cloud->b = ini_sprite(cloud->t_a, cloud->pos_b, cloud->sca_b, cloud->o);
	cloud->c = ini_sprite(cloud->t_a, cloud->pos_c, cloud->sca_c, cloud->o);
	cloud->c_b = ini_sprite(cloud->t_a, cloud->pos_c_b, cloud->sca_c, cloud->o);
	cloud->c_c = ini_sprite(cloud->t_a, cloud->pos_c_c, cloud->sca_c, cloud->o);
	return (0);
}

sfVector2f cloud_clock(int i, sfSprite *c, sfVector2f pos, float speed)
{
	sfSprite_setPosition(c, pos);
	pos.x = pos.x - speed;
	if (pos.x <= - i)
		pos.x = 1920;
	return (pos);
}
