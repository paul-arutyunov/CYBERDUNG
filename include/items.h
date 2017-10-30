#ifndef _ITEMS_H_
#define _ITEMS_H_

#define ITEM_TAB_SIZE (sizeof item_tab / sizoef (Item) )

typedef struct {
	char *name;
	char *type;
	int grade;
} Item;

extern Item item_tab[];

#endif
