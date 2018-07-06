/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** C GRAPH PROG
*/

#include "rpg.h"

void utility(window_t window, object_t *object, GUI_t *HUD)
{
	sfRenderWindow_display(window.window);
	sfRenderWindow_clear(window.window, sfBlack);
	poll_event(window, object, HUD);
}

int free_mode(window_t window, object_t *object)
{
	if (window.use == 1) {
		if (object->pause == 1) {
			/* menu(window.window); */
			return (2);
		}
		draw_map(window, object);
		move_control(object->hero, object->map);
		return (1);
	}
	return (0);
}

int fight_mode(window_t window, object_t *object, GUI_t *HUD)
{
	static sfSprite *life = NULL;
	static sfSprite *mana = NULL;
	
	if (window.use == 2) {
		fight_screen(window, object);
		fight_log(window);
		ini_life_bar(window, &life);
		ini_mana_bar(window, &mana);
		bar_manager(window, &life, &mana, object->hero);
		set_mob_life(window, object->mob);
		survol_button(window.window, HUD);
		draw_button_list(window.window, HUD);
		sfRenderWindow_drawText(window.window, window.text, NULL);
		return (1);
	}
	return (0);
}

int menu_mode(window_t window, menu_t *menu)
{
	sfText *text = sfText_create();
	
	if (window.use == 0) {
		sfText_setFont(text, window.font);
		set_text(text, "press right click", set_vector(700, 750), sfBlack);
		sfText_setScale(text, set_vector(2, 2));
		draw_menu(menu, window.window);
		sfRenderWindow_drawText(window.window, text, NULL);
		return (1);
	}
	return (0);
}
