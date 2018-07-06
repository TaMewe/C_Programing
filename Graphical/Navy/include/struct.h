#ifndef __STRUCT_H__
#define __STRUCT_H__

enum hero_type {
	loris,
	léandre,
	robin,
	mateo,
	dylan,
};

typedef struct stat_s {
	int str;
	int def;
	int m_str;
	int m_def;
	int crit;
} stat_t;

typedef struct hero_s {
	int type;

	sfSprite *sprite;
	sfTexture *texture;
	sfVector2f position;
	sfVector2f scale;
	int hp;
	int mp;
	int xp;
	int lvl;
	stat_t *stat;

	struct hero_s *next;
} hero_t;

#endif
