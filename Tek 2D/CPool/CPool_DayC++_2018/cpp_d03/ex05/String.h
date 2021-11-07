#ifndef STRING_H_
# define STRING_H_

#include <stdlib.h>
#include <string.h>

typedef struct	String
{
	char *str;
	void (*assign_s)(struct String *this, struct String const *str);
	void (*assign_c)(struct String *this, char const *str);
	void (*append_s)(struct String *this, struct String const *ap);
	void (*append_c)(struct String *this, char const *ap);
	char (*at)(struct String *this, size_t pos);
	void (*clear)(struct String *this);
	int (*size)(struct String *this);
} String;

void StringInit(String *this, char const *s);
void StringDestroy(String *this);

#endif
