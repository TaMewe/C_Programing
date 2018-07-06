/*
** EPITECH PROJECT, 2018
** window
** File description:
** window
*/

#include "rpg.h"
#include "map.h"

window_t create_window(int width, int height, int bitsPerPixel)
{
	window_t window;

	window.mode.width = width;
	window.mode.height = height;
	window.mode.bitsPerPixel = bitsPerPixel;
	window.window = sfRenderWindow_create(window.mode, "My RPG",
					      sfFullscreen, NULL);
	window.clock = sfClock_create();
	window.text = sfText_create();
	window.font = sfFont_createFromFile("Sprite/Font/font.ttf");
	window.use = 0;
	sfText_setFont(window.text, window.font);
	sfRenderWindow_setFramerateLimit(window.window, 60);
	return (window);
}

void key_pressed(sfEvent event, map_t *map, hero_t *hero)
{
	(void)event;
	(void)map;
	(void)hero;
}

int poll_event(window_t window, object_t *object, GUI_t *HUD)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(window.window, &event)) {
		event_close_window(window.window, event);
		event_key_pressed(window, event, object);
		event_click(window, event, object, HUD);
	}
	return (0);
}

window_t draw_map(window_t window, object_t *object)
{
	first_map_spe(window, object, zone_1);
	second_map_spe(window, object, zone_2);
	third_map_spe(window, object, zone_t);
	for (int i = 0; object->map->map_c[i] != NULL; i++) {
		for (int j = 0; j != object->map->lar; j++)
			sfRenderWindow_drawSprite(
				window.window, object->map->blocks_1d[i][j], NULL);
	}
	draw_sprite(window.window, object->hero->sprite, 1);
	for (int i = 0; object->map->map_c[i] != NULL; i++) {
		for (int j = 0; j != object->map->lar; j++)
			sfRenderWindow_drawSprite(
				window.window, object->map->blocks_2d[i][j], NULL);
	}
	return (window);
}

int window_is_open()
{
	window_t window = create_window(1920, 1080, 32);
	GUI_t *HUD = ini_button_list();
	object_t *object = ini_object();
	sfVector2f vec;

	object->map->map_1d = my_strcpy((char *)zone_1[0]);
	object->map->map_2d = my_strcpy((char *)zone_1[1]);
	object->map->map_coli = my_strcpy((char *)zone_1[2]);
	map_creation(object->map);
	set_character(object->hero, object->map);
	while (sfRenderWindow_isOpen(window.window)) {
		menu_mode(window, object->menu);
		free_mode(window, object);
		swap_1_to_2(object->map, object->hero, zone_1, zone_2);
		swap_2_to_1(object->map, object->hero, zone_1, zone_2);
		swap_1_to_tente(object->map, object->hero, zone_2, zone_t);
//		swap_tente_to_1(object->map, object->hero, zone_1, zone_t);
		fight_mode(window, object, HUD);
		utility(window, object, HUD);
		window = window_use(window, object, HUD);
		vec = sfSprite_getPosition(object->hero->sprite);
		printf("x = %f\ny = %f\n", vec.x, vec.y);
	}
	sprite_destroy_menu(object->menu);
	return (0);
}
