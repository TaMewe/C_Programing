/*
** EPITECH PROJECT, 2018
** fill_sprite
** File description:
** fill_sprite
*/

#include "rpg.h"
#include "struct.h"

void destroy_map(char **destroy1, char **destroy2)
{
	for (int i = 0; destroy1[i] != NULL; i++)
		free(destroy1[i]);
	for (int i = 0; destroy2[i] != NULL; i++)
		free(destroy2[i]);
	return ;
}

void choose_text(char *filepath, sfSprite ***map_item, int *axe, sfTexture ***text)
{
	sfVector2f vec;

	text[axe[0]][axe[1]] = sfTexture_createFromFile(filepath, NULL);
	sfSprite_setTexture(map_item[axe[0]][axe[1]], text[axe[0]][axe[1]], sfTrue);
	vec.x = axe[1] * 64;
	vec.y = axe[0] * 64;
	sfSprite_setPosition(map_item[axe[0]][axe[1]], vec);
}

void text_fire(map_t *map)
{
	for (int i = 0; map->map_c[i] != NULL; i++) {
		for (int j = 0; j != map->lar; j++) {
			if (map->map_d[i][j] == 'u') {
				sfSprite_setTextureRect(map->blocks_2d[i][j], map->rect);
			}
		}
	}
}

const char *filepaths_1[100] =
{
	"Sprite/PNG/0.png",
	"Sprite/PNG/1.png",
	"Sprite/PNG/2.png",
	"Sprite/PNG/3.png",
	"Sprite/PNG/6.png",
	"Sprite/PNG/o.png",
	"Sprite/PNG/A.png",
	"Sprite/PNG/B.png",
	"Sprite/PNG/C.png",
	"Sprite/PNG/D.png",
	"Sprite/PNG/E.png",
	"Sprite/PNG/F.png",
	"Sprite/PNG/G.png",
	"Sprite/PNG/H.png",
	"Sprite/PNG/p.png",
	"Sprite/PNG/q.png",
	"Sprite/PNG/r.png",
	"Sprite/PNG/s.png",
	"Sprite/PNG/v.png",
	"Sprite/PNG/w.png",
	"Sprite/PNG/y.png",
	"Sprite/PNG/z.png",
	"Sprite/PNG/i.png",
	"Sprite/PNG/j.png",
	"Sprite/PNG/b.png",
	"Sprite/PNG/Blank.png",
	NULL
};

const char opts_1[100] =
{
	'0',
	'1','2','3','6','o','A','B','C','D','E','F','G','H','p',
	'q','r','s','v','w','y','z','i','j','b','-',
	'\0'
};

void fill_sprite(sfSprite ***map_item, char **map, int *axe, sfTexture ***text)
{
	for (int i = 0; opts_1[i]; i += 1) {
		if (opts_1[i] == map[axe[0]][axe[1]])
			choose_text((char *)filepaths_1[i], map_item, axe, text);
	}
}

const char *filepaths_2[100] =
{
	"Sprite/PNG/4.png",
	"Sprite/PNG/5.png",
	"Sprite/PNG/8.png",
	"Sprite/PNG/9.png",
	"Sprite/PNG/7.png",
	"Sprite/PNG/I.png",
	"Sprite/PNG/J.png",
	"Sprite/PNG/K.png",
	"Sprite/PNG/L.png",
	"Sprite/PNG/M.png",
	"Sprite/PNG/N.png",
	"Sprite/PNG/O.png",
	"Sprite/PNG/P.png",
	"Sprite/PNG/Q.png",
	"Sprite/PNG/R.png",
	"Sprite/PNG/S.png",
	"Sprite/PNG/T.png",
	"Sprite/PNG/U.png",
	"Sprite/PNG/V.png",
	"Sprite/PNG/W.png",
	"Sprite/PNG/X.png",
	"Sprite/PNG/Y.png",
	"Sprite/PNG/Z.png",
	"Sprite/PNG/a.png",
	"Sprite/PNG/c.png",
	"Sprite/PNG/d.png",
	"Sprite/PNG/e.png",
	"Sprite/PNG/f.png",
	"Sprite/PNG/g.png",
	"Sprite/PNG/h.png",
	"Sprite/PNG/k.png",
	"Sprite/PNG/l.png",
	"Sprite/PNG/m.png",
	"Sprite/PNG/n.png",
	"Sprite/PNG/t.png",
	"Sprite/PNG/u.png",
	"Sprite/PNG/x.png",
	"Sprite/PNG/d.png",
	"Sprite/PNG/Blank.png",
	NULL
};

const char opts_2[100] =
{
	'4','5','8',
	'9','7','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y',
	'Z','a','c','d','e','f','g','h','k','l','m','n','t','u','x','d','0',
	'\0'
};

void fill_sprite_2(sfSprite ***map_item, char **map, int *axe, sfTexture ***text)
{
	for (int i = 0; opts_2[i]; i += 1) {
		if (opts_2[i] == map[axe[0]][axe[1]])
			choose_text((char *)filepaths_2[i], map_item, axe, text);
	}
}
