/*
** EPITECH PROJECT, 2018
** my_rpg
** File description:
** C GRAPH PROG
*/

#include "rpg.h"

void draw_sprite(sfRenderWindow *window, sfSprite *sprite, int use)
{
	if (use == 1)
		sfRenderWindow_drawSprite(window, sprite, NULL);
}

sfVector2f set_vector(float x, float y)
{
	sfVector2f vector = { x, y };

	return (vector);
}

sfIntRect set_rect(int left, int top, int width, int height)
{
	sfIntRect rect = { left, top, width, height };

	return (rect);
}

float create_time(sfClock *clock)
{
	sfTime time;
	float seconds;

	time = sfClock_getElapsedTime(clock);
	seconds = time.microseconds / 1000000.0;
	return (seconds);
}

window_t window_use(window_t window, object_t *object, GUI_t *HUD)
{
	if (window.use == 0) {
		if (sfMouse_isButtonPressed(sfMouseRight) == sfTrue) {
			sfMusic_stop(object->menu->music.sonic);
			window.use = 1;
		}
	}
	if (window.use == 1) {
		if (sfKeyboard_isKeyPressed(sfKeyC) == sfTrue && object->hero->hp[0] != 0) {
			window.use = 2;
			sfText_setString(window.text, NULL);
			object->mob->turn = 0;
			stop_map_music(object);
			sfMusic_play(object->mob->fight_theme);
		}
		if (sfKeyboard_isKeyPressed(sfKeyI) == sfTrue)
			window.use = 3;
		if (object->hero->xp[0] >= object->hero->xp[1]) {
			my_puterror("LEVEL UP!\n");
			object->hero->stat->atk_p += 5;
			object->hero->xp[0] = 0;
			object->hero->xp[1] += object->hero->xp[1];
		}
	}
	if (window.use == 2) {
		if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
			if (check_button(window.window, HUD, button_flee) == 1
			    && object->mob->hp[0] != 0 && object->mob->turn == 0)
				window = function_flee(window);
			else if (window.pause == 1) {
				window.pause = 0;
				window.use = 1;
				sfText_setString(window.text, NULL);
				object->mob->hp[0] = object->mob->hp[1];
				sfMusic_stop(object->mob->fight_theme);
			}
		}
		if (object->mob->hp[0] == 0
		    && sfMouse_isButtonPressed(sfMouseRight) == sfTrue) {
			sfText_setString(window.text, NULL);
			object->mob->hp[0] = object->mob->hp[1];
			window.use = 1;
			sfMusic_stop(object->mob->fight_theme);
			object->hero->xp[0] += object->mob->xp;
		}
		if (object->mob->hp[0] != 0)
			mob_attack(window, object->hero, object->mob, HUD);
		if (object->hero->hp[0] == 0) {
                        window.use = 1;
			sfMusic_stop(object->mob->fight_theme);
		}
	}
	if (window.use == 3) {
		if (sfKeyboard_isKeyPressed(sfKeyP) == sfTrue)
			window.use = 1;
		wood_background_moving(window.window, object->inv);
		draw_inv(window.window, object->inv);
		apply_sca(window.window, object->inv);
	}
	return (window);
}
