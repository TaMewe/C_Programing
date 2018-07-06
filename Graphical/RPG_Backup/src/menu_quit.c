/*
** EPITECH PROJECT, 2018
** Quit menu
** File description:
** Menu yes or no for quit game
*/

#include "rpg.h"

GUI_t *sprite_on_buttons(char *path1, sfVector2f pos)
{
	GUI_t   *exit = malloc(sizeof(GUI_t));
	sfVector2f      origin;

	exit->type = button_type;
	exit->sprite = sfSprite_create();
	exit->texture = sfTexture_createFromFile(path1, NULL);
	exit->rect = set_rect(0, 0, 411, 115);
	exit->position = pos;
	origin = set_vector(exit->rect.width / 2, exit->rect.height / 2);
	exit->scale = set_vector(1, 1);
	sfSprite_setTexture(exit->sprite, exit->texture, sfTrue);
	sfSprite_setTextureRect(exit->sprite, exit->rect);
	sfSprite_setPosition(exit->sprite, exit->position);
	sfSprite_setScale(exit->sprite, exit->scale);
	sfSprite_setOrigin(exit->sprite, origin);
	exit->next = NULL;
	return (exit); 
}

int scale_buttons(sfRenderWindow *window, GUI_t *button)
{
	sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
	sfIntRect area;
	
	while (button != NULL) {
		if (button->type == button_type) {
			area = set_area(button);
			if (sfIntRect_contains(&area, mouse.x, mouse.y) == sfTrue)
				sfSprite_setTexture(button->sprite, button->survol, sfTrue);
			else
				sfSprite_setTexture(button->sprite, button->texture, sfTrue);
		}
		button = button->next;
	}
	return (0);
}

GUI_t *ini_button_lists()
{
	GUI_t *HUD = ini_fight_HUD();
	GUI_t *add = HUD;
	sfVector2f pos = { 800, 200 };

	add->next = sprite_on_buttons("Sprite/menu_quit_img/resume.png", pos);
	add->next->button = button_resume;
	add = add->next;
	pos = set_vector(800, 400);
	add->next = sprite_on_buttons("Sprite/menu_quit_img/Sa.png", pos);
	add->next->button = button_save;
	pos = set_vector(800, 600);
	add = add->next;
	add->next = sprite_on_buttons("Sprite/menu_quit_img/Settings.png", pos);
	add->next->button = button_settings;
	pos = set_vector(800, 800);
	add = add->next;
	add->next = sprite_on_buttons("Sprite/menu_quit_img/Quit.png", pos);
	add->next->button = button_quit;
	return (HUD);
}


/* int exit_is_clicked(exit_t *button, sfVector2i clickPosition) */
/* { */
/* 	return (clickPosition.x < sfRectangleShape_getPosition(button->huge).x + */
/* 		sfRectangleShape_getSize(button->huge).x && */
/* 		clickPosition.x > sfRectangleShape_getPosition(button->huge).x && */
/* 		clickPosition.y < sfRectangleShape_getPosition(button->huge).y + */
/* 		sfRectangleShape_getSize(button->huge).y && */
/* 		clickPosition.y > sfRectangleShape_getPosition(button->huge).y); */
/* } */

/* void exit_init(exit_t *button, sfVector2f pos, sfVector2f size) */
/* { */
/* 	button->huge = sfRectangleShape_create(); */
/* 	sfRectangleShape_setPosition(button->huge, pos); */
/* 	sfRectangleShape_setSize(button->huge, size); */
/* 	sfRectangleShape_setFillColor(button->huge, (sfColor) {255, 0, 0, 255}); */
/* } */

/* int menu(sfRenderWindow *window) */
/* { */
/* 	sfEvent	click; */
/* 	exit_t	*button_quit = malloc(sizeof(exit_t)); */
/* 	exit_t	*button_save = malloc(sizeof(exit_t)); */
/* 	exit_t	*button_settings = malloc(sizeof(exit_t)); */
/* 	exit_t	*button_resume = malloc(sizeof(exit_t)); */
/* 	sfVector2i mouse; */
	
/* 	exit_init(button_quit, (sfVector2f) {800, 800}, (sfVector2f) {400, 100}); */
/* 	exit_init(button_save, (sfVector2f) {800, 600}, (sfVector2f) {400, 100}); */
/* 	exit_init(button_settings, (sfVector2f) {800, 400}, (sfVector2f) {400, 100}); */
/* 	exit_init(button_resume, (sfVector2f) {800, 200}, (sfVector2f) {400, 100}); */
/* 	sfRenderWindow_drawRectangleShape(window, button_quit->huge, NULL); */
/* 	sfRenderWindow_drawRectangleShape(window, button_save->huge, NULL); */
/* 	sfRenderWindow_drawRectangleShape(window, button_settings->huge, NULL); */
/* 	sfRenderWindow_drawRectangleShape(window, button_resume->huge, NULL); */
/* 	if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) { */
/* 		mouse = sfMouse_getPositionRenderWindow(window); */
/* 		if (exit_is_clicked(button_quit, mouse) && sfMouse_isButtonPressed(sfMouseLeft)) { */
/* 			write(1, "The game stopped\n", 17); */
/* 			sfRenderWindow_close(window); */
/* 		} */
/* 		if (exit_is_clicked(button_save, mouse) && sfMouse_isButtonPressed(sfMouseLeft)) */
/* 			write(1, "Saving\n", 7); */
/* 		// appel à la fonction pour sauvegarder| */
/* 		if (exit_is_clicked(button_settings, mouse) && sfMouse_isButtonPressed(sfMouseLeft)) */
/* 			write(1, "Settings\n", 9); */
/* 		if (exit_is_clicked(button_resume, mouse) && sfMouse_isButtonPressed(sfMouseLeft)) */
/* 			write(1, "The game continue\n", 18); */
/* 	} */
/* 	return (0); */
/* } */
