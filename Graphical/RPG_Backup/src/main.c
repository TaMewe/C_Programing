/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "rpg.h"
#include "struct.h"

map_t *ini_map()
{
	map_t *map = malloc(sizeof(map_t));

	map->bg = malloc(sizeof(sfSprite *) * 3);
	for (int i = 0; i != 3; i++)
		map->bg[i] = sfSprite_create();
	map->text = sfTexture_createFromFile("Sprite/Parallax/sky.png", NULL);
	sfSprite_setTexture(map->bg[0], map->text, sfTrue);
	map->text = sfTexture_createFromFile("Sprite/Parallax/clouds_1.png", NULL);
	sfSprite_setTexture(map->bg[1], map->text, sfTrue);
	map->text = sfTexture_createFromFile("Sprite/Parallax/clouds_2.png", NULL);
	sfSprite_setTexture(map->bg[2], map->text, sfTrue);
	map->clock = sfClock_create();
	map->rect.top = 0;
	map->rect.left = 0;
	map->rect.width = 64;
	map->rect.height = 64;
	map->Town = sfMusic_createFromFile("audio/map/Town.ogg");
	if (!map->Town)
		my_puterror("ERROR: failed to load Town music.\n");
	sfMusic_setLoop(map->Town, sfTrue);
	map->play = 0;
	return (map);
}

int main(int ac, char **av, char **envp)
{
	(void)ac;
	(void)av;
	if (envp[0] == NULL)
		return (84);
	if (window_is_open() == 84)
		return (84);
	return (0);
}
