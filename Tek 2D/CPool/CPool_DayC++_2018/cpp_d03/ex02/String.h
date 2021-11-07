/*
** EPITECH PROJECT, 2018
** String.h
** File description:
** String.h
*/

#ifndef STRING_H_
# define STRING_H_

#include <string.h>
#include <stdlib.h>

typedef struct	String
{
	char *str;
	void (*assign_s)(struct String *this, struct String const *str);
	void (*assign_c)(struct String *this, char const *str);
	void (*append_s)(struct String *this, struct String const *ap);
	void (*append_c)(struct String *this, char const *ap);
} String;

void StringInit(String *this, char const *s);
void StringDestroy(String *this);

#endif
