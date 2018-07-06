/*
** EPITECH PROJECT, 2018
** fill_sprite
** File description:
** fill_sprite
*/

#include "../include/my.h"
#include "../include/struct.h"

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
	if (text[axe[0]][axe[1]] == NULL) {
		printf("OUT OF MEMORY SRSLY?!?!?");
		exit (0);
	}
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

void fill_sprite(sfSprite ***map_item, char **map, int *axe, sfTexture ***text)
{
	switch (map[axe[0]][axe[1]]) {
	case '0':
		choose_text("Sprite/PNG/0.png", map_item, axe, text);
		break;
	case '1':
		choose_text("Sprite/PNG/1.png", map_item, axe, text);
		break;
	case '2':
		choose_text("Sprite/PNG/2.png", map_item, axe, text);
		break;
	case '3':
		choose_text("Sprite/PNG/3.png", map_item, axe, text);
		break;
	case 'o':
		choose_text("Sprite/PNG/o.png", map_item, axe, text);
		break;
	case 'A':
		choose_text("Sprite/PNG/A.png", map_item, axe, text);
		break;
	case 'B':
		choose_text("Sprite/PNG/B.png", map_item, axe, text);
		break;
	case 'C':
		choose_text("Sprite/PNG/C.png", map_item, axe, text);
		break;
	case 'D':
		choose_text("Sprite/PNG/D.png", map_item, axe, text);
		break;
	case 'E':
		choose_text("Sprite/PNG/E.png", map_item, axe, text);
		break;
	case 'F':
		choose_text("Sprite/PNG/F.png", map_item, axe, text);
		break;
	case 'G':
		choose_text("Sprite/PNG/G.png", map_item, axe, text);
		break;
	case 'H':
		choose_text("Sprite/PNG/H.png", map_item, axe, text);
		break;
	case 'd':
		choose_text("Sprite/PNG/d.png", map_item, axe, text);
		break;
	case 'e':
		choose_text("Sprite/PNG/e.png", map_item, axe, text);
		break;
	case 'f':
		choose_text("Sprite/PNG/f.png", map_item, axe, text);
		break;
	case 'g':
		choose_text("Sprite/PNG/g.png", map_item, axe, text);
		break;
	case 'h':
		choose_text("Sprite/PNG/h.png", map_item, axe, text);
		break;
	case 'i':
		choose_text("Sprite/PNG/i.png", map_item, axe, text);
		break;
	case 'p':
		choose_text("Sprite/PNG/p.png", map_item, axe, text);
		break;
	case 'q':
		choose_text("Sprite/PNG/q.png", map_item, axe, text);
		break;
	case 'r':
		choose_text("Sprite/PNG/r.png", map_item, axe, text);
		break;
	case 's':
		choose_text("Sprite/PNG/s.png", map_item, axe, text);
		break;
	case '-':
		choose_text("Sprite/PNG/Blank.png", map_item, axe, text);
		break;
	default:
		break;
	}
}

void fill_sprite_2(sfSprite ***map_item, char **map, int *axe, sfTexture ***text)
{
	switch (map[axe[0]][axe[1]]) {
	case '8':
		choose_text("Sprite/PNG/8.png", map_item, axe, text);
		break;
	case '9':
		choose_text("Sprite/PNG/9.png", map_item, axe, text);
		break;
	case '7':
		choose_text("Sprite/PNG/7.png", map_item, axe, text);
		break;
	case 'I':
		choose_text("Sprite/PNG/I.png", map_item, axe, text);
		break;
	case 'J':
		choose_text("Sprite/PNG/J.png", map_item, axe, text);
		break;
	case 'K':
		choose_text("Sprite/PNG/K.png", map_item, axe, text);
		break;
	case 'L':
		choose_text("Sprite/PNG/L.png", map_item, axe, text);
		break;
	case 'M':
		choose_text("Sprite/PNG/M.png", map_item, axe, text);
		break;
	case 'N':
		choose_text("Sprite/PNG/N.png", map_item, axe, text);
		break;
	case 'O':
		choose_text("Sprite/PNG/O.png", map_item, axe, text);
		break;
	case 'P':
		choose_text("Sprite/PNG/P.png", map_item, axe, text);
		break;
	case 'Q':
		choose_text("Sprite/PNG/Q.png", map_item, axe, text);
		break;
	case 'R':
		choose_text("Sprite/PNG/R.png", map_item, axe, text);
		break;
	case 'S':
		choose_text("Sprite/PNG/S.png", map_item, axe, text);
		break;
	case 'T':
		choose_text("Sprite/PNG/T.png", map_item, axe, text);
		break;
	case 'U':
		choose_text("Sprite/PNG/U.png", map_item, axe, text);
		break;
	case 'V':
		choose_text("Sprite/PNG/V.png", map_item, axe, text);
		break;
	case 'W':
		choose_text("Sprite/PNG/W.png", map_item, axe, text);
		break;
	case 'X':
		choose_text("Sprite/PNG/X.png", map_item, axe, text);
		break;
	case 'Y':
		choose_text("Sprite/PNG/Y.png", map_item, axe, text);
		break;
	case 'Z':
		choose_text("Sprite/PNG/Z.png", map_item, axe, text);
		break;
	case 'a':
		choose_text("Sprite/PNG/a.png", map_item, axe, text);
		break;
	case 'b':
		choose_text("Sprite/PNG/b.png", map_item, axe, text);
		break;
	case 'c':
		choose_text("Sprite/PNG/c.png", map_item, axe, text);
		break;
	case 'd':
		choose_text("Sprite/PNG/d.png", map_item, axe, text);
		break;
	case 'e':
		choose_text("Sprite/PNG/e.png", map_item, axe, text);
		break;
	case 'f':
		choose_text("Sprite/PNG/f.png", map_item, axe, text);
		break;
	case 'g':
		choose_text("Sprite/PNG/g.png", map_item, axe, text);
		break;
	case 'h':
		choose_text("Sprite/PNG/h.png", map_item, axe, text);
		break;
	case 'i':
		choose_text("Sprite/PNG/i.png", map_item, axe, text);
		break;
	case 'j':
		choose_text("Sprite/PNG/j.png", map_item, axe, text);
		break;
	case 'k':
		choose_text("Sprite/PNG/k.png", map_item, axe, text);
		break;
	case 'l':
		choose_text("Sprite/PNG/l.png", map_item, axe, text);
		break;
	case 'm':
		choose_text("Sprite/PNG/m.png", map_item, axe, text);
		break;
	case 'n':
		choose_text("Sprite/PNG/n.png", map_item, axe, text);
		break;
	case 't':
		choose_text("Sprite/PNG/t.png", map_item, axe, text);
		break;
	case 'u':
		choose_text("Sprite/PNG/u.png", map_item, axe, text);
		break;
	case '0':
		choose_text("Sprite/PNG/Blank.png", map_item, axe, text);
		break;
	default:
		break;
	}
}
