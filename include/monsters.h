#ifndef _MONSTERS_H_
#define _MONSTERS_H_

#define MONSTER_TAB_SIZE (sizeof monster_tab / sizeof (Monster) )

typedef struct {
	char *name;
	int hp;
	int str;
} Monster;

extern Monster monster_tab[];

#endif
