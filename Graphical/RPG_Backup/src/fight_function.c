/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** C GRAPH PROG
*/

#include "rpg.h"

window_t function_flee(window_t window)
{
	window.pause = 1;
	set_text(window.text, "You are fleeing the fight.\nLet's click here >",
		 set_vector(600, 870), sfBlack);
	sfText_setScale(window.text, set_vector(1.5, 1.5));
	return (window);
}

void function_attack(window_t window, hero_t *hero, mob_t *mob, GUI_t *HUD)
{
	int att = rand_attack(hero, mob);

	if (check_button(window.window, HUD, button_attack) == 1 && mob->turn == 0) {
		mob->hp[0] = mob->hp[0] - att;
		if (mob->hp[0] < 0)
			mob->hp[0] = 0;
		set_text(window.text, damage_string(att, hero, mob),
			 set_vector(600, 870), sfBlack);
		sfText_setScale(window.text, set_vector(1.5, 1.5));
		mob->turn = 1;
	}
}

void mob_attack(window_t window, hero_t *hero, mob_t *mob, GUI_t *HUD)
{
	static sfClock *clock = NULL;
	static float seconds;

	(void)window;
	(void)hero;
	(void)HUD;
	if (clock == NULL)
		clock = sfClock_create();
	seconds = create_time(clock);
	if (mob->turn == 0)
		sfClock_restart(clock);
	if (mob->turn == 1) {
		if (seconds > 1.5) {
			hero->hp[0] -= mob->stat->atk_p;
			if (hero->hp[0] < 0)
				hero->hp[0] = 0;
			mob->turn = 0;
			set_text(window.text, damage_mob(mob->stat->atk_p, hero, mob),
				 set_vector(600, 870), sfBlack);
		}
	}
}
