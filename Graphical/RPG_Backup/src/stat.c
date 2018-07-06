/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** C GRAPH PROG
*/

#include "rpg.h"

stat_t *warrior_stat()
{
	stat_t *stat = malloc(sizeof(stat_t));

	stat->atk_p = 7;
	stat->def_p = 6;
	stat->atk_m = 5;
	stat->def_m = 4;
	stat->vit = 3;
	return (stat);
}

stat_t *mage_stat()
{
	stat_t *stat = malloc(sizeof(stat_t));

	stat->atk_p = 3;
	stat->def_p = 3;
	stat->atk_m = 9;
	stat->def_m = 5;
	stat->vit = 5;
	return (stat);
}


stat_t *archer_stat()
{
	stat_t *stat = malloc(sizeof(stat_t));

	stat->atk_p = 7;
	stat->def_p = 4;
	stat->atk_m = 6;
	stat->def_m = 4;
	stat->vit = 4;
	return (stat);
}


stat_t *assassin_stat()
{
	stat_t *stat = malloc(sizeof(stat_t));

	stat->atk_p = 9;
	stat->def_p = 3;
	stat->atk_m = 4;
	stat->def_m = 3;
	stat->vit = 6;
	return (stat);
}


stat_t *druid_stat()
{
	stat_t *stat = malloc(sizeof(stat_t));

	stat->atk_p = 3;
	stat->def_p = 5;
	stat->atk_m = 7;
	stat->def_m = 5;
	stat->vit = 5;
	return (stat);
}
